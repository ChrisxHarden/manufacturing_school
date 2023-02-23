/*第九组董浩然*/

#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "commom.h"
#include <QMessageBox>
RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    setFixedSize(549,404);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::AddUserResultShow(bool is)
{
    disconnect(&client,SIGNAL(GotAddUserResult(bool)),this,SLOT(AddUserResultShow(bool)));
    client.Close();

    if(is)
    {
        QMessageBox::information(NULL,"注册结果","注册成功！",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(NULL,"注册结果","注册失败！",QMessageBox::Ok);
    }


    this->close();

}

void RegisterDialog::on_bt_confirm_clicked()
{
    QString phone = ui->le_phone->text();
    QString name = ui->le_name->text();

    char str[BUFFERSIZE_MAX]	= { 0 };
    sprintf(str,"{\"cmd\":\"_cmd_add_user\", \"cmd_type\":23, \"phone\":\"%s\", \"name\":\"%s\"}",
            phone.toLatin1().data(),name.toLatin1().data());
    qDebug()<<"cmd is "<<str;

    connect(&client,SIGNAL(GotAddUserResult(bool)),this,SLOT(AddUserResultShow(bool)));
    client.ConnectToServer( SERVER_IP, SERVER_PORT );
    client.waitForConnected( -1 );
    if( !client.WriteData(str, strlen(str) + 1) ) {
        qDebug()<< "WriteData failed !\n" ;
        return;
    }

}

void RegisterDialog::on_bt_abort_clicked()
{

    this->close();
}
