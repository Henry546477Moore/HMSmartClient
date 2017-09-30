#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPlainTextEdit>

namespace Ui {
class MainWidget;
}

class HMPluginInterface;
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
    /*!
     * \brief MainWidget::on_btnSend_clicked
     * send message to plugin
     * \author lsq
     * \date 2017-09-29 10:33
     */
    void on_btnSend_clicked();
    /*!
     * \brief receivePluginMsg
     * receive plugin message
     * \param msg message info
     * \author lsq
     * \date 2017-09-30 10:31
     */
    void receivePluginMsg(const QString &msg);

public:
    QPlainTextEdit* LogEdit;

private:
    Ui::MainWidget *ui;
    HMPluginInterface *pluginInterface;        //save plugin point
};

#endif // MAINWIDGET_H
