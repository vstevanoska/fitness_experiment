/****************************************************************************
** Meta object code from reading C++ file 'fitnessexperiment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../FitnessExperiment/fitnessexperiment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fitnessexperiment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FitnessExperiment_t {
    QByteArrayData data[68];
    char stringdata0[871];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FitnessExperiment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FitnessExperiment_t qt_meta_stringdata_FitnessExperiment = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FitnessExperiment"
QT_MOC_LITERAL(1, 18, 24), // "loadSelectExperimentPage"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 16), // "loadAnalysisPage"
QT_MOC_LITERAL(4, 61, 13), // "addAccReading"
QT_MOC_LITERAL(5, 75, 13), // "timestampTemp"
QT_MOC_LITERAL(6, 89, 5), // "xTemp"
QT_MOC_LITERAL(7, 95, 5), // "yTemp"
QT_MOC_LITERAL(8, 101, 5), // "zTemp"
QT_MOC_LITERAL(9, 107, 13), // "addGyrReading"
QT_MOC_LITERAL(10, 121, 7), // "setUser"
QT_MOC_LITERAL(11, 129, 8), // "userTemp"
QT_MOC_LITERAL(12, 138, 17), // "setExperimentName"
QT_MOC_LITERAL(13, 156, 8), // "nameTemp"
QT_MOC_LITERAL(14, 165, 17), // "setExperimentType"
QT_MOC_LITERAL(15, 183, 8), // "typeTemp"
QT_MOC_LITERAL(16, 192, 12), // "setFrequency"
QT_MOC_LITERAL(17, 205, 8), // "freqTemp"
QT_MOC_LITERAL(18, 214, 8), // "setSpeed"
QT_MOC_LITERAL(19, 223, 9), // "speedTemp"
QT_MOC_LITERAL(20, 233, 12), // "setTimestamp"
QT_MOC_LITERAL(21, 246, 14), // "getAccReadings"
QT_MOC_LITERAL(22, 261, 30), // "QVector<AccelerometerReading>*"
QT_MOC_LITERAL(23, 292, 14), // "getGyrReadings"
QT_MOC_LITERAL(24, 307, 26), // "QVector<GyroscopeReading>*"
QT_MOC_LITERAL(25, 334, 7), // "getUser"
QT_MOC_LITERAL(26, 342, 17), // "getExperimentName"
QT_MOC_LITERAL(27, 360, 17), // "getExperimentType"
QT_MOC_LITERAL(28, 378, 12), // "getFrequency"
QT_MOC_LITERAL(29, 391, 8), // "getSpeed"
QT_MOC_LITERAL(30, 400, 12), // "getTimestamp"
QT_MOC_LITERAL(31, 413, 12), // "sendToServer"
QT_MOC_LITERAL(32, 426, 16), // "cancelExperiment"
QT_MOC_LITERAL(33, 443, 18), // "getAccReadingsSize"
QT_MOC_LITERAL(34, 462, 18), // "getGyrReadingsSize"
QT_MOC_LITERAL(35, 481, 17), // "getAccTimestampAt"
QT_MOC_LITERAL(36, 499, 5), // "index"
QT_MOC_LITERAL(37, 505, 9), // "getAccXAt"
QT_MOC_LITERAL(38, 515, 9), // "getAccYAt"
QT_MOC_LITERAL(39, 525, 9), // "getAccZAt"
QT_MOC_LITERAL(40, 535, 17), // "getGyrTimestampAt"
QT_MOC_LITERAL(41, 553, 9), // "getGyrXAt"
QT_MOC_LITERAL(42, 563, 9), // "getGyrYAt"
QT_MOC_LITERAL(43, 573, 9), // "getGyrZAt"
QT_MOC_LITERAL(44, 583, 12), // "clearVectors"
QT_MOC_LITERAL(45, 596, 13), // "loadFilenames"
QT_MOC_LITERAL(46, 610, 12), // "getFilenames"
QT_MOC_LITERAL(47, 623, 14), // "loadExperiment"
QT_MOC_LITERAL(48, 638, 8), // "filename"
QT_MOC_LITERAL(49, 647, 11), // "getAccTsMin"
QT_MOC_LITERAL(50, 659, 11), // "getAccTsMax"
QT_MOC_LITERAL(51, 671, 10), // "getAccXMin"
QT_MOC_LITERAL(52, 682, 10), // "getAccXMax"
QT_MOC_LITERAL(53, 693, 10), // "getAccYMin"
QT_MOC_LITERAL(54, 704, 10), // "getAccYMax"
QT_MOC_LITERAL(55, 715, 10), // "getAccZMin"
QT_MOC_LITERAL(56, 726, 10), // "getAccZMax"
QT_MOC_LITERAL(57, 737, 11), // "getGyrTsMin"
QT_MOC_LITERAL(58, 749, 11), // "getGyrTsMax"
QT_MOC_LITERAL(59, 761, 10), // "getGyrXMin"
QT_MOC_LITERAL(60, 772, 10), // "getGyrXMax"
QT_MOC_LITERAL(61, 783, 10), // "getGyrYMin"
QT_MOC_LITERAL(62, 794, 10), // "getGyrYMax"
QT_MOC_LITERAL(63, 805, 10), // "getGyrZMin"
QT_MOC_LITERAL(64, 816, 10), // "getGyrZMax"
QT_MOC_LITERAL(65, 827, 17), // "getCalculatedData"
QT_MOC_LITERAL(66, 845, 10), // "sensorMode"
QT_MOC_LITERAL(67, 856, 14) // "coordinateMode"

    },
    "FitnessExperiment\0loadSelectExperimentPage\0"
    "\0loadAnalysisPage\0addAccReading\0"
    "timestampTemp\0xTemp\0yTemp\0zTemp\0"
    "addGyrReading\0setUser\0userTemp\0"
    "setExperimentName\0nameTemp\0setExperimentType\0"
    "typeTemp\0setFrequency\0freqTemp\0setSpeed\0"
    "speedTemp\0setTimestamp\0getAccReadings\0"
    "QVector<AccelerometerReading>*\0"
    "getGyrReadings\0QVector<GyroscopeReading>*\0"
    "getUser\0getExperimentName\0getExperimentType\0"
    "getFrequency\0getSpeed\0getTimestamp\0"
    "sendToServer\0cancelExperiment\0"
    "getAccReadingsSize\0getGyrReadingsSize\0"
    "getAccTimestampAt\0index\0getAccXAt\0"
    "getAccYAt\0getAccZAt\0getGyrTimestampAt\0"
    "getGyrXAt\0getGyrYAt\0getGyrZAt\0"
    "clearVectors\0loadFilenames\0getFilenames\0"
    "loadExperiment\0filename\0getAccTsMin\0"
    "getAccTsMax\0getAccXMin\0getAccXMax\0"
    "getAccYMin\0getAccYMax\0getAccZMin\0"
    "getAccZMax\0getGyrTsMin\0getGyrTsMax\0"
    "getGyrXMin\0getGyrXMax\0getGyrYMin\0"
    "getGyrYMax\0getGyrZMin\0getGyrZMax\0"
    "getCalculatedData\0sensorMode\0"
    "coordinateMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FitnessExperiment[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      51,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  269,    2, 0x06 /* Public */,
       3,    0,  270,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    4,  271,    2, 0x02 /* Public */,
       9,    4,  280,    2, 0x02 /* Public */,
      10,    1,  289,    2, 0x02 /* Public */,
      12,    1,  292,    2, 0x02 /* Public */,
      14,    1,  295,    2, 0x02 /* Public */,
      16,    1,  298,    2, 0x02 /* Public */,
      18,    1,  301,    2, 0x02 /* Public */,
      20,    1,  304,    2, 0x02 /* Public */,
      21,    0,  307,    2, 0x02 /* Public */,
      23,    0,  308,    2, 0x02 /* Public */,
      25,    0,  309,    2, 0x02 /* Public */,
      26,    0,  310,    2, 0x02 /* Public */,
      27,    0,  311,    2, 0x02 /* Public */,
      28,    0,  312,    2, 0x02 /* Public */,
      29,    0,  313,    2, 0x02 /* Public */,
      30,    0,  314,    2, 0x02 /* Public */,
      31,    0,  315,    2, 0x02 /* Public */,
      32,    0,  316,    2, 0x02 /* Public */,
      33,    0,  317,    2, 0x02 /* Public */,
      34,    0,  318,    2, 0x02 /* Public */,
      35,    1,  319,    2, 0x02 /* Public */,
      37,    1,  322,    2, 0x02 /* Public */,
      38,    1,  325,    2, 0x02 /* Public */,
      39,    1,  328,    2, 0x02 /* Public */,
      40,    1,  331,    2, 0x02 /* Public */,
      41,    1,  334,    2, 0x02 /* Public */,
      42,    1,  337,    2, 0x02 /* Public */,
      43,    1,  340,    2, 0x02 /* Public */,
      44,    0,  343,    2, 0x02 /* Public */,
      45,    0,  344,    2, 0x02 /* Public */,
      46,    0,  345,    2, 0x02 /* Public */,
      47,    1,  346,    2, 0x02 /* Public */,
      49,    0,  349,    2, 0x02 /* Public */,
      50,    0,  350,    2, 0x02 /* Public */,
      51,    0,  351,    2, 0x02 /* Public */,
      52,    0,  352,    2, 0x02 /* Public */,
      53,    0,  353,    2, 0x02 /* Public */,
      54,    0,  354,    2, 0x02 /* Public */,
      55,    0,  355,    2, 0x02 /* Public */,
      56,    0,  356,    2, 0x02 /* Public */,
      57,    0,  357,    2, 0x02 /* Public */,
      58,    0,  358,    2, 0x02 /* Public */,
      59,    0,  359,    2, 0x02 /* Public */,
      60,    0,  360,    2, 0x02 /* Public */,
      61,    0,  361,    2, 0x02 /* Public */,
      62,    0,  362,    2, 0x02 /* Public */,
      63,    0,  363,    2, 0x02 /* Public */,
      64,    0,  364,    2, 0x02 /* Public */,
      65,    2,  365,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::UInt,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::ULongLong,    5,
    0x80000000 | 22,
    0x80000000 | 24,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::UInt,
    QMetaType::QString,
    QMetaType::LongLong,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Float, QMetaType::Int,   36,
    QMetaType::Float, QMetaType::Int,   36,
    QMetaType::Float, QMetaType::Int,   36,
    QMetaType::Float, QMetaType::Int,   36,
    QMetaType::Float, QMetaType::Int,   36,
    QMetaType::Float, QMetaType::Int,   36,
    QMetaType::Float, QMetaType::Int,   36,
    QMetaType::Float, QMetaType::Int,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::QString, QMetaType::UInt, QMetaType::UInt,   66,   67,

       0        // eod
};

void FitnessExperiment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FitnessExperiment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadSelectExperimentPage(); break;
        case 1: _t->loadAnalysisPage(); break;
        case 2: _t->addAccReading((*reinterpret_cast< const float(*)>(_a[1])),(*reinterpret_cast< const float(*)>(_a[2])),(*reinterpret_cast< const float(*)>(_a[3])),(*reinterpret_cast< const float(*)>(_a[4]))); break;
        case 3: _t->addGyrReading((*reinterpret_cast< const float(*)>(_a[1])),(*reinterpret_cast< const float(*)>(_a[2])),(*reinterpret_cast< const float(*)>(_a[3])),(*reinterpret_cast< const float(*)>(_a[4]))); break;
        case 4: _t->setUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setExperimentName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setExperimentType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setFrequency((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 8: _t->setSpeed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setTimestamp((*reinterpret_cast< const quint64(*)>(_a[1]))); break;
        case 10: { QVector<AccelerometerReading>* _r = _t->getAccReadings();
            if (_a[0]) *reinterpret_cast< QVector<AccelerometerReading>**>(_a[0]) = std::move(_r); }  break;
        case 11: { QVector<GyroscopeReading>* _r = _t->getGyrReadings();
            if (_a[0]) *reinterpret_cast< QVector<GyroscopeReading>**>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->getUser();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->getExperimentName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->getExperimentType();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { uint _r = _t->getFrequency();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->getSpeed();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { qint64 _r = _t->getTimestamp();
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->sendToServer(); break;
        case 19: _t->cancelExperiment(); break;
        case 20: { int _r = _t->getAccReadingsSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: { int _r = _t->getGyrReadingsSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 22: { float _r = _t->getAccTimestampAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 23: { float _r = _t->getAccXAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 24: { float _r = _t->getAccYAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 25: { float _r = _t->getAccZAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 26: { float _r = _t->getGyrTimestampAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 27: { float _r = _t->getGyrXAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 28: { float _r = _t->getGyrYAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 29: { float _r = _t->getGyrZAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->clearVectors(); break;
        case 31: _t->loadFilenames(); break;
        case 32: { QStringList _r = _t->getFilenames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->loadExperiment((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: { float _r = _t->getAccTsMin();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 35: { float _r = _t->getAccTsMax();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 36: { float _r = _t->getAccXMin();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 37: { float _r = _t->getAccXMax();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 38: { float _r = _t->getAccYMin();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 39: { float _r = _t->getAccYMax();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 40: { float _r = _t->getAccZMin();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 41: { float _r = _t->getAccZMax();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 42: { float _r = _t->getGyrTsMin();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 43: { float _r = _t->getGyrTsMax();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 44: { float _r = _t->getGyrXMin();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 45: { float _r = _t->getGyrXMax();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 46: { float _r = _t->getGyrYMin();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 47: { float _r = _t->getGyrYMax();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 48: { float _r = _t->getGyrZMin();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 49: { float _r = _t->getGyrZMax();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 50: { QString _r = _t->getCalculatedData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FitnessExperiment::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FitnessExperiment::loadSelectExperimentPage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FitnessExperiment::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FitnessExperiment::loadAnalysisPage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FitnessExperiment::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FitnessExperiment.data,
    qt_meta_data_FitnessExperiment,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FitnessExperiment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FitnessExperiment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FitnessExperiment.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FitnessExperiment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 51)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 51;
    }
    return _id;
}

// SIGNAL 0
void FitnessExperiment::loadSelectExperimentPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FitnessExperiment::loadAnalysisPage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
