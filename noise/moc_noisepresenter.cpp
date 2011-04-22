/****************************************************************************
** Meta object code from reading C++ file 'noisepresenter.h'
**
** Created: Sat Apr 23 02:27:55 2011
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
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      28,   15,   15,   15, 0x0a,
      38,   15,   15,   15, 0x0a,
      51,   15,   15,   15, 0x0a,
      66,   15,   15,   15, 0x0a,
      89,   15,   15,   15, 0x0a,
     115,   15,   15,   15, 0x0a,
     142,   15,   15,   15, 0x0a,
     167,   15,   15,   15, 0x0a,
     188,   15,   15,   15, 0x0a,
     218,  206,   15,   15, 0x0a,
     238,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NoisePresenter[] = {
    "NoisePresenter\0\0grayscale()\0inverse()\0"
    "setRate(int)\0restoreImage()\0"
    "applyImpulseNoise(int)\0applyAdditionalNoise(int)\0"
    "applyBrightnessFilter(int)\0"
    "applyContrastFilter(int)\0applyMultiNoise(int)\0"
    "loadImage(QImage)\0channelName\0"
    "setChannel(QString)\0showHist()\0"
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
        case 0: grayscale(); break;
        case 1: inverse(); break;
        case 2: setRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: restoreImage(); break;
        case 4: applyImpulseNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: applyAdditionalNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: applyBrightnessFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: applyContrastFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: applyMultiNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: loadImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 10: setChannel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: showHist(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
