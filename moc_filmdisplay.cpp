/****************************************************************************
** Meta object code from reading C++ file 'filmdisplay.h'
**
** Created: Fri May 11 22:21:46 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "filmdisplay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filmdisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FilmDisplay[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FilmDisplay[] = {
    "FilmDisplay\0\0on_buttonClose_released()\0"
};

const QMetaObject FilmDisplay::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_FilmDisplay,
      qt_meta_data_FilmDisplay, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FilmDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FilmDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FilmDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FilmDisplay))
        return static_cast<void*>(const_cast< FilmDisplay*>(this));
    return QFrame::qt_metacast(_clname);
}

int FilmDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_buttonClose_released(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
