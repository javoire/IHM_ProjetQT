/****************************************************************************
** Meta object code from reading C++ file 'filterform.h'
**
** Created: Fri May 11 21:56:49 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "filterform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FilterForm[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   12,   11,   11, 0x05,
      62,   54,   11,   11, 0x05,
      90,   82,   11,   11, 0x05,
     116,  110,   11,   11, 0x05,
     138,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     166,  160,   11,   11, 0x0a,
     199,  160,   11,   11, 0x0a,
     232,  160,   11,   11, 0x0a,
     267,  160,   11,   11, 0x0a,
     302,   12,   11,   11, 0x0a,
     329,   11,   11,   11, 0x08,
     360,  355,   11,   11, 0x08,
     395,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FilterForm[] = {
    "FilterForm\0\0checked,name\0"
    "genreIsClicked(bool,QString)\0yearMin\0"
    "yearMinChanged(int)\0yearMax\0"
    "yearMaxChanged(int)\0title\0"
    "titleChanged(QString)\0searchButtonClicked()\0"
    "value\0DoubleSlider_yearMinChanged(int)\0"
    "DoubleSlider_yearMaxChanged(int)\0"
    "DoubleSlider_yearMinSetByUser(int)\0"
    "DoubleSlider_yearMaxSetByUser(int)\0"
    "checkToggled(bool,QString)\0"
    "on_buttonPopup_released()\0arg1\0"
    "on_titleInput_textChanged(QString)\0"
    "on_Search_released()\0"
};

const QMetaObject FilterForm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FilterForm,
      qt_meta_data_FilterForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FilterForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FilterForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FilterForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FilterForm))
        return static_cast<void*>(const_cast< FilterForm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FilterForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: genreIsClicked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: yearMinChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: yearMaxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: titleChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: searchButtonClicked(); break;
        case 5: DoubleSlider_yearMinChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: DoubleSlider_yearMaxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: DoubleSlider_yearMinSetByUser((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: DoubleSlider_yearMaxSetByUser((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: checkToggled((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: on_buttonPopup_released(); break;
        case 11: on_titleInput_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: on_Search_released(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FilterForm::genreIsClicked(bool _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilterForm::yearMinChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FilterForm::yearMaxChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FilterForm::titleChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FilterForm::searchButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
