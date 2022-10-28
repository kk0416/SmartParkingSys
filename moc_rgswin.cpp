/****************************************************************************
** Meta object code from reading C++ file 'rgswin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rgswin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rgswin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RgsWin_t {
    QByteArrayData data[11];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RgsWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RgsWin_t qt_meta_stringdata_RgsWin = {
    {
QT_MOC_LITERAL(0, 0, 6), // "RgsWin"
QT_MOC_LITERAL(1, 7, 8), // "FmRgsres"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "flag"
QT_MOC_LITERAL(4, 22, 16), // "on_BtnOK_clicked"
QT_MOC_LITERAL(5, 39, 15), // "acceptloginSlot"
QT_MOC_LITERAL(6, 55, 11), // "eventFilter"
QT_MOC_LITERAL(7, 67, 7), // "watched"
QT_MOC_LITERAL(8, 75, 7), // "QEvent*"
QT_MOC_LITERAL(9, 83, 5), // "event"
QT_MOC_LITERAL(10, 89, 20) // "on_BtnCancel_clicked"

    },
    "RgsWin\0FmRgsres\0\0flag\0on_BtnOK_clicked\0"
    "acceptloginSlot\0eventFilter\0watched\0"
    "QEvent*\0event\0on_BtnCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RgsWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    2,   44,    2, 0x08 /* Private */,
      10,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 8,    7,    9,
    QMetaType::Void,

       0        // eod
};

void RgsWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RgsWin *_t = static_cast<RgsWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->FmRgsres((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_BtnOK_clicked(); break;
        case 2: _t->acceptloginSlot(); break;
        case 3: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_BtnCancel_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject RgsWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RgsWin.data,
      qt_meta_data_RgsWin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RgsWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RgsWin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RgsWin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RgsWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
