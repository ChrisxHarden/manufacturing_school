/*第9组赵恩宇*/ 
#include "chat_server.h"
#include <QtCore/QCoreApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QCoreApplication a(argc, argv);

    OrderServer server;
    server.Run( 33333 );

    return a.exec();
}
