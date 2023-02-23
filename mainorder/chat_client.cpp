/*第九组赵恩宇*/
#include "chat_client.h"
#include <QHostAddress>

OrderClient::OrderClient( QObject *parent /* = NULL */ )
    : QTcpSocket( parent )
{
    connect( this, SIGNAL(readyRead()), this, SLOT(OnReadyRead()) );
    connect( this, SIGNAL(connected()), this, SLOT(OnConnected()) );
}

OrderClient::~OrderClient()
{

}

void OrderClient::ConnectToServer( const char *ip, quint16 port )
{
    QString strip( ip );
    QHostAddress addr;
    addr.setAddress( strip );
    connectToHost( addr, port );
}

void OrderClient::OnConnected()
{
    qDebug()<<"connected:"<< socketDescriptor() ;
}

void OrderClient::Close()
{
    disconnectFromHost();
    close();
}

bool OrderClient::WriteData( const char *data, qint64 len )
{
    if( NULL == data || len <= 0 )
        return false;
    qint64 ret = writeData( data, len );
    if( 0 >= ret )
        return false;

    waitForBytesWritten( -1 );					
    qDebug()<< "send    data: "<<data ;
    waitForReadyRead( -1 );					

    return true;
}
void OrderClient::OnReadyRead()
{
    char data[BUFFERSIZE_MAX] = { 0 };
    qint64 len = readData( data, BUFFERSIZE_MAX );
    if( len <= 0 )
    {
        qDebug()<<"ChatClient::OnReadyRead() read data failed !\n" ;
        return;
    }
    qDebug()<< "receive data\n"<< data ;
    ReadJson(tr(data) );
}





void OrderClient::ReadJson(QString json )
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);
    QString result = sc.property("result").toString();
    qDebug() << "OrderClient::ReadJson(QString json )--get rsult "<<result; //解析字段
    if(result=="_result_idenfity_user")
    {
        IdentifyUserResult(json);
    }
    else  if(result=="_result_add_user")
    {
        AddUserResult(json);
    }
    else if(result=="_result_add_order")
    {
        AddOrderResult(json);
    }
    else if(result=="_result_get_order")
    {
         GetOrderResult(json);
    }
    else if(result == "_result_error")
    {
         GotErrorMsg(json);
    }
}
void OrderClient::test(bool is)
{
    qDebug()<<"ChatClient::test"<<is;
}

void OrderClient::IdentifyUserResult(QString json)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);
    //QString eMsg = sc.property("error_msg").toString();
    int is_legal = sc.property("is_legal").toString().toInt();

    if(is_legal == 1)
    {
        emit GotIdentifyUserResult(true);
    }
    else
    {
        emit GotIdentifyUserResult(false);
    }

}
void OrderClient::AddUserResult(QString json)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);
    //QString eMsg = sc.property("error_msg").toString();
    int is_added = sc.property("id_added").toString().toInt();
    if(is_added == 1)
    {
        emit GotAddUserResult(true);
    }
    else
    {
        emit GotAddUserResult(false);
    }

}

void OrderClient::AddOrderResult(QString json)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);
   // QString eMsg = sc.property("error_msg").toString();

    int is_added = sc.property("id_added").toString().toInt();
    if(is_added == 1)
    {
        emit GotAddOrderResult(true);
    }
    else
    {
        emit GotAddOrderResult(false);
    }
}

void OrderClient::GetOrderResult(QString json)
{
    //QScriptEngine engine;
    //QScriptValue sc = engine.evaluate("value="+json);
    //QString eMsg = sc.property("error_msg").toString();
    //qDebug()<<"ChatClient::GetOrderResult"<<eMsg;
    //QString info = sc.property("orders").toString();
    //qDebug()<<"OrderClient::GetOrderResult(QString json)--"<<json;
    emit GotGetOrderResult(json);
}

void OrderClient::GotErrorMsg(QString json)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value="+json);
    QString eMsg = sc.property("error_msg").toString();
    qDebug()<<"ChatClient::GetOrderResult"<<eMsg;
    emit GotErrorResult(eMsg);
}


