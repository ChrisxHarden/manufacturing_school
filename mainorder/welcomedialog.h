/*吕志伟*/
#ifndef WELCOMEDIALOG_H
#define WELCOMEDIALOG_H

#include <QDialog>

namespace Ui {
    class WelcomeDialog;
}

class WelcomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomeDialog(QWidget *parent = 0);
    ~WelcomeDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WelcomeDialog *ui;
};

#endif // WELCOMEDIALOG_H
