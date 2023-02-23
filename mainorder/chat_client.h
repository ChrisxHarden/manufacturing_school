/*第九组赵恩宇*/
#ifndef CHAT_CLIENT_H
#define CHAT_CLIENT_H
#include <QTcpSocket>
#include <string.h>
#include <QtScript>
#include <QDebug>

class OrderClient : public QTcpSocket
{
        Q_OBJECT

public:
        OrderClient	( QObject *parent = NULL );
        ~OrderClient	();

        void	ConnectToServer	( const char *ip, quint16 port );
        void	Close			();
        bool	WriteData		( const char *data, qint64 len );
        void    IdentifyUserResult(QString json);
        void    AddUserResult(QString json);
        void    AddOrderResult(QString json);
        void    GetOrderResult(QString json);
        void    GotErrorMsg(QString json);

protected:
        void	ReadJson	(QString json );
signals:
        void    GotIdentifyUserResult(bool isLegal);
        void    GotAddUserResult(bool isAdded);
        void    GotAddOrderResult(bool isAdded);
        void    GotGetOrderResult(QString newOrder);
        void    GotErrorResult(QString msg);


private slots:
        void	OnConnected	();
        void	OnReadyRead	();
        void    test(bool is);

public:
        enum { BUFFERSIZE_MAX = 2048 };
};




#endif // CHAT_CLIENT_H
