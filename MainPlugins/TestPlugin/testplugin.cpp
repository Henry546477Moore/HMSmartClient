#include "testplugin.h"
#include <QDebug>

TestPlugin::TestPlugin()
{
    this->testwidget = nullptr;
}

/*!
 * \brief SayToPlugin main module comunication to plugin
 * \param msg comunication message into
 * \author lsq
 * \date 2017-09-28 22:58
 */
void TestPlugin::SayToPlugin(const QString &msg)
{
    if(this->testwidget == nullptr)
    {
        qDebug() << "Please load the plugin";
        return;
    }
    this->testwidget->SayToWidget(msg);
}

/*!
 * \brief GetPluginWidget ask plugin create a widget instance
 * \param parent widget instance parent
 * \return  widget
 * \author lsq
 * \date 2017-09-28 22:59
 */
HMPluginWidgetBase* TestPlugin::GetPluginWidget(QWidget *parent)
{
    if(this->testwidget == nullptr)
    {
        this->testwidget = new TestWidget(parent);
    }
    return this->testwidget;
}
