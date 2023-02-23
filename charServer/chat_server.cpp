/*第9组赵恩宇*/ 
#include "chat_server.h"
#include "my_socket.h"
#include <QHostAddress>

OrderServer::OrderServer( QObject *parent /* = NULL */ )
        : QTcpServer( parent )
{
        _mysockets.empty();
}

OrderServer::~OrderServer()
{
        qDeleteAll( _mysockets );
        _mysockets.clear();
}

void OrderServer::Run( quint16 port )
{
        if( !this->listen(QHostAddress::Any, port) )
                printf( "ChatServer listen failed !" );
}

void OrderServer::incomingConnection( int handle )
{
        printf( "incomingConnection(): %d !\n", handle );
        MyClientSocket *mysocket = new MyClientSocket( this );
        mysocket->setSocketDescriptor( handle );
        connect( mysocket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()) );
        _mysockets.append( mysocket );
}

void OrderServer::clientDisconnected()
{
        printf( "client disconnected !\n" );
        QList<MyClientSocket*>::iterator iter;
        for( iter = _mysockets.begin(); iter != _mysockets.end(); iter++ ) {
                if( -1 == (*iter)->socketDescriptor() ) {
                        _mysockets.erase( iter );
                        return;
                }
        }
}

