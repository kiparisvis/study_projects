/****************************************************************************
** Meta object code from reading C++ file 'depositwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../qt_project/depositwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'depositwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DepositWindow_t {
    const uint offsetsAndSize[48];
    char stringdata0[381];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DepositWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DepositWindow_t qt_meta_stringdata_DepositWindow = {
    {
QT_MOC_LITERAL(0, 13), // "DepositWindow"
QT_MOC_LITERAL(14, 25), // "on_pushButtonCalc_clicked"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 5), // "xrise"
QT_MOC_LITERAL(47, 29), // "on_b_add_to_subs_list_clicked"
QT_MOC_LITERAL(77, 29), // "on_b_add_to_adds_list_clicked"
QT_MOC_LITERAL(107, 14), // "ok_add_clicked"
QT_MOC_LITERAL(122, 14), // "ok_sub_clicked"
QT_MOC_LITERAL(137, 31), // "find_start_finish_dates_deposit"
QT_MOC_LITERAL(169, 24), // "add_payments_to_out_list"
QT_MOC_LITERAL(194, 18), // "append_to_out_list"
QT_MOC_LITERAL(213, 4), // "type"
QT_MOC_LITERAL(218, 4), // "date"
QT_MOC_LITERAL(223, 12), // "adds_or_subs"
QT_MOC_LITERAL(236, 18), // "append_to_aos_list"
QT_MOC_LITERAL(255, 3), // "sum"
QT_MOC_LITERAL(259, 35), // "add_lasts_days_of_years_to_ou..."
QT_MOC_LITERAL(295, 19), // "add_aos_to_out_list"
QT_MOC_LITERAL(315, 21), // "rule_sort_out_by_date"
QT_MOC_LITERAL(337, 6), // "St_out"
QT_MOC_LITERAL(344, 3), // "ti1"
QT_MOC_LITERAL(348, 3), // "ti2"
QT_MOC_LITERAL(352, 13), // "calc_out_list"
QT_MOC_LITERAL(366, 14) // "fill_out_table"

    },
    "DepositWindow\0on_pushButtonCalc_clicked\0"
    "\0xrise\0on_b_add_to_subs_list_clicked\0"
    "on_b_add_to_adds_list_clicked\0"
    "ok_add_clicked\0ok_sub_clicked\0"
    "find_start_finish_dates_deposit\0"
    "add_payments_to_out_list\0append_to_out_list\0"
    "type\0date\0adds_or_subs\0append_to_aos_list\0"
    "sum\0add_lasts_days_of_years_to_out_list\0"
    "add_aos_to_out_list\0rule_sort_out_by_date\0"
    "St_out\0ti1\0ti2\0calc_out_list\0"
    "fill_out_table"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DepositWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    0,  105,    2, 0x08,    2 /* Private */,
       4,    0,  106,    2, 0x08,    3 /* Private */,
       5,    0,  107,    2, 0x08,    4 /* Private */,
       6,    0,  108,    2, 0x08,    5 /* Private */,
       7,    0,  109,    2, 0x08,    6 /* Private */,
       8,    0,  110,    2, 0x08,    7 /* Private */,
       9,    0,  111,    2, 0x08,    8 /* Private */,
      10,    3,  112,    2, 0x08,    9 /* Private */,
      14,    3,  119,    2, 0x08,   13 /* Private */,
      16,    0,  126,    2, 0x08,   17 /* Private */,
      17,    0,  127,    2, 0x08,   18 /* Private */,
      18,    2,  128,    2, 0x08,   19 /* Private */,
      22,    0,  133,    2, 0x08,   22 /* Private */,
      23,    0,  134,    2, 0x08,   23 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QDate, QMetaType::Double,   11,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::QDate, QMetaType::Double,   11,   12,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 19, 0x80000000 | 19,   20,   21,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DepositWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DepositWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButtonCalc_clicked(); break;
        case 1: { int _r = _t->xrise();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->on_b_add_to_subs_list_clicked(); break;
        case 3: _t->on_b_add_to_adds_list_clicked(); break;
        case 4: _t->ok_add_clicked(); break;
        case 5: _t->ok_sub_clicked(); break;
        case 6: _t->find_start_finish_dates_deposit(); break;
        case 7: _t->add_payments_to_out_list(); break;
        case 8: _t->append_to_out_list((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 9: _t->append_to_aos_list((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 10: _t->add_lasts_days_of_years_to_out_list(); break;
        case 11: _t->add_aos_to_out_list(); break;
        case 12: { bool _r = _t->rule_sort_out_by_date((*reinterpret_cast< const St_out(*)>(_a[1])),(*reinterpret_cast< const St_out(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->calc_out_list(); break;
        case 14: _t->fill_out_table(); break;
        default: ;
        }
    }
}

const QMetaObject DepositWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DepositWindow.offsetsAndSize,
    qt_meta_data_DepositWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DepositWindow_t
, QtPrivate::TypeAndForceComplete<DepositWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QDate, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QDate, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const St_out &, std::false_type>, QtPrivate::TypeAndForceComplete<const St_out &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *DepositWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DepositWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DepositWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DepositWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
