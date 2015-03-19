/****************************************************************************
** Meta object code from reading C++ file 'doors_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Demo/src/controllers/doors_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doors_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Doors_Controller_t {
    QByteArrayData data[12];
    char stringdata[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Doors_Controller_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Doors_Controller_t qt_meta_stringdata_Doors_Controller = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Doors_Controller"
QT_MOC_LITERAL(1, 17, 12), // "updatePanels"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "value"
QT_MOC_LITERAL(4, 37, 17), // "disableRightPanel"
QT_MOC_LITERAL(5, 55, 16), // "disableLeftPanel"
QT_MOC_LITERAL(6, 72, 18), // "reactiveRightPanel"
QT_MOC_LITERAL(7, 91, 17), // "reactiveLeftPanel"
QT_MOC_LITERAL(8, 109, 13), // "openLeftDoors"
QT_MOC_LITERAL(9, 123, 14), // "closeLeftDoors"
QT_MOC_LITERAL(10, 138, 14), // "openRightDoors"
QT_MOC_LITERAL(11, 153, 15) // "closeRightDoors"

    },
    "Doors_Controller\0updatePanels\0\0value\0"
    "disableRightPanel\0disableLeftPanel\0"
    "reactiveRightPanel\0reactiveLeftPanel\0"
    "openLeftDoors\0closeLeftDoors\0"
    "openRightDoors\0closeRightDoors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Doors_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Doors_Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Doors_Controller *_t = static_cast<Doors_Controller *>(_o);
        switch (_id) {
        case 0: _t->updatePanels((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->disableRightPanel(); break;
        case 2: _t->disableLeftPanel(); break;
        case 3: _t->reactiveRightPanel(); break;
        case 4: _t->reactiveLeftPanel(); break;
        case 5: _t->openLeftDoors(); break;
        case 6: _t->closeLeftDoors(); break;
        case 7: _t->openRightDoors(); break;
        case 8: _t->closeRightDoors(); break;
        default: ;
        }
    }
}

const QMetaObject Doors_Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Doors_Controller.data,
      qt_meta_data_Doors_Controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Doors_Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Doors_Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Doors_Controller.stringdata))
        return static_cast<void*>(const_cast< Doors_Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int Doors_Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
