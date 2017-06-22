/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[40];
    char stringdata0[929];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "sendHeelStrikeTime"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "heelStrikeTime"
QT_MOC_LITERAL(4, 46, 28), // "on_pushButton_enable_clicked"
QT_MOC_LITERAL(5, 75, 29), // "on_pushButton_disable_clicked"
QT_MOC_LITERAL(6, 105, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(7, 129, 30), // "on_actionConnect_All_triggered"
QT_MOC_LITERAL(8, 160, 33), // "on_actionDisconnect_All_trigg..."
QT_MOC_LITERAL(9, 194, 26), // "on_pushButton_move_clicked"
QT_MOC_LITERAL(10, 221, 16), // "checkMotorStatus"
QT_MOC_LITERAL(11, 238, 30), // "on_actionCalibration_triggered"
QT_MOC_LITERAL(12, 269, 35), // "on_actionJoint_Angle_Data_tri..."
QT_MOC_LITERAL(13, 305, 46), // "on_actionJoint_Angular_Veloci..."
QT_MOC_LITERAL(14, 352, 39), // "on_pushButton_move_withVeloci..."
QT_MOC_LITERAL(15, 392, 28), // "on_actionLeft_Foot_triggered"
QT_MOC_LITERAL(16, 421, 29), // "on_actionRight_Foot_triggered"
QT_MOC_LITERAL(17, 451, 17), // "checkSensorStatus"
QT_MOC_LITERAL(18, 469, 13), // "updateIMUData"
QT_MOC_LITERAL(19, 483, 18), // "gaitEventDetection"
QT_MOC_LITERAL(20, 502, 7), // "double*"
QT_MOC_LITERAL(21, 510, 9), // "gait_time"
QT_MOC_LITERAL(22, 520, 16), // "QVector<double>*"
QT_MOC_LITERAL(23, 537, 12), // "leftFootGyro"
QT_MOC_LITERAL(24, 550, 13), // "rightFootGyro"
QT_MOC_LITERAL(25, 564, 13), // "QVector<int>*"
QT_MOC_LITERAL(26, 578, 13), // "leftGaitEvent"
QT_MOC_LITERAL(27, 592, 14), // "rightGaitEvent"
QT_MOC_LITERAL(28, 607, 30), // "displayAngularVelocityGaitData"
QT_MOC_LITERAL(29, 638, 23), // "leftHip_angularVelocity"
QT_MOC_LITERAL(30, 662, 24), // "leftknee_angularVelocity"
QT_MOC_LITERAL(31, 687, 24), // "rightHip_angularVelocity"
QT_MOC_LITERAL(32, 712, 25), // "rightKnee_angularVelocity"
QT_MOC_LITERAL(33, 738, 18), // "exoskeletonControl"
QT_MOC_LITERAL(34, 757, 26), // "receiveHeelStrikeEventTime"
QT_MOC_LITERAL(35, 784, 15), // "heelStrikeEvent"
QT_MOC_LITERAL(36, 800, 30), // "on_actionStart_Timer_triggered"
QT_MOC_LITERAL(37, 831, 36), // "on_actionStart_Measurement_tr..."
QT_MOC_LITERAL(38, 868, 35), // "on_actionStop_Measurement_tri..."
QT_MOC_LITERAL(39, 904, 24) // "on_actionwaist_triggered"

    },
    "MainWindow\0sendHeelStrikeTime\0\0"
    "heelStrikeTime\0on_pushButton_enable_clicked\0"
    "on_pushButton_disable_clicked\0"
    "on_actionOpen_triggered\0"
    "on_actionConnect_All_triggered\0"
    "on_actionDisconnect_All_triggered\0"
    "on_pushButton_move_clicked\0checkMotorStatus\0"
    "on_actionCalibration_triggered\0"
    "on_actionJoint_Angle_Data_triggered\0"
    "on_actionJoint_Angular_Velocity_Data_triggered\0"
    "on_pushButton_move_withVelocity_clicked\0"
    "on_actionLeft_Foot_triggered\0"
    "on_actionRight_Foot_triggered\0"
    "checkSensorStatus\0updateIMUData\0"
    "gaitEventDetection\0double*\0gait_time\0"
    "QVector<double>*\0leftFootGyro\0"
    "rightFootGyro\0QVector<int>*\0leftGaitEvent\0"
    "rightGaitEvent\0displayAngularVelocityGaitData\0"
    "leftHip_angularVelocity\0"
    "leftknee_angularVelocity\0"
    "rightHip_angularVelocity\0"
    "rightKnee_angularVelocity\0exoskeletonControl\0"
    "receiveHeelStrikeEventTime\0heelStrikeEvent\0"
    "on_actionStart_Timer_triggered\0"
    "on_actionStart_Measurement_triggered\0"
    "on_actionStop_Measurement_triggered\0"
    "on_actionwaist_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  137,    2, 0x08 /* Private */,
       5,    0,  138,    2, 0x08 /* Private */,
       6,    0,  139,    2, 0x08 /* Private */,
       7,    0,  140,    2, 0x08 /* Private */,
       8,    0,  141,    2, 0x08 /* Private */,
       9,    0,  142,    2, 0x08 /* Private */,
      10,    0,  143,    2, 0x08 /* Private */,
      11,    0,  144,    2, 0x08 /* Private */,
      12,    0,  145,    2, 0x08 /* Private */,
      13,    0,  146,    2, 0x08 /* Private */,
      14,    0,  147,    2, 0x08 /* Private */,
      15,    0,  148,    2, 0x08 /* Private */,
      16,    0,  149,    2, 0x08 /* Private */,
      17,    0,  150,    2, 0x08 /* Private */,
      18,    0,  151,    2, 0x08 /* Private */,
      19,    5,  152,    2, 0x08 /* Private */,
      28,    4,  163,    2, 0x08 /* Private */,
      33,    0,  172,    2, 0x08 /* Private */,
      34,    1,  173,    2, 0x08 /* Private */,
      36,    0,  176,    2, 0x08 /* Private */,
      37,    0,  177,    2, 0x08 /* Private */,
      38,    0,  178,    2, 0x08 /* Private */,
      39,    0,  179,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 25, 0x80000000 | 25,   21,   23,   24,   26,   27,
    QMetaType::Void, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22,   29,   30,   31,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendHeelStrikeTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_enable_clicked(); break;
        case 2: _t->on_pushButton_disable_clicked(); break;
        case 3: _t->on_actionOpen_triggered(); break;
        case 4: _t->on_actionConnect_All_triggered(); break;
        case 5: _t->on_actionDisconnect_All_triggered(); break;
        case 6: _t->on_pushButton_move_clicked(); break;
        case 7: _t->checkMotorStatus(); break;
        case 8: _t->on_actionCalibration_triggered(); break;
        case 9: _t->on_actionJoint_Angle_Data_triggered(); break;
        case 10: _t->on_actionJoint_Angular_Velocity_Data_triggered(); break;
        case 11: _t->on_pushButton_move_withVelocity_clicked(); break;
        case 12: _t->on_actionLeft_Foot_triggered(); break;
        case 13: _t->on_actionRight_Foot_triggered(); break;
        case 14: _t->checkSensorStatus(); break;
        case 15: _t->updateIMUData(); break;
        case 16: _t->gaitEventDetection((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< QVector<double>*(*)>(_a[2])),(*reinterpret_cast< QVector<double>*(*)>(_a[3])),(*reinterpret_cast< QVector<int>*(*)>(_a[4])),(*reinterpret_cast< QVector<int>*(*)>(_a[5]))); break;
        case 17: _t->displayAngularVelocityGaitData((*reinterpret_cast< QVector<double>*(*)>(_a[1])),(*reinterpret_cast< QVector<double>*(*)>(_a[2])),(*reinterpret_cast< QVector<double>*(*)>(_a[3])),(*reinterpret_cast< QVector<double>*(*)>(_a[4]))); break;
        case 18: _t->exoskeletonControl(); break;
        case 19: _t->receiveHeelStrikeEventTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->on_actionStart_Timer_triggered(); break;
        case 21: _t->on_actionStart_Measurement_triggered(); break;
        case 22: _t->on_actionStop_Measurement_triggered(); break;
        case 23: _t->on_actionwaist_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendHeelStrikeTime)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendHeelStrikeTime(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
