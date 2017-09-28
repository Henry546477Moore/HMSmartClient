#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDir>
#include <QDebug>
#include <QPluginLoader>

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
    //load plugin
    if(this->pluginInterface == nullptr)
    {
        QDir pluginDir("./plugins");
        foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
            qDebug() << fileName;
            qDebug() << pluginDir.absoluteFilePath(fileName);
            QPluginLoader pluginLoader(pluginDir.absoluteFilePath(fileName));
            QObject *plugin = nullptr;
            plugin = pluginLoader.instance();
            if(plugin != nullptr){
                qDebug() << "get successful instance of plugin";
                this->pluginInterface = qobject_cast<HMSmartPluginInterface*>(plugin);
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
                    lst.append(json.value("dependencies").toVariant().toString());
                    lst.append(json.value("keys").toVariant().toString());
                    qDebug() << lst;
                    this->ui->txtPluginInfo->setText(lst.join(","));

                    QWidget* pluginWidget = this->pluginInterface->GetPluginWidget(this);
                    if(pluginWidget != nullptr){
                        this->ui->gridPluginPnl->addWidget(pluginWidget);
                    }
                    return;
                }
            }
            qDebug() << "not find the plugin";
        }
    }
    //unload plugin
    else{
        qDebug() << "not implements function";
    }
}
