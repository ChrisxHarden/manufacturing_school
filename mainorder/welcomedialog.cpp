/*吕志伟*/
#include "welcomedialog.h"
#include "ui_welcomedialog.h"
#include <QMovie>
#include "logindialog.h"

WelcomeDialog::WelcomeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeDialog)
{
    ui->setupUi(this);
    setFixedSize(549,404);
    QMovie *m = new QMovie("./pic/8.gif");
    ui->label->setMovie(m);
    m->start();
}

WelcomeDialog::~WelcomeDialog()
{
    delete ui;
}

void WelcomeDialog::on_pushButton_clicked()
{
    LoginDialog *w = new LoginDialog();
    w->show();
    this->close();

}
