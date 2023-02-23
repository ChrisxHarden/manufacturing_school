/********************************************************************************
** Form generated from reading UI file 'dishitem.ui'
**
** Created: Fri Nov 19 09:13:49 2021
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISHITEM_H
#define UI_DISHITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DishItem
{
public:
    QLabel *label_pic;
    QLabel *label_name;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_price;

    void setupUi(QWidget *DishItem)
    {
        if (DishItem->objectName().isEmpty())
            DishItem->setObjectName(QString::fromUtf8("DishItem"));
        DishItem->resize(220, 157);
        label_pic = new QLabel(DishItem);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(20, 10, 181, 81));
        label_pic->setScaledContents(true);
        label_pic->setAlignment(Qt::AlignCenter);
        label_name = new QLabel(DishItem);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(20, 100, 171, 20));
        label_name->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(DishItem);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 136, 181, 23));
        layoutWidget = new QWidget(DishItem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 120, 111, 17));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        label_price = new QLabel(layoutWidget);
        label_price->setObjectName(QString::fromUtf8("label_price"));
        label_price->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_price);


        retranslateUi(DishItem);

        QMetaObject::connectSlotsByName(DishItem);
    } // setupUi

    void retranslateUi(QWidget *DishItem)
    {
        DishItem->setWindowTitle(QApplication::translate("DishItem", "Form", 0, QApplication::UnicodeUTF8));
        label_pic->setText(QApplication::translate("DishItem", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("DishItem", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DishItem", "\347\202\271\350\217\234", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DishItem", "\345\215\225\344\273\267\357\274\232 \357\277\245", 0, QApplication::UnicodeUTF8));
        label_price->setText(QApplication::translate("DishItem", "32", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DishItem: public Ui_DishItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISHITEM_H
