
#ifndef UI_MANADIALOG_H
#define UI_MANADIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_MamaDialog
{
public:
    QLabel *label_name;
    QLabel *label;
    QPushButton *bt_refresh;
    QTableView *tableView;

    void setupUi(QDialog *MamaDialog)
    {
        if (MamaDialog->objectName().isEmpty())
            MamaDialog->setObjectName(QString::fromUtf8("MamaDialog"));
        MamaDialog->resize(682, 434);
        label_name = new QLabel(MamaDialog);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(590, 20, 71, 21));
        label = new QLabel(MamaDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 30, 61, 21));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bt_refresh = new QPushButton(MamaDialog);
        bt_refresh->setObjectName(QString::fromUtf8("bt_refresh"));
        bt_refresh->setGeometry(QRect(20, 10, 75, 31));
        tableView = new QTableView(MamaDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 60, 641, 361));

        retranslateUi(MamaDialog);

        QMetaObject::connectSlotsByName(MamaDialog);
    } // setupUi

    void retranslateUi(QDialog *MamaDialog)
    {
        MamaDialog->setWindowTitle(QApplication::translate("MamaDialog", "\347\273\217\347\220\206\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        label_name->setText(QString());
        label->setText(QApplication::translate("MamaDialog", "\350\256\242\345\215\225\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        bt_refresh->setText(QApplication::translate("MamaDialog", "\345\210\267 \346\226\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MamaDialog: public Ui_MamaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANADIALOG_H
