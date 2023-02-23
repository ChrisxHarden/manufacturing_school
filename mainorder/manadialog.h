/*第九组吕志伟*/

#ifndef MAMADIALOG_H
#define MAMADIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include "chat_client.h"
namespace Ui {
    class MamaDialog;
}

class ManaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManaDialog(QWidget *parent = 0);
    ~ManaDialog();
    void GetNewOrder();
    void SetPhone(QString p);

public slots:
    void GetOrderResultShow(QString info);
    void deleteOrder();
    void showOrder();

private slots:
    void on_bt_refresh_clicked();

private:
    Ui::MamaDialog *ui;
    OrderClient client;
    QStandardItemModel *model;
    int numberofdish;
    QString phone;
};

#endif // MAMADIALOG_H
