#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "hmsmartplugininterface.h"

namespace Ui {
class MainWidget;
}

/*!
 * \brief The MainWidget class main module widget
 * \author lsq
 * \date 2017-09-28 23:05
 */
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:
    /*!
     * \brief on_btnLoadPlugin_clicked load or unload plugin
     * \author lsq
     * \date 2017-09-28 23:06
     */
    void on_btnLoadPlugin_clicked();

private:
    Ui::MainWidget *ui;
    HMSmartPluginInterface *pluginInterface;        //save plugin point
};

#endif // MAINWIDGET_H
