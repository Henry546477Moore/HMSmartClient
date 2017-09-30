#include "testwidget.h"
#include "ui_testwidget.h"

TestWidget::TestWidget(QWidget *parent) :
    HMPluginWidgetBase(parent),
    ui(new Ui::TestWidget)
{
    ui->setupUi(this);
}

TestWidget::~TestWidget()
{
    delete ui;
}

/*!
 * \brief SayToWidget main module comunication to plugin widget msg
 * \param msg message into
 * \author lsq
 * \date 2017-09-28 23:32
 */
void TestWidget::SayToWidget(const QString &msg)
{
    this->ui->txtFromMain->append(QString("%1\n").arg(msg));
}

void TestWidget::on_btnSend_clicked()
{
    emit SayToApplication(this->ui->txtSendToMainMdoule->text());
}
