/****************************************************************************
** Meta object code from reading C++ file 'chat_client.h'
**
** Created: Thu Nov 18 23:21:53 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chat_client.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OrderClient[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   13,   12,   12, 0x05,
      57,   49,   12,   12, 0x05,
      80,   49,   12,   12, 0x05,
     113,  104,   12,   12, 0x05,
     144,  140,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     168,   12,   12,   12, 0x08,
     182,   12,   12,   12, 0x08,
     199,  196,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OrderClient[] = {
    "OrderClient\0\0isLegal\0GotIdentifyUserResult(bool)\0"
    "isAdded\0GotAddUserResult(bool)\0"
    "GotAddOrderResult(bool)\0newOrder\0"
    "GotGetOrderResult(QString)\0msg\0"
    "GotErrorResult(QString)\0OnConnected()\0"
    "OnReadyRead()\0is\0test(bool)\0"
};

const QMetaObject OrderClient::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_OrderClient,
      qt_meta_data_OrderClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OrderClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OrderClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OrderClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrderClient))
        return static_cast<void*>(const_cast< OrderClient*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int OrderClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: GotIdentifyUserResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: GotAddUserResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: GotAddOrderResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: GotGetOrderResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: GotErrorResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: OnConnected(); break;
        case 6: OnReadyRead(); break;
        case 7: test((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void OrderClient::GotIdentifyUserResult(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OrderClient::GotAddUserResult(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void OrderClient::GotAddOrderResult(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void OrderClient::GotGetOrderResult(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void OrderClient::GotErrorResult(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
