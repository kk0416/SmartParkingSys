/****************************************************************************
** Meta object code from reading C++ file 'playvdthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "playvdthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playvdthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayVdThread_t {
    QByteArrayData data[23];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayVdThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayVdThread_t qt_meta_stringdata_PlayVdThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PlayVdThread"
QT_MOC_LITERAL(1, 13, 17), // "emitsendincarinfo"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "emitsendoutcarinfo"
QT_MOC_LITERAL(4, 51, 17), // "emitsendpkcarinfo"
QT_MOC_LITERAL(5, 69, 10), // "frameVideo"
QT_MOC_LITERAL(6, 80, 3), // "Mat"
QT_MOC_LITERAL(7, 84, 5), // "frame"
QT_MOC_LITERAL(8, 90, 14), // "sendvdinfoemit"
QT_MOC_LITERAL(9, 105, 6), // "vdname"
QT_MOC_LITERAL(10, 112, 6), // "vdtime"
QT_MOC_LITERAL(11, 119, 6), // "vdpath"
QT_MOC_LITERAL(12, 126, 6), // "vdsize"
QT_MOC_LITERAL(13, 133, 8), // "vdframes"
QT_MOC_LITERAL(14, 142, 16), // "sendpicincaremit"
QT_MOC_LITERAL(15, 159, 9), // "inpicname"
QT_MOC_LITERAL(16, 169, 9), // "inpicpath"
QT_MOC_LITERAL(17, 179, 17), // "sendpicoutcaremit"
QT_MOC_LITERAL(18, 197, 10), // "outpicname"
QT_MOC_LITERAL(19, 208, 10), // "outpicpath"
QT_MOC_LITERAL(20, 219, 16), // "sendpicpkcaremit"
QT_MOC_LITERAL(21, 236, 9), // "pkpicname"
QT_MOC_LITERAL(22, 246, 9) // "pkpicpath"

    },
    "PlayVdThread\0emitsendincarinfo\0\0"
    "emitsendoutcarinfo\0emitsendpkcarinfo\0"
    "frameVideo\0Mat\0frame\0sendvdinfoemit\0"
    "vdname\0vdtime\0vdpath\0vdsize\0vdframes\0"
    "sendpicincaremit\0inpicname\0inpicpath\0"
    "sendpicoutcaremit\0outpicname\0outpicpath\0"
    "sendpicpkcaremit\0pkpicname\0pkpicpath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayVdThread[] = {

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
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       8,    5,   60,    2, 0x06 /* Public */,
      14,    2,   71,    2, 0x06 /* Public */,
      17,    2,   76,    2, 0x06 /* Public */,
      20,    2,   81,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,    9,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   22,

       0        // eod
};

void PlayVdThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayVdThread *_t = static_cast<PlayVdThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emitsendincarinfo(); break;
        case 1: _t->emitsendoutcarinfo(); break;
        case 2: _t->emitsendpkcarinfo(); break;
        case 3: _t->frameVideo((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 4: _t->sendvdinfoemit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 5: _t->sendpicincaremit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->sendpicoutcaremit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->sendpicpkcaremit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PlayVdThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayVdThread::emitsendincarinfo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlayVdThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayVdThread::emitsendoutcarinfo)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PlayVdThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayVdThread::emitsendpkcarinfo)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PlayVdThread::*_t)(Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayVdThread::frameVideo)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PlayVdThread::*_t)(QString , QString , QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayVdThread::sendvdinfoemit)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (PlayVdThread::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayVdThread::sendpicincaremit)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (PlayVdThread::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayVdThread::sendpicoutcaremit)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (PlayVdThread::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayVdThread::sendpicpkcaremit)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject PlayVdThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PlayVdThread.data,
      qt_meta_data_PlayVdThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlayVdThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayVdThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayVdThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PlayVdThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PlayVdThread::emitsendincarinfo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PlayVdThread::emitsendoutcarinfo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PlayVdThread::emitsendpkcarinfo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PlayVdThread::frameVideo(Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlayVdThread::sendvdinfoemit(QString _t1, QString _t2, QString _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlayVdThread::sendpicincaremit(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PlayVdThread::sendpicoutcaremit(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PlayVdThread::sendpicpkcaremit(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
