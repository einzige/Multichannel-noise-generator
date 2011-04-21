/****************************************************************************
** Meta object code from reading C++ file 'noisepresenter.h'
**
** Created: Thu Apr 21 18:45:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../noisepresenter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'noisepresenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NoisePresenter[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      33,   31,   15,   15, 0x0a,
      77,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NoisePresenter[] = {
    "NoisePresenter\0\0restoreImage()\0,\0"
    "applyImpulseFilter(Channel::Identifier,int)\0"
    "loadImage(QImage)\0"
};

const QMetaObject NoisePresenter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NoisePresenter,
      qt_meta_data_NoisePresenter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NoisePresenter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NoisePresenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NoisePresenter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NoisePresenter))
        return static_cast<void*>(const_cast< NoisePresenter*>(this));
    return QObject::qt_metacast(_clname);
}

int NoisePresenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: restoreImage(); break;
        case 1: applyImpulseFilter((*reinterpret_cast< Channel::Identifier(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: loadImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
