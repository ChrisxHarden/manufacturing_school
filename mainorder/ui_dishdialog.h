/********************************************************************************
** Form generated from reading UI file 'dishdialog.ui'
**
** Created: Fri Nov 19 09:13:49 2021
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISHDIALOG_H
#define UI_DISHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DishDialog
{
public:
    QLabel *image;
    QLabel *label_name;
    QLabel *label_desc;
    QPushButton *bt_abort1;
    QPushButton *bt_confirm;
    QLabel *label_jia;
    QLabel *label_price;
    QLabel *label_huiyuan;
    QLabel *label_vip_price;
    QLabel *label_numb;
    QPushButton *bt_sub;
    QLabel *label_num;
    QPushButton *bt_add;
    QLabel *label_n_price;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *DishDialog)
    {
        if (DishDialog->objectName().isEmpty())
            DishDialog->setObjectName(QString::fromUtf8("DishDialog"));
        DishDialog->resize(492, 319);
        image = new QLabel(DishDialog);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(15, 15, 311, 161));
        image->setLayoutDirection(Qt::LeftToRight);
        image->setScaledContents(true);
        image->setAlignment(Qt::AlignCenter);
        label_name = new QLabel(DishDialog);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(350, 30, 121, 41));
        label_name->setAlignment(Qt::AlignCenter);
        label_desc = new QLabel(DishDialog);
        label_desc->setObjectName(QString::fromUtf8("label_desc"));
        label_desc->setGeometry(QRect(0, 190, 492, 61));
        label_desc->setScaledContents(true);
        bt_abort1 = new QPushButton(DishDialog);
        bt_abort1->setObjectName(QString::fromUtf8("bt_abort1"));
        bt_abort1->setGeometry(QRect(410, 273, 71, 31));
        bt_confirm = new QPushButton(DishDialog);
        bt_confirm->setObjectName(QString::fromUtf8("bt_confirm"));
        bt_confirm->setGeometry(QRect(330, 273, 71, 31));
        label_jia = new QLabel(DishDialog);
        label_jia->setObjectName(QString::fromUtf8("label_jia"));
        label_jia->setGeometry(QRect(350, 80, 51, 43));
        label_price = new QLabel(DishDialog);
        label_price->setObjectName(QString::fromUtf8("label_price"));
        label_price->setGeometry(QRect(440, 80, 41, 41));
        label_price->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 20pt \"Adobe Arabic\";"));
        label_huiyuan = new QLabel(DishDialog);
        label_huiyuan->setObjectName(QString::fromUtf8("label_huiyuan"));
        label_huiyuan->setGeometry(QRect(350, 120, 61, 41));
        label_vip_price = new QLabel(DishDialog);
        label_vip_price->setObjectName(QString::fromUtf8("label_vip_price"));
        label_vip_price->setGeometry(QRect(440, 120, 51, 41));
        label_vip_price->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 20pt \"Adobe Arabic\";"));
        label_numb = new QLabel(DishDialog);
        label_numb->setObjectName(QString::fromUtf8("label_numb"));
        label_numb->setGeometry(QRect(15, 265, 41, 49));
        label_numb->setAlignment(Qt::AlignCenter);
        bt_sub = new QPushButton(DishDialog);
        bt_sub->setObjectName(QString::fromUtf8("bt_sub"));
        bt_sub->setGeometry(QRect(60, 272, 31, 35));
        bt_sub->setMinimumSize(QSize(0, 35));
        label_num = new QLabel(DishDialog);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(90, 275, 41, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_num->setFont(font);
        label_num->setAlignment(Qt::AlignCenter);
        bt_add = new QPushButton(DishDialog);
        bt_add->setObjectName(QString::fromUtf8("bt_add"));
        bt_add->setGeometry(QRect(130, 272, 31, 35));
        bt_add->setMinimumSize(QSize(0, 35));
        label_n_price = new QLabel(DishDialog);
        label_n_price->setObjectName(QString::fromUtf8("label_n_price"));
        label_n_price->setGeometry(QRect(170, 264, 51, 49));
        label_n_price->setAlignment(Qt::AlignCenter);
        label = new QLabel(DishDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(420, 85, 16, 31));
        label_2 = new QLabel(DishDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 125, 16, 31));

        retranslateUi(DishDialog);

        QMetaObject::connectSlotsByName(DishDialog);
    } // setupUi

    void retranslateUi(QDialog *DishDialog)
    {
        DishDialog->setWindowTitle(QApplication::translate("DishDialog", "\350\217\234\345\223\201\350\257\246\346\203\205", 0, QApplication::UnicodeUTF8));
        image->setText(QApplication::translate("DishDialog", "picname", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("DishDialog", "name", 0, QApplication::UnicodeUTF8));
        label_desc->setText(QApplication::translate("DishDialog", "\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        bt_abort1->setText(QApplication::translate("DishDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        bt_confirm->setText(QApplication::translate("DishDialog", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        label_jia->setText(QApplication::translate("DishDialog", "\344\273\267  \346\240\274", 0, QApplication::UnicodeUTF8));
        label_price->setText(QApplication::translate("DishDialog", "123", 0, QApplication::UnicodeUTF8));
        label_huiyuan->setText(QApplication::translate("DishDialog", "\344\274\232\345\221\230\344\273\267", 0, QApplication::UnicodeUTF8));
        label_vip_price->setText(QApplication::translate("DishDialog", "121", 0, QApplication::UnicodeUTF8));
        label_numb->setText(QApplication::translate("DishDialog", "\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        bt_sub->setText(QApplication::translate("DishDialog", "-", 0, QApplication::UnicodeUTF8));
        label_num->setText(QApplication::translate("DishDialog", "1", 0, QApplication::UnicodeUTF8));
        bt_add->setText(QApplication::translate("DishDialog", "+", 0, QApplication::UnicodeUTF8));
        label_n_price->setText(QApplication::translate("DishDialog", "123", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DishDialog", "\357\277\245", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DishDialog", "\357\277\245", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DishDialog: public Ui_DishDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISHDIALOG_H
