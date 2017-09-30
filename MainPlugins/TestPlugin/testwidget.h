#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include "hmpluginwidgetbase.h"

namespace Ui {
class TestWidget;
}

/*!
 * \brief The TestWidget class test plugin's widget
 * \author lsq
 * \date 2017-09-28 23:31
 */
class TestWidget : public HMPluginWidgetBase
{
    Q_OBJECT

public:
    explicit TestWidget(QWidget *parent = 0);
    ~TestWidget();

    /*!
     * \brief SayToWidget main module comunication to plugin widget msg
     * \param msg message into
     * \author lsq
     * \date 2017-09-28 23:32
     */
    void SayToWidget(const QString &msg);

private slots:
    void on_btnSend_clicked();

private:
    Ui::TestWidget *ui;
};

#endif // TESTWIDGET_H
