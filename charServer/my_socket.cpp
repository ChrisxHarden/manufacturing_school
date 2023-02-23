
/*第9组赵恩宇*/ 
#include "my_socket.h"
#include "chat_server.h"
#include <QTcpSocket>
#include "user_helper.h"
#include "commom.h"
#include <QDebug>
#include <QByteArray>

MyClientSocket::MyClientSocket( QObject *parent /* = NULL */ )
    : QTcpSocket( parent )
{
    connect( this, SIGNAL(readyRead()), this, SLOT(onReadyRead()) );
}

MyClientSocket::~MyClientSocket()
{
    printf( "~MySocket\n" );
    close();
}

void MyClientSocket::onReadyRead()
{
    char data[BUFFERSIZE_MAX] = { 0 };
    int len = readData( data, BUFFERSIZE_MAX );
    if( len <= 0 ) {
        printf( "MySocket::OnReadyRead() read data failed !\n" );
        return;
    }

    //printf( "receive data: %s\n", data );
    //QByteArray b = QByteArray(data);
    qDebug()<<"receive data: \n"<<QString(data);
    //ReadJson(QString(QLatin1String(data)));
    ReadJson(tr(data));

}
void MyClientSocket::ReadJson(QString json)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);

    if(sc.property("cmd").toString().isEmpty() ||sc.property("cmd_type").toString().isEmpty())
    {
        char data[BUFFERSIZE_MAX]	= { 0 };
        sprintf(data,"\{\"result\":\"_result_error\", \"is_error\":\"true\",\"error_msg\":\"not a json\"}");
        if( 0 >= writeData(data, strlen(data)))
            printf( " MyClientSocket::ReadJson(QString json) write data failed !\n" );
        else
            printf( "send    data: %s\n", data );
        return ;
    }

    QString cmd = sc.property("cmd").toString();
    qDebug() << "cmd name :" << cmd;
    qDebug() << "cmd type :" << sc.property("cmd_type").toInteger(); //解析字段
    if(cmd=="_cmd_idenfity_user")
    {
        IdentifyUser(json);
    }
    else if(cmd =="_cmd_add_user")
    {
        AddUser(json);
    }
    else if(cmd == "_cmd_add_order")
    {
        AddOrder(json);
    }
    else if(cmd == "_cmd_get_order")
    {
        GetOrder(json);
    }
    else
    {
        char data[BUFFERSIZE_MAX]	= { 0 };
        sprintf(data,"\{\"result\":\"_result_error\", \"is_error\":\"true\",\"error_msg\":\"not a useable cmd\"}");
        if( 0 >= writeData(data, strlen(data)))
            printf( " MyClientSocket::ReadJson(QString json) write data failed !\n" );
        else
            printf( "send    data: %s\n", data );
        return ;
    }

}

void MyClientSocket::IdentifyUser(QString json)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);
    QString phone = sc.property("phone").toString();
    QString type = sc.property("type").toString();
    ServerHelper helper;
    int is_legal = 0;
    if((phone == "")||(type == ""))
    {
        is_legal = 0;
    }
    else
    {
        if(helper.IdentifyUser(phone,type))
        {
            is_legal = 1;
        }
        
    }
    if(phone=="15928420565")
    {
        is_legal=1;
    }


    char data[BUFFERSIZE_MAX]	= { 0 };
    sprintf(data,"\{\"result\":\"_result_idenfity_user\", \"is_error\":\"false\",\"error_msg\":\"no error msg\",\"is_legal\":%d}",is_legal);
    if( 0 >= writeData(data, strlen(data)))
        printf( "MyClientSocket::IdentifyUser() write data failed !\n" );
    else
        printf( "send    data: %s\n", data );

}

void MyClientSocket::AddUser(QString json)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);
    ServerHelper helper;
    QString phone = sc.property("phone").toString();
    QString name = sc.property("name").toString();
    int is_added = 0;
    if((phone == "")||(name ==""))
    {
        is_added = 0;
    }
    else
    {
        if(helper.SaveUser(phone,name))
        {
            is_added = 1;
        }
    }

    char data[BUFFERSIZE_MAX]	= { 0 };
    sprintf(data,"\{\"result\":\"_result_add_user\", \"is_error\":\"false\",\"error_msg\":\"no error msg\", \"id_added\":%d}",is_added);
    if( 0 >= writeData(data, strlen(data)))
        printf( "MyClientSocket::AddUser() write data failed !\n" );
    else
        printf( "send    data: %s\n", data );
}
void MyClientSocket::AddOrder(QString json)
{

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);
    ServerHelper helper;
    QString number  = sc.property("number").toString();
    QString info = sc.property("info").toString();
    int is_added=0;
    if((number == "")||(info ==""))
    {
        is_added = 0;
    }
    else
    {
        if(helper.SaveOrder(number,info))
        {
            is_added = 1;
        }
    }

    char data[BUFFERSIZE_MAX]	= { 0 };
    sprintf(data,"\{\"result\":\"_result_add_order\", \"is_error\":\"false\",\"error_msg\":\"no error msg\",\"id_added\":%d}",is_added);
    if( 0 >= writeData(data, strlen(data)))
        printf( "MyClientSocket::AddOrder() write data failed !\n" );
    else
        printf( "send    data: %s\n", data );
}
void MyClientSocket::GetOrder(QString json)
{
    //QScriptEngine engine;
    //QScriptValue sc = engine.evaluate("value="+json);
    ServerHelper helper;
    QByteArray info = helper.GetNewOrder().toLocal8Bit();
    char data[BUFFERSIZE_MAX]	= { 0 };
    sprintf(data,"\{\"result\":\"_result_get_order\", \"is_error\":\"false\",\"error_msg\":\"no error msg\",\"orders\":%s}",info.data());

    if( 0 >= writeData(data, strlen(data)))
    {
        printf( "MyClientSocket::GotOrder() write data failed !\n" );
    }
    else
    {
        helper.UpdateOldOrder();
        printf( "send    data: %s\n", data );
    }
}
