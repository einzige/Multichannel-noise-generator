/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Apr 23 02:27:54 2011
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
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      24,   11,   11,   11, 0x05,
      39,   11,   11,   11, 0x05,
      56,   11,   11,   11, 0x05,
      80,   11,   11,   11, 0x05,
      95,   91,   11,   11, 0x05,
     125,  115,   11,   11, 0x05,
     156,  148,   11,   11, 0x05,
     187,  182,   11,   11, 0x05,
     213,  208,   11,   11, 0x05,
     234,  208,   11,   11, 0x05,
     253,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     263,   11,   11,   11, 0x0a,
     275,   91,   11,   11, 0x0a,
     296,   11,   11,   11, 0x08,
     331,   11,   11,   11, 0x08,
     361,   11,   11,   11, 0x08,
     391,   11,   11,   11, 0x08,
     435,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0grayscale()\0restoreImage()\0"
    "rateChanged(int)\0channelChanged(QString)\0"
    "showHist()\0img\0imageLoaded(QImage)\0"
    "blackRate\0applyImpulseNoise(int)\0"
    "maxDiff\0applyAdditionalNoise(int)\0"
    "coef\0applyMultiNoise(int)\0diff\0"
    "applyBrightness(int)\0applyContrast(int)\0"
    "inverse()\0loadImage()\0displayImage(QImage)\0"
    "on_applyBrightnessButton_clicked()\0"
    "on_applyMultiButton_clicked()\0"
    "on_applyAdditButton_clicked()\0"
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
        case 4: showHist(); break;
        case 5: imageLoaded((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 6: applyImpulseNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: applyAdditionalNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: applyMultiNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: applyBrightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: applyContrast((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: inverse(); break;
        case 12: loadImage(); break;
        case 13: displayImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 14: on_applyBrightnessButton_clicked(); break;
        case 15: on_applyMultiButton_clicked(); break;
        case 16: on_applyAdditButton_clicked(); break;
        case 17: on_channelsBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: on_applyImpulseButton_clicked(); break;
        default: ;
        }
        _id -= 19;
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
void MainWindow::showHist()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MainWindow::imageLoaded(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::applyImpulseNoise(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::applyAdditionalNoise(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::applyMultiNoise(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::applyBrightness(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::applyContrast(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::inverse()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}
QT_END_MOC_NAMESPACE
