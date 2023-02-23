/*第9组赵恩宇*/ 
#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include <stdio.h>
#include <QString>

typedef struct user_struct{
    QString phone;
    QString name;
    QString type;

}user_s;


typedef struct order_struct{
    QString number;
    QString info;

}order_s;


typedef struct dish_struct{
    int id;
    QString name;
    QString type;
    QString desc;
    QString pic_name;
    QString remarks;
    int price;
    int vip_price;

}dish_s;

typedef struct dish_item_struct{
    QString name;
    int num;
    int n_price;
    QString remark;
}dish_item_s;

#endif // DATA_STRUCT_H
