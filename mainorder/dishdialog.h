
/*第九组于殷豪*/
#ifndef DISHDIALOG_H
#define DISHDIALOG_H

#include <QDialog>
#include "data_struct.h"

namespace Ui {
    class DishDialog;
}

class DishDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DishDialog(QWidget *parent = 0);
    ~DishDialog();
    void setDish(dish_s dish,int state);
    void UpdateNPirce(int n);
signals:
    void AddToMainDishOrder(dish_item_s item);

private slots:
    void on_bt_confirm_clicked();
    void on_bt_abort_clicked();
    void on_bt_sub_clicked();
    void on_bt_add_clicked();

    void on_bt_abort1_clicked();

private:
    Ui::DishDialog *ui;
    dish_s dish;//infromarion of this dish
    int num;//number of this dish
    int userState;
};

#endif // DISHDIALOG_H
