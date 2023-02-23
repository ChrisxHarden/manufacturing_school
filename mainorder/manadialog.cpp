/*第九组吕志伟*/

#include "manadialog.h"
#include "ui_manadialog.h"
#include "commom.h"
#include <QMessageBox>
#include <QModelIndex>
#include <QtScript>
ManaDialog::ManaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MamaDialog)
{
    ui->setupUi(this);
    numberofdish = 0;
    model = new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,"订单号");
    model->setHeaderData(1,Qt::Horizontal,"订单详情");
    ui->tableView->setWordWrap(true);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,161);
    ui->tableView->setColumnWidth(1,480);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode ( QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *copyAct = new QAction(ui->tableView);
    copyAct->setText("删除");
    connect(copyAct, SIGNAL(triggered()), this, SLOT(deleteOrder()));
    ui->tableView->addAction(copyAct);
    QAction *detailAct = new QAction(ui->tableView);
    detailAct->setText("详情");
    connect(detailAct, SIGNAL(triggered()), this, SLOT(showOrder()));
    ui->tableView->addAction(detailAct);
}

ManaDialog::~ManaDialog()
{
    delete ui;
}

void ManaDialog::GetNewOrder()
{
    ui->bt_refresh->setEnabled(false);
    char str[BUFFERSIZE_MAX]	= { 0 };
    sprintf(str,"{\"cmd\":\"_cmd_get_order\", \"cmd_type\":23}");
    qDebug()<<"cmd is "<<str;

    connect(&client,SIGNAL(GotGetOrderResult(QString)),this,SLOT(GetOrderResultShow(QString)));
    client.ConnectToServer( SERVER_IP, SERVER_PORT );
    client.waitForConnected( -1 );
    if( !client.WriteData(str, strlen(str) + 1) ) {
        qDebug()<< "WriteData failed !\n" ;
        return;
    }
}

void ManaDialog::GetOrderResultShow(QString json)
{
    ui->bt_refresh->setEnabled(true);
    disconnect(&client,SIGNAL(GotGetOrderResult(QString)),this,SLOT(GetOrderResultShow(QString)));
    client.Close();
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);
    if (sc.property("orders").isArray())
    {
        int i = numberofdish;
        //qDebug()<<"ManaDialog::GetOrderResultShow(QString json)--is a array "<<numberofdish;
        QScriptValueIterator it(sc.property("orders"));
        while (it.hasNext()) {
            it.next();
            QString number = it.value().property("number").toString();
            QString info = it.value().property("info").toString();
            //info.replace(QString(";"),QString("\n"));
            //qDebug()<<"ManaDialog::GetOrderResultShow --info"<<info;
            if((number!=""))
            {
                model->setItem(i,0,new QStandardItem(number));
                model->setItem(i,1,new QStandardItem(info));
                numberofdish++;
            }
            i++;
        }
    }
    else
    {
        qDebug()<<"ManaDialog::GetOrderResultShow(QString json)--not a array";
    }

}

void ManaDialog::on_bt_refresh_clicked()
{
    GetNewOrder();
}

void ManaDialog::deleteOrder()
{
    QModelIndex index = ui->tableView->currentIndex();
    if(QMessageBox::Yes == QMessageBox::question(NULL, "确认", "确认删除这个菜单？",
                                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
        if(model->removeRow(index.row())){
            numberofdish--;
        }
    }

}

void ManaDialog::SetPhone(QString p)
{
    this->phone = p;
    ui->label_name->setText(p);
}

void ManaDialog::showOrder()
{
    QModelIndex index = ui->tableView->currentIndex();
    QString number = model->item(index.row(),0)->text();
    QString order = model->item(index.row(),1)->text();
    order.replace(QString(";"),QString("\n"));
    QMessageBox::information(NULL,number+" 号订单详情",order,QMessageBox::Ok);

}
