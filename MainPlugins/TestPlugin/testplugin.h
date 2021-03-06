#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include "testplugin_global.h"
#include <QObject>
#include "hmplugininterface.h"
#include "testwidget.h"

/*!
 * \brief The TestPlugin class test plugin indoor
 * \author lsq
 * \date 2017-09-28 23:25
 */
class TESTPLUGINSHARED_EXPORT TestPlugin : public QObject, HMPluginInterface
{
Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.lsquange/1.0" FILE "testplugin.json")
    Q_INTERFACES(HMPluginInterface)
public:
    TestPlugin();
    /*!
     * \brief SayToPlugin main module comunication to plugin
     * \param msg comunication message into
     * \author lsq
     * \date 2017-09-28 22:58
     */
    void SayToPlugin(const QString &msg);
    /*!
     * \brief GetPluginWidget ask plugin create a widget instance
     * \param parent widget instance parent
     * \return  widget
     * \author lsq
     * \date 2017-09-28 22:59
     */
    HMPluginWidgetBase* GetPluginWidget(QWidget *parent);

private:
    TestWidget* testwidget;            //plugin widget
};

#endif // TESTPLUGIN_H
