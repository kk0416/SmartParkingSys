/****************************************************************************
** Meta object code from reading C++ file 'readthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "readthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'readthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReadThread_t {
    QByteArrayData data[16];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReadThread_t qt_meta_stringdata_ReadThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ReadThread"
QT_MOC_LITERAL(1, 11, 8), // "SendSign"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "flag"
QT_MOC_LITERAL(4, 26, 7), // "SendRgs"
QT_MOC_LITERAL(5, 34, 13), // "sendincarinfo"
QT_MOC_LITERAL(6, 48, 13), // "sendphotoinfo"
QT_MOC_LITERAL(7, 62, 13), // "sendvideoinfo"
QT_MOC_LITERAL(8, 76, 6), // "VIDEO*"
QT_MOC_LITERAL(9, 83, 9), // "videoinfo"
QT_MOC_LITERAL(10, 93, 10), // "sendvdinfo"
QT_MOC_LITERAL(11, 104, 14), // "sendoutcarinfo"
QT_MOC_LITERAL(12, 119, 9), // "CAR_INFO*"
QT_MOC_LITERAL(13, 129, 8), // "carinfo6"
QT_MOC_LITERAL(14, 138, 14), // "sendsrccarinfo"
QT_MOC_LITERAL(15, 153, 8) // "carinfo7"

    },
    "ReadThread\0SendSign\0\0flag\0SendRgs\0"
    "sendincarinfo\0sendphotoinfo\0sendvideoinfo\0"
    "VIDEO*\0videoinfo\0sendvdinfo\0sendoutcarinfo\0"
    "CAR_INFO*\0carinfo6\0sendsrccarinfo\0"
    "carinfo7"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReadThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    1,   60,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,
       7,    1,   66,    2, 0x06 /* Public */,
      10,    1,   69,    2, 0x06 /* Public */,
      11,    1,   72,    2, 0x06 /* Public */,
      14,    1,   75,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   15,

       0        // eod
};

void ReadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReadThread *_t = static_cast<ReadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendSign((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SendRgs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendincarinfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendphotoinfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sendvideoinfo((*reinterpret_cast< VIDEO*(*)>(_a[1]))); break;
        case 5: _t->sendvdinfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sendoutcarinfo((*reinterpret_cast< CAR_INFO*(*)>(_a[1]))); break;
        case 7: _t->sendsrccarinfo((*reinterpret_cast< CAR_INFO*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ReadThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::SendSign)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::SendRgs)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::sendincarinfo)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::sendphotoinfo)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(VIDEO * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::sendvideoinfo)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::sendvdinfo)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(CAR_INFO * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::sendoutcarinfo)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(CAR_INFO * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::sendsrccarinfo)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject ReadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ReadThread.data,
      qt_meta_data_ReadThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ReadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReadThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ReadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ReadThread::SendSign(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ReadThread::SendRgs(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ReadThread::sendincarinfo(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ReadThread::sendphotoinfo(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ReadThread::sendvideoinfo(VIDEO * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ReadThread::sendvdinfo(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ReadThread::sendoutcarinfo(CAR_INFO * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ReadThread::sendsrccarinfo(CAR_INFO * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
