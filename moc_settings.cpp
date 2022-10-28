/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    QByteArrayData data[15];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Settings_t qt_meta_stringdata_Settings = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Settings"
QT_MOC_LITERAL(1, 9, 13), // "connectgetipp"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 2), // "ip"
QT_MOC_LITERAL(4, 27, 4), // "port"
QT_MOC_LITERAL(5, 32, 13), // "emitinmainwin"
QT_MOC_LITERAL(6, 46, 16), // "on_BtnOK_clicked"
QT_MOC_LITERAL(7, 63, 20), // "on_BtnReturn_clicked"
QT_MOC_LITERAL(8, 84, 21), // "on_BtnPicAdrs_clicked"
QT_MOC_LITERAL(9, 106, 20), // "on_BtnVdAdrs_clicked"
QT_MOC_LITERAL(10, 127, 13), // "slotmaintoset"
QT_MOC_LITERAL(11, 141, 13), // "slotisconnect"
QT_MOC_LITERAL(12, 155, 1), // "a"
QT_MOC_LITERAL(13, 157, 9), // "storeippt"
QT_MOC_LITERAL(14, 167, 9) // "getippfmt"

    },
    "Settings\0connectgetipp\0\0ip\0port\0"
    "emitinmainwin\0on_BtnOK_clicked\0"
    "on_BtnReturn_clicked\0on_BtnPicAdrs_clicked\0"
    "on_BtnVdAdrs_clicked\0slotmaintoset\0"
    "slotisconnect\0a\0storeippt\0getippfmt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   70,    2, 0x08 /* Private */,
       7,    0,   71,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    1,   75,    2, 0x08 /* Private */,
      13,    0,   78,    2, 0x08 /* Private */,
      14,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Settings *_t = static_cast<Settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectgetipp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->emitinmainwin(); break;
        case 2: _t->on_BtnOK_clicked(); break;
        case 3: _t->on_BtnReturn_clicked(); break;
        case 4: _t->on_BtnPicAdrs_clicked(); break;
        case 5: _t->on_BtnVdAdrs_clicked(); break;
        case 6: _t->slotmaintoset(); break;
        case 7: _t->slotisconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->storeippt(); break;
        case 9: _t->getippfmt(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Settings::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::connectgetipp)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Settings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::emitinmainwin)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Settings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Settings.data,
      qt_meta_data_Settings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Settings::connectgetipp(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Settings::emitinmainwin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
