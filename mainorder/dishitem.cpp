/*第九组于殷豪*/
#include "dishitem.h"
#include "ui_dishitem.h"

DishItem::DishItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DishItem)
{
    ui->setupUi(this);

}

DishItem::~DishItem()
{
    delete ui;
}

void DishItem::on_pushButton_clicked()
{
    emit PopDish(dish);
}

void DishItem::setDish(dish_s dish)
{
    this->dish = dish;
    ui->label_name->setText(dish.name);
    ui->label_price->setText(QString::number(dish.price));
    QString pic_path = "./dish_pic/"+dish.pic_name;
    ui->label_pic->setPixmap(QPixmap(pic_path));
}
