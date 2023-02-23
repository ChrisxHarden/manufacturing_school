/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created: Fri Nov 19 09:13:49 2021
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLineEdit *le_phone;
    QLabel *label_phone;
    QLabel *label_n;
    QLineEdit *le_name;
    QGraphicsView *graphicsView;
    QPushButton *bt_confirm;
    QPushButton *bt_abort;
    QLabel *label_register;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QString::fromUtf8("RegisterDialog"));
        RegisterDialog->resize(549, 404);
        QFont font;
        font.setPointSize(7);
        RegisterDialog->setFont(font);
        le_phone = new QLineEdit(RegisterDialog);
        le_phone->setObjectName(QString::fromUtf8("le_phone"));
        le_phone->setGeometry(QRect(248, 147, 151, 26));
        label_phone = new QLabel(RegisterDialog);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));
        label_phone->setGeometry(QRect(150, 140, 61, 41));
        QFont font1;
        font1.setPointSize(11);
        label_phone->setFont(font1);
        label_n = new QLabel(RegisterDialog);
        label_n->setObjectName(QString::fromUtf8("label_n"));
        label_n->setGeometry(QRect(150, 182, 61, 41));
        label_n->setFont(font1);
        le_name = new QLineEdit(RegisterDialog);
        le_name->setObjectName(QString::fromUtf8("le_name"));
        le_name->setGeometry(QRect(248, 189, 151, 26));
        graphicsView = new QGraphicsView(RegisterDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(110, 61, 331, 261));
        bt_confirm = new QPushButton(RegisterDialog);
        bt_confirm->setObjectName(QString::fromUtf8("bt_confirm"));
        bt_confirm->setGeometry(QRect(140, 270, 61, 31));
        QFont font2;
        font2.setPointSize(10);
        bt_confirm->setFont(font2);
        bt_abort = new QPushButton(RegisterDialog);
        bt_abort->setObjectName(QString::fromUtf8("bt_abort"));
        bt_abort->setGeometry(QRect(366, 275, 61, 31));
        bt_abort->setFont(font2);
        label_register = new QLabel(RegisterDialog);
        label_register->setObjectName(QString::fromUtf8("label_register"));
        label_register->setGeometry(QRect(245, 77, 81, 31));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setStyleStrategy(QFont::PreferAntialias);
        label_register->setFont(font3);
        graphicsView->raise();
        le_phone->raise();
        label_phone->raise();
        label_n->raise();
        le_name->raise();
        bt_confirm->raise();
        bt_abort->raise();
        label_register->raise();

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        label_phone->setText(QApplication::translate("RegisterDialog", "\346\211\213\346\234\272\345\217\267", 0, QApplication::UnicodeUTF8));
        label_n->setText(QApplication::translate("RegisterDialog", "\345\247\223  \345\220\215", 0, QApplication::UnicodeUTF8));
        bt_confirm->setText(QApplication::translate("RegisterDialog", "\347\241\256  \350\256\244", 0, QApplication::UnicodeUTF8));
        bt_abort->setText(QApplication::translate("RegisterDialog", "\345\217\226  \346\266\210", 0, QApplication::UnicodeUTF8));
        label_register->setText(QApplication::translate("RegisterDialog", "\346\263\250  \345\206\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
