/*第九组董浩然*/

#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "chat_client.h"
namespace Ui {
    class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();
public slots:
        void AddUserResultShow(bool);
private slots:
        void on_bt_confirm_clicked();

        void on_bt_abort_clicked();

private:
    Ui::RegisterDialog *ui;
    OrderClient client;
};

#endif // REGISTERDIALOG_H
