/*第九组*/
#include <QtGui/QApplication>
#include "logindialog.h"
#include <QTextCodec>
#include <QFile>
#include <QDebug>
#include <QTime>
#include "welcomedialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);

    QString qss;
    QFile qssFile(":/new/qss/order.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qDebug()<<"get qss file";
        qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }
    else
    {
        qDebug()<<"get qss file failed" ;
    }

    WelcomeDialog *wel = new WelcomeDialog();
    wel->show();
    

    return a.exec();
}
