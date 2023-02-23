/*第9组赵恩宇*/ 
#ifndef MY_SOCKET_H
#define MY_SOCKET_H
#include <QThread>
#include <QTcpSocket>
#include <QtScript>
#include <QDebug>
#include <string.h>

class OrderServer;


class MyClientSocket : public QTcpSocket
{
    Q_OBJECT

public:
    MyClientSocket	( QObject *parent = NULL );
    ~MyClientSocket	();
    void  ReadJson(QString json);
    void IdentifyUser(QString json);
    void AddUser(QString json);
    void AddOrder(QString json);
    void GetOrder(QString json);

private slots:
    void	onReadyRead		();
private:
    enum { BUFFERSIZE_MAX = 2048 };
};


#endif // MY_SOCKET_H
