/********************************************************************************
** Form generated from reading UI file 'welcomedialog.ui'
**
** Created: Fri Nov 19 09:13:49 2021
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEDIALOG_H
#define UI_WELCOMEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WelcomeDialog
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *WelcomeDialog)
    {
        if (WelcomeDialog->objectName().isEmpty())
            WelcomeDialog->setObjectName(QString::fromUtf8("WelcomeDialog"));
        WelcomeDialog->resize(549, 404);
        label = new QLabel(WelcomeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 549, 404));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(WelcomeDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 350, 71, 31));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        pushButton->setFont(font);

        retranslateUi(WelcomeDialog);

        QMetaObject::connectSlotsByName(WelcomeDialog);
    } // setupUi

    void retranslateUi(QDialog *WelcomeDialog)
    {
        WelcomeDialog->setWindowTitle(QApplication::translate("WelcomeDialog", "\346\254\242\350\277\216", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WelcomeDialog", "\346\254\242\350\277\216\346\235\245\345\210\260\347\202\271\351\244\220\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("WelcomeDialog", "\350\277\233  \345\205\245", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WelcomeDialog: public Ui_WelcomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEDIALOG_H
