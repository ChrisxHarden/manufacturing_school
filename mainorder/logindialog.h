/*第九组董浩然*/

#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "chat_client.h"
namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
public slots:
        void IdentifyUserResultShow(bool);
        void IdentifyManaResultShow(bool);

private slots:
    void on_bt_user_login_clicked();

    void on_bt_mana_login_clicked();

    void on_bt_register_clicked();

    void on_bt_vip_login_clicked();

private:
    Ui::LoginDialog *ui;
    OrderClient client;
};

#endif // LOGINDIALOG_H
