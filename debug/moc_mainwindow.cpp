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
    QByteArrayData data[61];
    char stringdata0[1517];
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
QT_MOC_LITERAL(25, 564, 13), // "leftGaitEvent"
QT_MOC_LITERAL(26, 578, 14), // "rightGaitEvent"
QT_MOC_LITERAL(27, 593, 30), // "displayAngularVelocityGaitData"
QT_MOC_LITERAL(28, 624, 23), // "leftHip_angularVelocity"
QT_MOC_LITERAL(29, 648, 24), // "leftknee_angularVelocity"
QT_MOC_LITERAL(30, 673, 24), // "rightHip_angularVelocity"
QT_MOC_LITERAL(31, 698, 25), // "rightKnee_angularVelocity"
QT_MOC_LITERAL(32, 724, 18), // "exoskeletonControl"
QT_MOC_LITERAL(33, 743, 26), // "receiveHeelStrikeEventTime"
QT_MOC_LITERAL(34, 770, 15), // "heelStrikeEvent"
QT_MOC_LITERAL(35, 786, 28), // "plotGaitPhaseDetectionResult"
QT_MOC_LITERAL(36, 815, 4), // "time"
QT_MOC_LITERAL(37, 820, 29), // "plotGaitCadenceTrackingResult"
QT_MOC_LITERAL(38, 850, 11), // "gaitCadence"
QT_MOC_LITERAL(39, 862, 17), // "targetGaitCadence"
QT_MOC_LITERAL(40, 880, 8), // "gaitTime"
QT_MOC_LITERAL(41, 889, 17), // "recordData_Thread"
QT_MOC_LITERAL(42, 907, 10), // "recordData"
QT_MOC_LITERAL(43, 918, 30), // "on_actionStart_Timer_triggered"
QT_MOC_LITERAL(44, 949, 36), // "on_actionStart_Measurement_tr..."
QT_MOC_LITERAL(45, 986, 35), // "on_actionStop_Measurement_tri..."
QT_MOC_LITERAL(46, 1022, 24), // "on_actionwaist_triggered"
QT_MOC_LITERAL(47, 1047, 30), // "on_radioButton_walking_clicked"
QT_MOC_LITERAL(48, 1078, 33), // "on_radioButton_stairAcent_cli..."
QT_MOC_LITERAL(49, 1112, 34), // "on_radioButton_stairDecent_cl..."
QT_MOC_LITERAL(50, 1147, 34), // "on_actionNew_Measurement_trig..."
QT_MOC_LITERAL(51, 1182, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(52, 1206, 32), // "on_pushButton_threadTest_clicked"
QT_MOC_LITERAL(53, 1239, 24), // "on_actionStand_triggered"
QT_MOC_LITERAL(54, 1264, 22), // "on_actionSit_triggered"
QT_MOC_LITERAL(55, 1287, 32), // "on_pushButton_stopThread_clicked"
QT_MOC_LITERAL(56, 1320, 38), // "on_pushButton_moveWithVelocit..."
QT_MOC_LITERAL(57, 1359, 49), // "on_actionActivate_Profile_Pos..."
QT_MOC_LITERAL(58, 1409, 49), // "on_actionActivate_Profile_Vel..."
QT_MOC_LITERAL(59, 1459, 29), // "on_actionStand_ver2_triggered"
QT_MOC_LITERAL(60, 1489, 27) // "on_actionSit_ver2_triggered"

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
    "rightFootGyro\0leftGaitEvent\0rightGaitEvent\0"
    "displayAngularVelocityGaitData\0"
    "leftHip_angularVelocity\0"
    "leftknee_angularVelocity\0"
    "rightHip_angularVelocity\0"
    "rightKnee_angularVelocity\0exoskeletonControl\0"
    "receiveHeelStrikeEventTime\0heelStrikeEvent\0"
    "plotGaitPhaseDetectionResult\0time\0"
    "plotGaitCadenceTrackingResult\0gaitCadence\0"
    "targetGaitCadence\0gaitTime\0recordData_Thread\0"
    "recordData\0on_actionStart_Timer_triggered\0"
    "on_actionStart_Measurement_triggered\0"
    "on_actionStop_Measurement_triggered\0"
    "on_actionwaist_triggered\0"
    "on_radioButton_walking_clicked\0"
    "on_radioButton_stairAcent_clicked\0"
    "on_radioButton_stairDecent_clicked\0"
    "on_actionNew_Measurement_triggered\0"
    "on_actionSave_triggered\0"
    "on_pushButton_threadTest_clicked\0"
    "on_actionStand_triggered\0"
    "on_actionSit_triggered\0"
    "on_pushButton_stopThread_clicked\0"
    "on_pushButton_moveWithVelocity_clicked\0"
    "on_actionActivate_Profile_Position_Mode_triggered\0"
    "on_actionActivate_Profile_Velocity_Mode_triggered\0"
    "on_actionStand_ver2_triggered\0"
    "on_actionSit_ver2_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  224,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  227,    2, 0x08 /* Private */,
       5,    0,  228,    2, 0x08 /* Private */,
       6,    0,  229,    2, 0x08 /* Private */,
       7,    0,  230,    2, 0x08 /* Private */,
       8,    0,  231,    2, 0x08 /* Private */,
       9,    0,  232,    2, 0x08 /* Private */,
      10,    0,  233,    2, 0x08 /* Private */,
      11,    0,  234,    2, 0x08 /* Private */,
      12,    0,  235,    2, 0x08 /* Private */,
      13,    0,  236,    2, 0x08 /* Private */,
      14,    0,  237,    2, 0x08 /* Private */,
      15,    0,  238,    2, 0x08 /* Private */,
      16,    0,  239,    2, 0x08 /* Private */,
      17,    0,  240,    2, 0x08 /* Private */,
      18,    0,  241,    2, 0x08 /* Private */,
      19,    5,  242,    2, 0x08 /* Private */,
      27,    4,  253,    2, 0x08 /* Private */,
      32,    0,  262,    2, 0x08 /* Private */,
      33,    1,  263,    2, 0x08 /* Private */,
      35,    3,  266,    2, 0x08 /* Private */,
      37,    3,  273,    2, 0x08 /* Private */,
      41,    0,  280,    2, 0x08 /* Private */,
      42,    0,  281,    2, 0x08 /* Private */,
      43,    0,  282,    2, 0x08 /* Private */,
      44,    0,  283,    2, 0x08 /* Private */,
      45,    0,  284,    2, 0x08 /* Private */,
      46,    0,  285,    2, 0x08 /* Private */,
      47,    0,  286,    2, 0x08 /* Private */,
      48,    0,  287,    2, 0x08 /* Private */,
      49,    0,  288,    2, 0x08 /* Private */,
      50,    0,  289,    2, 0x08 /* Private */,
      51,    0,  290,    2, 0x08 /* Private */,
      52,    0,  291,    2, 0x08 /* Private */,
      53,    0,  292,    2, 0x08 /* Private */,
      54,    0,  293,    2, 0x08 /* Private */,
      55,    0,  294,    2, 0x08 /* Private */,
      56,    0,  295,    2, 0x08 /* Private */,
      57,    0,  296,    2, 0x08 /* Private */,
      58,    0,  297,    2, 0x08 /* Private */,
      59,    0,  298,    2, 0x08 /* Private */,
      60,    0,  299,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22,   21,   23,   24,   25,   26,
    QMetaType::Void, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22,   28,   29,   30,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   34,
    QMetaType::Void, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22,   25,   26,   36,
    QMetaType::Void, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22,   38,   39,   40,
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
    QMetaType::Void,
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
        case 16: _t->gaitEventDetection((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< QVector<double>*(*)>(_a[2])),(*reinterpret_cast< QVector<double>*(*)>(_a[3])),(*reinterpret_cast< QVector<double>*(*)>(_a[4])),(*reinterpret_cast< QVector<double>*(*)>(_a[5]))); break;
        case 17: _t->displayAngularVelocityGaitData((*reinterpret_cast< QVector<double>*(*)>(_a[1])),(*reinterpret_cast< QVector<double>*(*)>(_a[2])),(*reinterpret_cast< QVector<double>*(*)>(_a[3])),(*reinterpret_cast< QVector<double>*(*)>(_a[4]))); break;
        case 18: _t->exoskeletonControl(); break;
        case 19: _t->receiveHeelStrikeEventTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->plotGaitPhaseDetectionResult((*reinterpret_cast< QVector<double>*(*)>(_a[1])),(*reinterpret_cast< QVector<double>*(*)>(_a[2])),(*reinterpret_cast< QVector<double>*(*)>(_a[3]))); break;
        case 21: _t->plotGaitCadenceTrackingResult((*reinterpret_cast< QVector<double>*(*)>(_a[1])),(*reinterpret_cast< QVector<double>*(*)>(_a[2])),(*reinterpret_cast< QVector<double>*(*)>(_a[3]))); break;
        case 22: _t->recordData_Thread(); break;
        case 23: _t->recordData(); break;
        case 24: _t->on_actionStart_Timer_triggered(); break;
        case 25: _t->on_actionStart_Measurement_triggered(); break;
        case 26: _t->on_actionStop_Measurement_triggered(); break;
        case 27: _t->on_actionwaist_triggered(); break;
        case 28: _t->on_radioButton_walking_clicked(); break;
        case 29: _t->on_radioButton_stairAcent_clicked(); break;
        case 30: _t->on_radioButton_stairDecent_clicked(); break;
        case 31: _t->on_actionNew_Measurement_triggered(); break;
        case 32: _t->on_actionSave_triggered(); break;
        case 33: _t->on_pushButton_threadTest_clicked(); break;
        case 34: _t->on_actionStand_triggered(); break;
        case 35: _t->on_actionSit_triggered(); break;
        case 36: _t->on_pushButton_stopThread_clicked(); break;
        case 37: _t->on_pushButton_moveWithVelocity_clicked(); break;
        case 38: _t->on_actionActivate_Profile_Position_Mode_triggered(); break;
        case 39: _t->on_actionActivate_Profile_Velocity_Mode_triggered(); break;
        case 40: _t->on_actionStand_ver2_triggered(); break;
        case 41: _t->on_actionSit_ver2_triggered(); break;
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
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 42;
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
