/*第九组董浩然*/

#include "logindialog.h"
#include "ui_logindialog.h"
#include "mainorderdialog.h"
#include "manadialog.h"
#include "registerdialog.h"
#include "commom.h"
#include <QDebug>
#include <QMessageBox>
#include "chat_client.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(549,404);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_bt_user_login_clicked()
{
    MainOrderDialog *main = new MainOrderDialog();
    //main->SetUserState(1,"");
    main->show();
    this->close();
}
void LoginDialog::on_bt_register_clicked()
{
    RegisterDialog *reg = new RegisterDialog();
    reg->setModal(true);
    reg->show();

}

void LoginDialog::on_bt_mana_login_clicked()
{
   ui->bt_mana_login->setEnabled(false);
   QString phone = ui->lineEdit_2->text();
   char str[BUFFERSIZE_MAX]	= { 0 };
   sprintf(str,"{\"cmd\":\"_cmd_idenfity_user\", \"cmd_type\":23, \"phone\":\"%s\",\"type\":\"%s\"}",phone.toLatin1().data(),"2");
   qDebug()<<"cmd is "<<str;

   connect(&client,SIGNAL(GotIdentifyUserResult(bool)),this,SLOT(IdentifyManaResultShow(bool)));
   client.ConnectToServer( SERVER_IP, SERVER_PORT );
   client.waitForConnected( -1 );
   if( !client.WriteData(str, strlen(str) + 1) ) {
       qDebug()<< "WriteData failed !\n" ;
       return;
   }
}


void LoginDialog::on_bt_vip_login_clicked()
{
    ui->bt_vip_login->setEnabled(false);
    QString phone = ui->lineEdit->text();
    char str[BUFFERSIZE_MAX]	= { 0 };
    sprintf(str,"{\"cmd\":\"_cmd_idenfity_user\", \"cmd_type\":23, \"phone\":\"%s\",\"type\":\"%s\"}",phone.toLatin1().data(),"1");
    qDebug()<<"cmd is "<<str;

    connect(&client,SIGNAL(GotIdentifyUserResult(bool)),this,SLOT(IdentifyUserResultShow(bool)));
    client.ConnectToServer( SERVER_IP, SERVER_PORT );
    client.waitForConnected( -1 );
    if( !client.WriteData(str, strlen(str) + 1) ) {
        qDebug()<< "WriteData failed !\n" ;
        return;
    }

}

void LoginDialog::IdentifyUserResultShow(bool is)
{
    ui->bt_vip_login->setEnabled(true);
    disconnect(&client,SIGNAL(GotIdentifyUserResult(bool)),this,SLOT(IdentifyUserResultShow(bool)));
    client.Close();

    if(is)
    {
        MainOrderDialog *main = new MainOrderDialog();
        main->SetUserState(2,ui->lineEdit->text());
        main->show();
        this->close();
    }
    else
    {
        QMessageBox::information(NULL,"登陆提示","登陆失败",QMessageBox::Ok);
    }



}

void LoginDialog::IdentifyManaResultShow(bool is)
{
    ui->bt_mana_login->setEnabled(true);
    disconnect(&client,SIGNAL(GotIdentifyUserResult(bool)),this,SLOT(IdentifyManaResultShow(bool)));
    client.Close();

    if(is)
    {
        ManaDialog *mana = new ManaDialog();

        mana->show();
        this->close();
    }
    else
    {
        QMessageBox::information(NULL,"登陆提示","登陆失败",QMessageBox::Ok);
    }
}
