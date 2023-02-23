/********************************************************************************
** Form generated from reading UI file 'mainorderdialog.ui'
**
** Created: Fri Nov 19 09:13:49 2021
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINORDERDIALOG_H
#define UI_MAINORDERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainOrderDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QWidget *tab_2;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_3;
    QWidget *tab_3;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_4;
    QWidget *tab_4;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_5;
    QWidget *tab_6;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_6;
    QWidget *tab_5;
    QWidget *layoutWidget_7;
    QGridLayout *gridLayout_7;
    QPushButton *bt_confirm;
    QLabel *label_phone;
    QTableView *tableView;
    QLabel *label_total;
    QLabel *label_total_money;

    void setupUi(QDialog *MainOrderDialog)
    {
        if (MainOrderDialog->objectName().isEmpty())
            MainOrderDialog->setObjectName(QString::fromUtf8("MainOrderDialog"));
        MainOrderDialog->resize(800, 560);
        tabWidget = new QTabWidget(MainOrderDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(220, 10, 571, 541));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 0, 571, 531));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget_3 = new QWidget(tab_2);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(0, 0, 571, 521));
        gridLayout_3 = new QGridLayout(layoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget_4 = new QWidget(tab_3);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(0, 0, 571, 521));
        gridLayout_4 = new QGridLayout(layoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        layoutWidget_5 = new QWidget(tab_4);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(0, 0, 571, 521));
        gridLayout_5 = new QGridLayout(layoutWidget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        layoutWidget_6 = new QWidget(tab_6);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(0, 0, 571, 521));
        gridLayout_6 = new QGridLayout(layoutWidget_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        layoutWidget_7 = new QWidget(tab_5);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(0, 0, 571, 521));
        gridLayout_7 = new QGridLayout(layoutWidget_7);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_5, QString());
        bt_confirm = new QPushButton(MainOrderDialog);
        bt_confirm->setObjectName(QString::fromUtf8("bt_confirm"));
        bt_confirm->setGeometry(QRect(8, 510, 211, 41));
        label_phone = new QLabel(MainOrderDialog);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));
        label_phone->setGeometry(QRect(20, 0, 181, 16));
        tableView = new QTableView(MainOrderDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(8, 11, 211, 461));
        label_total = new QLabel(MainOrderDialog);
        label_total->setObjectName(QString::fromUtf8("label_total"));
        label_total->setGeometry(QRect(8, 474, 96, 34));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_total->setFont(font);
        label_total->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_total_money = new QLabel(MainOrderDialog);
        label_total_money->setObjectName(QString::fromUtf8("label_total_money"));
        label_total_money->setGeometry(QRect(104, 474, 115, 34));
        QFont font1;
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_total_money->setFont(font1);
        label_total_money->setAlignment(Qt::AlignCenter);
        label_total_money->setMargin(5);

        retranslateUi(MainOrderDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainOrderDialog);
    } // setupUi

    void retranslateUi(QDialog *MainOrderDialog)
    {
        MainOrderDialog->setWindowTitle(QApplication::translate("MainOrderDialog", "\347\202\271\350\217\234", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainOrderDialog", "\346\271\230\350\217\234", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainOrderDialog", "\347\262\244\350\217\234", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainOrderDialog", "\345\267\235\350\217\234", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainOrderDialog", "\351\262\201\350\217\234", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainOrderDialog", "\345\256\266\345\270\270\350\217\234", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainOrderDialog", "\351\205\222\346\260\264\351\245\256\346\226\231", 0, QApplication::UnicodeUTF8));
        bt_confirm->setText(QApplication::translate("MainOrderDialog", "\347\241\256\350\256\244\344\270\213\345\215\225", 0, QApplication::UnicodeUTF8));
        label_phone->setText(QString());
        label_total->setText(QApplication::translate("MainOrderDialog", "\346\200\273\344\273\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_total_money->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainOrderDialog: public Ui_MainOrderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINORDERDIALOG_H
