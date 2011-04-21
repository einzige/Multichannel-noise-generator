/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Apr 21 23:43:51 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      24,   11,   11,   11, 0x05,
      39,   11,   11,   11, 0x05,
      56,   11,   11,   11, 0x05,
      84,   80,   11,   11, 0x05,
     114,  104,   11,   11, 0x05,
     145,  137,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     171,   11,   11,   11, 0x0a,
     183,   80,   11,   11, 0x0a,
     204,   11,   11,   11, 0x08,
     234,   11,   11,   11, 0x08,
     278,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0grayscale()\0restoreImage()\0"
    "rateChanged(int)\0channelChanged(QString)\0"
    "img\0imageLoaded(QImage)\0blackRate\0"
    "applyImpulseNoise(int)\0maxDiff\0"
    "applyAdditionalNoise(int)\0loadImage()\0"
    "displayImage(QImage)\0on_applyAdditButton_clicked()\0"
    "on_channelsBox_currentIndexChanged(QString)\0"
    "on_applyImpulseButton_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "IView"))
        return static_cast< IView*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: grayscale(); break;
        case 1: restoreImage(); break;
        case 2: rateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: channelChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: imageLoaded((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 5: applyImpulseNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: applyAdditionalNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: loadImage(); break;
        case 8: displayImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 9: on_applyAdditButton_clicked(); break;
        case 10: on_channelsBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: on_applyImpulseButton_clicked(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::grayscale()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindow::restoreImage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::rateChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::channelChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::imageLoaded(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::applyImpulseNoise(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::applyAdditionalNoise(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
