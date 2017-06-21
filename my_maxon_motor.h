#ifndef MY_MAXON_MOTOR_H
#define MY_MAXON_MOTOR_H

#include "Definitions.h"
#include "my_maxon_motor.h"
#include <iostream>
#include <string>
#include <vector>
#include <QString>


//Nonzero if successful; otherwise 0
#define OK true
#define NO false


class my_maxon_motor
{
public:
    my_maxon_motor();
    bool openDevice(QString *str_ErrorCode);
    bool closeALLDevice();
    bool init(int node_Id, double MaxProfileVelocity, double MaxFollowingError, double MaxAcceleration);
    bool init_profileVelocityMode(int nodeId, double MaxProfileVelocity, double MaxFollowingError, double MaxAcceleration, double MaxDecceleration);

    void setEnabled(QString *str_ErrorCode);
    void setDisabled(QString *str_ErrorCode);
    bool setPositionProfile(double velocity, double acceleration, double decceleration, QString *str_ErrorCode);
    bool getPositionProfile(double *velocity, double *acceleration, double *decceleration, QString *str_ErrorCode);

    void calibration(long m_HomeOffset, __int8 limitType, QString *str_ErrorCode);
    void WaitForHomingAttained(QString *str_ErrorCode);

    void MoveToPosition(double angle, bool absolute_Pos, QString *str_ErrorCode);
    void MoveToPositionWithVelocity(double angle, double velocity, double acceleration, double decceleration, bool Absolute, QString *str_ErrorCode);

    void MoveWithVelocity(double TargetVelocity, QString *str_ErrorCode);


    double getPosition(QString *str_ErrorCode);
    double getVelocity(QString *str_ErrorCode);
    double getCurrent(QString *str_ErrorCode);
    bool getEnableState(QString *str_ErrorCode);


    int getNodeId(){return this->node_Id;};
    static double Qc2Angle(double qc){return 360.0/(12800*HarmonicDriverRatio)*qc;}
    static double Angle2Qc(double angle){return 12800*HarmonicDriverRatio/360.0*angle;}


private:
    void* keyHandle;
    int node_Id;
    static const int HarmonicDriverRatio = 160;






    //-------------------------------------------------------------------------------------------






    bool GetProtocalInformation(std::vector<std::string>*);





};

#endif // MY_MAXON_MOTOR_H
