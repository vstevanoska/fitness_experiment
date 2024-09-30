/****************************************************************************
** Meta object code from reading C++ file 'FitnessExperimentServer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../FitnessExperimentServer/FitnessExperimentServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FitnessExperimentServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FitnessExperimentServer_t {
    const uint offsetsAndSize[16];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FitnessExperimentServer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FitnessExperimentServer_t qt_meta_stringdata_FitnessExperimentServer = {
    {
QT_MOC_LITERAL(0, 23), // "FitnessExperimentServer"
QT_MOC_LITERAL(24, 6), // "closed"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 15), // "onNewConnection"
QT_MOC_LITERAL(48, 18), // "processTextMessage"
QT_MOC_LITERAL(67, 7), // "message"
QT_MOC_LITERAL(75, 20), // "processBinaryMessage"
QT_MOC_LITERAL(96, 18) // "socketDisconnected"

    },
    "FitnessExperimentServer\0closed\0\0"
    "onNewConnection\0processTextMessage\0"
    "message\0processBinaryMessage\0"
    "socketDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FitnessExperimentServer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    1,   46,    2, 0x08,    3 /* Private */,
       6,    1,   49,    2, 0x08,    5 /* Private */,
       7,    0,   52,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,

       0        // eod
};

void FitnessExperimentServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FitnessExperimentServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->onNewConnection(); break;
        case 2: _t->processTextMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->processBinaryMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->socketDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FitnessExperimentServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FitnessExperimentServer::closed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FitnessExperimentServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FitnessExperimentServer.offsetsAndSize,
    qt_meta_data_FitnessExperimentServer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FitnessExperimentServer_t
, QtPrivate::TypeAndForceComplete<FitnessExperimentServer, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FitnessExperimentServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FitnessExperimentServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FitnessExperimentServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FitnessExperimentServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FitnessExperimentServer::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
