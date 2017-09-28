#ifndef HMSMARTPLUGININTERFACE_H
#define HMSMARTPLUGININTERFACE_H

#include <QString>
#include <QWidget>

#define HMSmartPluginInterface_iid "com.lsquange/1.0"

/*!
 * \brief The HMSmartPluginInterface class
 * HMSmartClient plugin interface
 * \author lsq
 * \date 2017-09-28 22:57
 */
class HMSmartPluginInterface
{
public:
    virtual ~HMSmartPluginInterface(){}
    /*!
     * \brief SayToPlugin main module comunication to plugin
     * \param msg comunication message into
     * \author lsq
     * \date 2017-09-28 22:58
     */
    virtual void SayToPlugin(const QString &msg) = 0;
    /*!
     * \brief GetPluginWidget ask plugin create a widget instance
     * \param parent widget instance parent
     * \return  widget
     * \author lsq
     * \date 2017-09-28 22:59
     */
    virtual QWidget* GetPluginWidget(QWidget *parent = 0) = 0;
};
Q_DECLARE_INTERFACE(HMSmartPluginInterface, HMSmartPluginInterface_iid)

#endif // HMSMARTPLUGININTERFACE_H
