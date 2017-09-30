#ifndef HMPLUGINWIDGETBASE_H
#define HMPLUGINWIDGETBASE_H

#include <QWidget>
#include "hmpluginwidgetbase_global.h"

class HMPLUGINWIDGETBASE_EXPORT HMPluginWidgetBase: public QWidget
{
    Q_OBJECT

public:
    HMPluginWidgetBase(QWidget *parent = 0);
    ~HMPluginWidgetBase();

signals:
    void SayToApplication(const QString &msg);

};

#endif // HMPLUGINWIDGETBASE_H
