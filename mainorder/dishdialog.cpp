/*第九组于殷豪*/
#include "dishdialog.h"
#include "ui_dishdialog.h"
#include <QDebug>

DishDialog::DishDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DishDialog)
{
    ui->setupUi(this);
    num = 1;

}

DishDialog::~DishDialog()
{
    delete ui;
}

void DishDialog::setDish(dish_s dish,int state)
{
    userState = state;
    this->dish = dish;
    ui->label_name->setText(dish.name);
    ui->label_desc->setText( dish.desc);
    ui->label_desc->setWordWrap(true);
    ui->label_price->setText(QString::number(dish.price));
    ui->label_vip_price->setText(QString::number(dish.vip_price));
    QString pic_path = "./dish_pic/"+dish.pic_name;
    ui->image->setPixmap(QPixmap(pic_path));
    ui->label_num->setText(QString::number(1));
    if(userState == 2)
    {
        ui->label_n_price->setText(QString::number(dish.vip_price));
    }
    else
    {
        ui->label_n_price->setText(QString::number(dish.price));
    }

}

void DishDialog::on_bt_confirm_clicked()
{
    dish_item_s item;
    item.name = dish.name;
    item.num = num;
    item.n_price = num*dish.price;
    if(userState == 2)
    {
        item.n_price = num*dish.vip_price;
    }
    else
    {
        item.n_price = num*dish.price;
    }
    emit AddToMainDishOrder(item);
    this->close();
}

void DishDialog::on_bt_abort_clicked()
{
    this->close();
}

void DishDialog::on_bt_sub_clicked()
{

    num = (num <= 1) ? 1:num-1;
    UpdateNPirce(num);
}

void DishDialog::on_bt_add_clicked()
{

    num = num+1;
    UpdateNPirce(num);

}

void DishDialog::UpdateNPirce(int n)
{
    ui->label_num->setText(QString::number(n));
    if(userState == 2)
    {
        ui->label_n_price->setText(QString::number(n*dish.vip_price));
    }
    else
    {
        ui->label_n_price->setText(QString::number(n*dish.price));
    }
}

void DishDialog::on_bt_abort1_clicked()
{
     this->close();
}
