/*第九组于殷豪*/

#ifndef MAINORDERDIALOG_H
#define MAINORDERDIALOG_H

#include <QMenu>
#include <QDialog>
#include <QStandardItemModel>
#include <QString>
#include <QMap>
#include <QList>
#include <QGridLayout>
#include <QSqlDatabase>
#include "chat_client.h"
#include "data_struct.h"
#include "dishitem.h"
namespace Ui {
    class MainOrderDialog;
}

class MainOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainOrderDialog(QWidget *parent = 0);
    ~MainOrderDialog();
    void InitTable(QGridLayout *gLayout,QString type);
    void ShowTable(QGridLayout *gLayout,QString type,int page);
    bool OpenDataBase(QString name);
    void SetUserState(int state,QString phone);
    int GetOrderTotalMoney();
    QString GetOrderInfo();
    void ClearOrder();

public slots:
    void deleteFronOrder();
    void AddOrderResultShow(bool is);
    void ShowDishDetail(dish_s current_dish);
    void AddToDishOrder(dish_item_s item);
    void GetErrorResult(QString msg);
private slots:
    void on_bt_confirm_clicked();

private:
    Ui::MainOrderDialog *ui;
    QMenu *cmenu ;
    QStandardItemModel *model;
    QSqlDatabase db;
    int userState; //1,user //2,vip
    QString phone;//user phone
    int numberofdish;
    OrderClient client;
    QMap< QString,QList<dish_s> > dish_map;
    QMap< QString,int > dish_page;
    dish_s current_dish;
};

#endif // MAINORDERDIALOG_H
