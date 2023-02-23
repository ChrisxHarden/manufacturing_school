/*第9组赵恩宇*/ 

#include "user_helper.h"
#include <QSqlQuery>
#include <QDebug>
#include <QVariant>
#include <QSqlError>

ServerHelper::ServerHelper(QObject *parent): QObject(parent)
{

}

ServerHelper::~ServerHelper()
{

}
bool ServerHelper::IdentifyUser(QString phone, QString type)
{
    if(!OpenDataBase("orderdata.db"))
    {
        return false;
    }
    QSqlQuery query(db);
    query.prepare("select * from mql_user where phone = ? and user_type = ?");
    query.addBindValue(phone);
    query.addBindValue(type);

    if( !query.exec() )
    {
        qDebug()<<"select * from mql_user where phone ... failed";
        qDebug()<<query.lastError();
        return false;
    }

    if( query.next() && ( query.value(0).toString() == phone ))
    {
        return true;
    }
    qDebug()<<"select * from mql_user where phone ...not recorded";
    return false;
}
bool ServerHelper::SaveUser(QString phone, QString name)
{
    if(!OpenDataBase("orderdata.db"))
    {
        return false;
    }
    QSqlQuery query(db);
    query.prepare("insert into mql_user values(?,?,1)");
    query.addBindValue(phone);
    query.addBindValue(name);
    if( !query.exec())
    {
        qDebug()<<"insert into mql_user values(?,?,1) failed";
        qDebug()<<query.lastError();
        return false;
    }
    return true;
}
bool ServerHelper::SaveOrder(QString number,QString info)
{
    if(!OpenDataBase("orderdata.db"))
    {
        return false;
    }
    QSqlQuery query(db);
    query.prepare("insert into mql_order values(?,?,?)");
    query.addBindValue(number);
    query.addBindValue(info);
    query.addBindValue("1");
    if(!query.exec())
    {
        qDebug()<<"insert into mql_order values(?,?,?) failed";
        qDebug()<<query.lastError();
        return false;
    }
    return true;
}
QString ServerHelper::GetNewOrder()
{
    if(!OpenDataBase("orderdata.db"))
    {
        return QString("");
    }

    QSqlQuery query(db);
    query.prepare("select * from mql_order where order_state = ?");
    query.addBindValue("1");
    if(!query.exec())
    {
        qDebug()<<"insert into mql_order values(?,?,?) failed";
        qDebug()<<query.lastError();
        return false;
    }

    QString result;
    int count =0;
    result +="[";
    while(query.next())
    {
        qDebug()<<" ServerHelper::GetNewOrder--get new order " << count;
        count ++;
        QString order_item = QString("{\"number\":\"%1\",\"info\":\"%2\"}").arg(query.value(0).toString()).arg(query.value(1).toString());
        result += order_item ;
        result += ",";
    }
   // qDebug()<<"get new order " << result;
    if(count > 0){
        result = result.replace(result.length()-1,1,QString("]"));
    }
    else{
        result += "]";
    }
    qDebug()<<"get new order " << result;
    return result;
}

bool ServerHelper::OpenDataBase(QString name)
{
    db = QSqlDatabase::addDatabase("QSQLITE","order");
    db.setDatabaseName(name);
    if(!db.open())
    {
        qDebug()<<"open database failed";
        return false;
    }
    else
    {
        qDebug()<<"open database success";
        return true;
    }
}

bool ServerHelper::UpdateOldOrder()
{
    qDebug()<<" ServerHelper::UpdateOldOrder()";
    QSqlQuery query(db);
    query.prepare("update mql_order set order_state = ? where order_state = ?");
    query.addBindValue("2");
    query.addBindValue("1");
    if(!query.exec())
    {
        qDebug()<<"update mql_order set order_state = ? ";
        qDebug()<<query.lastError();
        return false;
    }
    return true;
}
