/*第九组于殷豪*/

#ifndef DISHITEM_H
#define DISHITEM_H

#include <QWidget>
#include "data_struct.h"
namespace Ui {
    class DishItem;
}

class DishItem : public QWidget
{
    Q_OBJECT

public:
    explicit DishItem(QWidget *parent = 0);
    ~DishItem();
    void setDish(dish_s dish);
signals:
    void PopDish(dish_s);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DishItem *ui;
    dish_s dish;
};

#endif // DISHITEM_H
