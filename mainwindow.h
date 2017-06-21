#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTimer>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <math.h>
#include <algorithm>

#include "qcustomplot.h"
#include "Definitions.h"
#include "my_maxon_motor.h"
#include "movemotor_thread.h"
#include "LpmsSensorManagerI.h"
#include "LpmsSensorI.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    double radPerSecond2RPM(double radPerSecond);

    ~MainWindow();

signals:
    void sendHeelStrikeTime(double heelStrikeTime);


private slots:
    void on_pushButton_enable_clicked();

    void on_pushButton_disable_clicked();

    void on_actionOpen_triggered();

    void on_actionConnect_All_triggered();

    void on_actionDisconnect_All_triggered();

    void on_pushButton_move_clicked();

    void checkMotorStatus();

    void on_actionCalibration_triggered();

    void on_actionJoint_Angle_Data_triggered();

    void on_actionJoint_Angular_Velocity_Data_triggered();

    void on_pushButton_move_withVelocity_clicked();

    void on_actionLeft_Foot_triggered();

    void on_actionRight_Foot_triggered();

    void checkSensorStatus();
    void updateIMUData();
    void gaitEventDetection(double *gait_time, QVector<double> *leftFootGyro, QVector<double> *rightFootGyro, QVector<double> *leftGaitEvent, QVector<double> *rightGaitEvent);
    void displayAngularVelocityGaitData(QVector<double> *leftHip_angularVelocity, QVector<double> *leftknee_angularVelocity, QVector<double> *rightHip_angularVelocity, QVector<double> *rightKnee_angularVelocity);
    void exoskeletonControl();
    void receiveHeelStrikeEventTime(double heelStrikeEvent);
    void plotGaitPhaseDetectionResult(QVector<double> *leftGaitEvent, QVector<double> *rightGaitEvent, QVector<double> *time);
    void plotGaitCadenceTrackingResult(QVector<double> *gaitCadence, QVector<double> *targetGaitCadence, QVector<double> *gaitTime);
    void recordData_Thread();
    void recordData();

    void on_actionStart_Timer_triggered();

    void on_actionStart_Measurement_triggered();

    void on_actionStop_Measurement_triggered();

    void on_actionwaist_triggered();

    void on_radioButton_walking_clicked();

    void on_radioButton_stairAcent_clicked();

    void on_radioButton_stairDecent_clicked();

    void on_actionNew_Measurement_triggered();

    void on_actionSave_triggered();

    void on_pushButton_threadTest_clicked();

    void on_actionStand_triggered();

    void on_actionSit_triggered();

    void on_pushButton_stopThread_clicked();

    void on_pushButton_moveWithVelocity_clicked();

    void on_actionActivate_Profile_Position_Mode_triggered();

    void on_actionActivate_Profile_Velocity_Mode_triggered();

    void on_actionStand_ver2_triggered();

    void on_actionSit_ver2_triggered();

private:
    Ui::MainWindow *ui;
    double Max_profile_velocity, Max_following_error, Max_acceleration, Max_decceleration;
    my_maxon_motor *motor_left_hip, *motor_right_hip, *motor_left_knee, *motor_right_knee;
    moveMotor_thread *moveMotor;
    QTimer* timer;
    QFile *file;
    bool b_saving_file;
    double leftHipAcceleration, rightHipAcceleration, leftKneeAcceleration, rightKneeAcceleration;
    double leftHipDecceleration, rightHipDecceleration, leftKneeDecceleration, rightKneeDecceleration;
    double leftHipVelocity, rightHipVelocity, leftKneeVelocity, rightKneeVelocity;
    double leftHipPosition, rightHipPosition, leftKneePosition, rightKneePosition;

    struct parametricAngularVelocityModel{
        //stance phase
        double ramp_max, ramp_y;
        double stancePhase_period;

        //swing phase
        double knee_sin_x;
        double knee_sin_y;
        double knee_sin_amp;
        double hip_sin_x;
        double hip_sin_y;
        double hip_sin_amp;
    }walk;
    void lowerLimbAngularVelocityGenerator(QVector<double> *leftHip_angularVelocity, QVector<double> *leftknee_angularVelocity, QVector<double> *rightHip_angularVelocity, QVector<double> *rightKnee_angularVelocity, parametricAngularVelocityModel *angularVelocity_parameter);

    QVector<double> model_time;
    QVector<double> model_mean_left_hip;
    QVector<double> model_mean_right_hip;
    QVector<double> model_mean_left_knee;
    QVector<double> model_mean_right_knee;
    QVector<double> model_std_left_hip;
    QVector<double> model_std_right_hip;
    QVector<double> model_std_left_knee;
    QVector<double> model_std_right_knee;

    QVector<double> angularVelocity_leftHip;
    QVector<double> angularVelocity_leftKnee;
    QVector<double> angularVelocity_rightHip;
    QVector<double> angularVelocity_rightKnee;

    //IMU data member
    ImuData d_leftFoot, d_rightFoot, d_waist;
    LpmsSensorI* lpms_RF;
    LpmsSensorI* lpms_LF;
    LpmsSensorI* lpms_waist;
    LpmsSensorManagerI* manager;
    double gyro_leftFoot[3], gyro_rightFoot[3], gyro_waist[3];
    bool recordOrNot, status_walking, status_stairDecent, status_stairAcent;
    QVector<double> leftFootAngularVelocity;
    QVector<double> rightFootAngularVelocity;
    QVector<double> waist_angle, waist_gyro;
    QVector<double> leftGaitEvent, rightGaitEvent;
    QVector<double> gaitTime;
    QVector<double> heelStrikeTime;
    QVector<double> gaitCadence;
    QVector<double> gaitCadence_target;

};

#endif // MAINWINDOW_H
