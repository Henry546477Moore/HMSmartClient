#ifndef HMPLUGININTERFACE_H
#define HMPLUGININTERFACE_H

#include <QString>

#define HMPluginInterface_iid "com.lsquange/1.0"

class QWidget;
class HMPluginWidgetBase;
/*!
 * \brief The HMSmartPluginInterface class
 * HMSmartClient plugin interface
 * \author lsq
 * \date 2017-09-28 22:57
 */
class HMPluginInterface
{
public:
    virtual ~HMPluginInterface(){}
    /*!
     * \brief SayToPlugin main module comunication to plugin
     * \param msg comunication message into
     * \author lsq
     * \date 2017-09-28 22:58
     */
    virtual void SayToPlugin(const QString &msg) = 0;
    /*!
     * \brief GetPluginWidget: plugin main widget
     * \param parent widget instance parent
     * \return  widget
     * \author lsq
     * \date 2017-09-28 22:59
     */
    virtual HMPluginWidgetBase* GetPluginWidget(QWidget *parent = 0) = 0;
};
Q_DECLARE_INTERFACE(HMPluginInterface, HMPluginInterface_iid)

#endif // HMPLUGININTERFACE_H
