/*第9组赵恩宇*/ 
#ifndef USER_HELPER_H
#define USER_HELPER_H
#include <QObject>
#include <QSqlDatabase>
class ServerHelper : public QObject{
    Q_OBJECT


public :
        ServerHelper(QObject *parent = NULL);
        ~ServerHelper();
        bool IdentifyUser(QString phone,QString type);
        bool SaveUser(QString phone,QString name);
        bool SaveOrder(QString number,QString info);
        QString GetNewOrder();
        bool UpdateOldOrder();
        bool OpenDataBase(QString name);
private :
        QSqlDatabase db;
};

#endif // USER_HELPER_H
