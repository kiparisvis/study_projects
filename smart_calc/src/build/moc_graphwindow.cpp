/****************************************************************************
** Meta object code from reading C++ file 'graphwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../qt_project/graphwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphWindow_t {
    const uint offsetsAndSize[20];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GraphWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GraphWindow_t qt_meta_stringdata_GraphWindow = {
    {
QT_MOC_LITERAL(0, 11), // "GraphWindow"
QT_MOC_LITERAL(12, 9), // "slot_xMin"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 3), // "num"
QT_MOC_LITERAL(27, 9), // "slot_xMax"
QT_MOC_LITERAL(37, 9), // "slot_yMin"
QT_MOC_LITERAL(47, 9), // "slot_yMax"
QT_MOC_LITERAL(57, 9), // "plotGraph"
QT_MOC_LITERAL(67, 5), // "char*"
QT_MOC_LITERAL(73, 12) // "infix_string"

    },
    "GraphWindow\0slot_xMin\0\0num\0slot_xMax\0"
    "slot_yMin\0slot_yMax\0plotGraph\0char*\0"
    "infix_string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    1,   47,    2, 0x0a,    3 /* Public */,
       5,    1,   50,    2, 0x0a,    5 /* Public */,
       6,    1,   53,    2, 0x0a,    7 /* Public */,
       7,    1,   56,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void GraphWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slot_xMin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->slot_xMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->slot_yMin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->slot_yMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->plotGraph((*reinterpret_cast< char*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GraphWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_GraphWindow.offsetsAndSize,
    qt_meta_data_GraphWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GraphWindow_t
, QtPrivate::TypeAndForceComplete<GraphWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>


>,
    nullptr
} };


const QMetaObject *GraphWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int GraphWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
