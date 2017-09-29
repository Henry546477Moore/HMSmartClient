#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDir>
#include <QDebug>
#include <QPluginLoader>
#include "./../SharePluginLibrary/hmplugininterface.h"
#include "./../SharePluginLibrary/hmpluginwidgetbase.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->pluginInterface = nullptr;
}

MainWidget::~MainWidget()
{
    delete ui;
}

/*!
 * \brief on_btnLoadPlugin_clicked load or unload plugin
 * \author lsq
 * \date 2017-09-28 23:06
 */
void MainWidget::on_btnLoadPlugin_clicked()
{
    //1)load plugin
    if(this->pluginInterface)
    {        
        qDebug() << "not implements unload function";
        return;
    }

    //2)load plugin
    QDir pluginDir(QString("%1/MainPlugins").arg(QCoreApplication::applicationDirPath()));
    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        qDebug() << fileName;
        QPluginLoader pluginLoader(pluginDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if(plugin){
            qDebug() << "get successful instance of plugin";
            this->pluginInterface = qobject_cast<HMPluginInterface*>(plugin);
            if(this->pluginInterface != nullptr){
                qDebug() << "find the plugin";
                this->ui->btnLoadPlugin->setText(tr("unload"));;

                QJsonObject json = pluginLoader.metaData().value("MetaData").toObject();
                qDebug() << "########## MetaData ##########";
                QStringList lst;
                lst.append(json.value("author").toVariant().toString());
                lst.append(json.value("date").toVariant().toString());
                lst.append(json.value("name").toVariant().toString());
                lst.append(json.value("version").toVariant().toString());
                lst.append(json.value("dependences").toVariant().toString());
                lst.append(json.value("keys").toVariant().toString());
                qDebug() << lst;
                this->ui->txtPluginInfo->setText(lst.join(","));

                QWidget* pluginWidget = this->pluginInterface->GetPluginWidget(this);
                if(pluginWidget){
                    this->ui->gridPluginPnl->addWidget(pluginWidget);
                }
                return;
            }
        }
        qDebug() << "not find the plugin";
    }
}

/*!
 * \brief MainWidget::on_btnSend_clicked
 * send message to plugin
 * \author lsq
 * \date 2017-09-29 10:33
 */
void MainWidget::on_btnSend_clicked()
{
    if(!this->pluginInterface)
    {
        qDebug() << "Please load plugin";
        return;
    }
    this->pluginInterface->SayToPlugin(this->ui->txtSendToPlugin->text());
}
