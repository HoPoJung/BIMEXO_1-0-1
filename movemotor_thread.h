#ifndef MOVEMOTOR_THREAD_H
#define MOVEMOTOR_THREAD_H

#include <QThread>
#include <QVector>
#include <QDebug>
#include "my_maxon_motor.h"

#define STANCE 1
#define HEEL_OFF 2
#define SWING 4


class moveMotor_thread : public QThread
{
    Q_OBJECT
public:
    moveMotor_thread();

    void run();
    double radPerSecond2RPM(double radPerSecond);
    void checkAngleLimitation(QVector<double> *Hip, QVector<double> *leftKnee, QVector<double> *rightHip, QVector<double> *rightKnee);
    my_maxon_motor *motor_leftHip, *motor_rightHip, *motor_leftKnee, *motor_rightKnee;
    QVector<double> *angle_leftHip, *angle_rightHip, *angle_leftKnee, *angle_rightKnee;
    QVector<double> *angularVelocity_leftHip, *angularVelocity_rightHip, *angularVelocity_leftKnee, *angularVelocity_rightKnee;
    double IMU_waist, IMU_waist_gyro;
    int gaitPhase_left;
    bool running;
private:


};

#endif // MOVEMOTOR_THREAD_H
