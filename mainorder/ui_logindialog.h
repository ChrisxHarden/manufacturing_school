

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QTabWidget *tabWidget_1;
    QWidget *tab;
    QPushButton *bt_vip_login;
    QPushButton *bt_register;
    QLabel *label_user_2;
    QLineEdit *lineEdit;
    QWidget *tab_2;
    QPushButton *bt_mana_login;
    QLabel *label_user_1;
    QLineEdit *lineEdit_2;
    QPushButton *bt_user_login;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(549, 404);
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        LoginDialog->setFont(font);
        LoginDialog->setStyleSheet(QString::fromUtf8(""));
        tabWidget_1 = new QTabWidget(LoginDialog);
        tabWidget_1->setObjectName(QString::fromUtf8("tabWidget_1"));
        tabWidget_1->setGeometry(QRect(120, 54, 321, 201));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        bt_vip_login = new QPushButton(tab);
        bt_vip_login->setObjectName(QString::fromUtf8("bt_vip_login"));
        bt_vip_login->setGeometry(QRect(30, 130, 61, 31));
        bt_register = new QPushButton(tab);
        bt_register->setObjectName(QString::fromUtf8("bt_register"));
        bt_register->setGeometry(QRect(244, 130, 61, 31));
        QFont font1;
        font1.setStyleStrategy(QFont::PreferDefault);
        bt_register->setFont(font1);
        label_user_2 = new QLabel(tab);
        label_user_2->setObjectName(QString::fromUtf8("label_user_2"));
        label_user_2->setGeometry(QRect(40, 53, 61, 21));
        QFont font2;
        font2.setPointSize(11);
        label_user_2->setFont(font2);
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 50, 151, 26));
        tabWidget_1->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        bt_mana_login = new QPushButton(tab_2);
        bt_mana_login->setObjectName(QString::fromUtf8("bt_mana_login"));
        bt_mana_login->setGeometry(QRect(236, 130, 61, 31));
        label_user_1 = new QLabel(tab_2);
        label_user_1->setObjectName(QString::fromUtf8("label_user_1"));
        label_user_1->setGeometry(QRect(40, 53, 61, 21));
        label_user_1->setFont(font2);
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 50, 151, 26));
        tabWidget_1->addTab(tab_2, QString());
        bt_user_login = new QPushButton(LoginDialog);
        bt_user_login->setObjectName(QString::fromUtf8("bt_user_login"));
        bt_user_login->setGeometry(QRect(190, 340, 140, 35));
        bt_user_login->setFont(font2);
#ifndef QT_NO_SHORTCUT
        label_user_2->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(LoginDialog);

        tabWidget_1->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        bt_vip_login->setText(QApplication::translate("LoginDialog", "\347\231\273 \345\275\225", 0, QApplication::UnicodeUTF8));
        bt_register->setText(QApplication::translate("LoginDialog", "\346\263\250 \345\206\214", 0, QApplication::UnicodeUTF8));
        label_user_2->setText(QApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", 0, QApplication::UnicodeUTF8));
        tabWidget_1->setTabText(tabWidget_1->indexOf(tab), QApplication::translate("LoginDialog", "VIP\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        bt_mana_login->setText(QApplication::translate("LoginDialog", "\347\231\273 \345\275\225", 0, QApplication::UnicodeUTF8));
        label_user_1->setText(QApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", 0, QApplication::UnicodeUTF8));
        tabWidget_1->setTabText(tabWidget_1->indexOf(tab_2), QApplication::translate("LoginDialog", "\347\273\217 \347\220\206", 0, QApplication::UnicodeUTF8));
        bt_user_login->setText(QApplication::translate("LoginDialog", "\346\231\256\351\200\232\347\224\250\346\210\267\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
