/*第九组于殷豪*/

#include "mainorderdialog.h"
#include "ui_mainorderdialog.h"
#include "commom.h"
#include <QLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>
#include <QPixmap>
#include <QSqlError>
#include <QDateTime>
#include <QStandardItem>
#include "dishdialog.h"

MainOrderDialog::MainOrderDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::MainOrderDialog)
{
    userState = 1;
    numberofdish = 0;
    ui->setupUi(this);
    setFixedSize(800,560);
    model = new QStandardItemModel();
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,"菜名");
    model->setHeaderData(1,Qt::Horizontal,"数量");
    model->setHeaderData(2,Qt::Horizontal,"小计");

    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,119);
    ui->tableView->setColumnWidth(1,46);
    ui->tableView->setColumnWidth(2,46);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode ( QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *copyAct = new QAction(ui->tableView);
    copyAct->setText("删除");
    connect(copyAct, SIGNAL(triggered()), this, SLOT(deleteFronOrder()));
    ui->tableView->addAction(copyAct);



    if(OpenDataBase("orderdata.db"))
    {
        InitTable(ui->gridLayout_2,"湘菜");
        InitTable(ui->gridLayout_3,"粤菜");
        InitTable(ui->gridLayout_4,"川菜");
        InitTable(ui->gridLayout_5,"鲁菜");
        InitTable(ui->gridLayout_6,"家常菜");
        InitTable(ui->gridLayout_7,"酒水饮料");
    }
    db.close();

}

MainOrderDialog::~MainOrderDialog()
{
    delete ui;
    delete cmenu;
    delete model;
}

void MainOrderDialog::InitTable(QGridLayout *gLayout,QString type)
{
    gLayout->setSpacing(1);
    gLayout->setMargin(2);

    QSqlQuery query(db);
    //select * from mql_dish where dish_type = "湘菜"
    query.prepare("select * from mql_dish where dish_type = ?");
    query.addBindValue(type);
    if( !query.exec())
    {
        qDebug()<<"query.exec(select * from mql_dish) failed";
        qDebug()<<query.lastError();
        return;
    }
    QList<dish_s> dish_l;

    while(query.next())
    {
        dish_s dish;
        dish.id =   query.value(0).toInt();
        dish.name = query.value(1).toString();
        dish.type = query.value(2).toString();
        dish.desc = query.value(3).toString();
        dish.pic_name = query.value(4).toString();
        dish.remarks = query.value(5).toString();
        dish.price = query.value(6).toInt();
        dish.vip_price = query.value(7).toInt();
        dish_l.append(dish);
    }
    dish_map.insert(type,dish_l);
    ShowTable(gLayout,type,0);


}
void MainOrderDialog::ShowTable(QGridLayout *gLayout,QString type, int page)
{
    QList<dish_s> dish_l = dish_map.find(type).value();
    QList<dish_s>::iterator it_l;
    int i=0;
    for(it_l = dish_l.begin();( i<9 )&&(it_l != dish_l.end());it_l++,i++)
    {
        dish_s dish = *it_l;
        current_dish = dish;
        DishItem *item = new DishItem();
        item->setDish(dish);
        connect(item,SIGNAL(PopDish(dish_s)),this,SLOT(ShowDishDetail(dish_s)));
        gLayout->addWidget(item,i/3,i%3);
    }
}
bool MainOrderDialog::OpenDataBase(QString name)
{
    db = QSqlDatabase::addDatabase("QSQLITE","order");
    db.setDatabaseName(name);
    if(!db.open())
    {
        qDebug()<<"open database failed";
        return false;
    }
    else
    {
        qDebug()<<"open database success";
        return true;
    }
}

void MainOrderDialog::deleteFronOrder()
{
    QModelIndex index = ui->tableView->currentIndex();
    qDebug()<<" Dialog1::deleteFronOrder "<<index.row();
    if(QMessageBox::Yes == QMessageBox::question(NULL, "确认", "确认删除这道菜？",
                                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
        if(model->removeRow(index.row())){
            numberofdish--;
        }
    }
    ui->label_total_money->setText(QString::number(GetOrderTotalMoney()));

}

void MainOrderDialog::SetUserState(int state,QString phone)
{
    userState = state;
    this->phone = phone;
    ui->label_phone->setText(phone);
}



void MainOrderDialog::on_bt_confirm_clicked()
{
    QDateTime time  = QDateTime::currentDateTime();
    QString num= time.toString("yyyyMMddhhmmss");
    QString number = num+"t1";
    QByteArray order = GetOrderInfo().toLocal8Bit();
    qDebug()<<"MainOrderDialog::on_bt_confirm_clicked "<< order.data();
    //QString info("test dish order;test dish order;test dish order;test dish order;test dish order");
    //qDebug()<<info;
    char str[BUFFERSIZE_MAX]	= { 0 };
    sprintf(str,"{\"cmd\":\"_cmd_add_order\", \"cmd_type\":23, \"number\":\"%s\", \"info\":\"%s\"}",
            number.toLatin1().data(),order.data());
    qDebug()<<"cmd is "<<str;

    connect(&client,SIGNAL(GotAddOrderResult(bool)),this,SLOT(AddOrderResultShow(bool)));
    connect(&client,SIGNAL(GotErrorResult(QString)),this,SLOT(GetErrorResult(QString)));
    client.ConnectToServer( SERVER_IP, SERVER_PORT );
    client.waitForConnected( -1 );
    if( !client.WriteData(str, strlen(str) + 1) ) {
        qDebug()<< "WriteData failed !\n" ;
        QMessageBox::information(NULL,"出现了错误","连接服务器失败！",QMessageBox::Ok);
        return;
    }
}

int MainOrderDialog::GetOrderTotalMoney()
{
    int rows = model->rowCount();
    int total = 0;
    for(int i = 0;i<rows;i++)
    {
        QStandardItem *item = model->item(i,2);
        total += item->text().toInt();
    }
    return total;
}

QString MainOrderDialog::GetOrderInfo()
{
    int rows = model->rowCount();
    QString info ;
    for(int i = 0;i<rows;i++)
    {
        info += model->item(i,0)->text();
        info += " ×";
        info += model->item(i,1)->text();
        info += " ";
        info += model->item(i,2)->text();
        info += ";";
    }
    return info;
}

void MainOrderDialog::AddOrderResultShow(bool is)
{
    disconnect(&client,SIGNAL(GotAddOrderResult(bool)),this,SLOT(AddOrderResultShow(bool)));
    disconnect(&client,SIGNAL(GotErrorResult(QString)),this,SLOT(GetErrorResult(QString)));
    client.Close();
    if(is)
    {
        QMessageBox::information(NULL,"下单结果","下单成功！",QMessageBox::Ok);
        ClearOrder();
    }
    else
    {
        QMessageBox::information(NULL,"下单结果","下单失败，不可预知的错误出现了！",QMessageBox::Ok);
    }
}
void MainOrderDialog::ClearOrder(){
    for(int i = model->rowCount();i > 0;i--)
    {
        model->removeRow(i-1);
    }
    numberofdish = 0;
    ui->label_total_money->setText("");
}

void MainOrderDialog::ShowDishDetail(dish_s current_dish)
{
    DishDialog *dialog = new DishDialog();
    dialog->setDish(current_dish,userState);
    connect(dialog,SIGNAL(AddToMainDishOrder(dish_item_s)),this,SLOT(AddToDishOrder(dish_item_s)));
    dialog->setModal(true);
    dialog->show();
}

void MainOrderDialog::AddToDishOrder(dish_item_s item)
{
    int i =numberofdish;
    model->setItem(i,0,new QStandardItem(item.name));
    model->item(i,0)->setTextAlignment(Qt::AlignCenter);
    model->setItem(i,1,new QStandardItem(QString::number(item.num )));
    model->setItem(i,2,new QStandardItem(QString::number(item.n_price)));
    numberofdish++;
    ui->label_total_money->setText(QString::number(GetOrderTotalMoney()));

}

void MainOrderDialog::GetErrorResult(QString msg)
{
    disconnect(&client,0,this,0);
    QMessageBox::information(NULL,"出现了错误",msg+"\n服务器出现了错误",QMessageBox::Ok);
}


