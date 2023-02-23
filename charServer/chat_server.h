/*第9组赵恩宇*/ 
#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H
#include <QTcpServer>

class MyClientSocket;

class OrderServer : public QTcpServer
{
        Q_OBJECT

public:
        OrderServer	( QObject *parent = NULL );
        ~OrderServer	();

        void	Run	( quint16 port );

protected:
        void	incomingConnection	( int handle );

private slots:
        void	clientDisconnected	();

private:
        quint16				_port;
        QList<MyClientSocket*>	_mysockets;
};


#endif // CHAT_SERVER_H
