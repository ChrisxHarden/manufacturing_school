/****************************************************************************
** Meta object code from reading C++ file 'manadialog.h'
**
** Created: Thu Nov 18 23:21:50 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../manadialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manadialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManaDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x0a,
      45,   11,   11,   11, 0x0a,
      59,   11,   11,   11, 0x0a,
      71,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ManaDialog[] = {
    "ManaDialog\0\0info\0GetOrderResultShow(QString)\0"
    "deleteOrder()\0showOrder()\0"
    "on_bt_refresh_clicked()\0"
};

const QMetaObject ManaDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ManaDialog,
      qt_meta_data_ManaDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManaDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManaDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManaDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManaDialog))
        return static_cast<void*>(const_cast< ManaDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ManaDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: GetOrderResultShow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: deleteOrder(); break;
        case 2: showOrder(); break;
        case 3: on_bt_refresh_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
