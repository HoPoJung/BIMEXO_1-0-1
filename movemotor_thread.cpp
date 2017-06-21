#include "movemotor_thread.h"
#define _USE_MATH_DEFINES
#include <math.h>


moveMotor_thread::moveMotor_thread()
{
    running = true;
    gaitPhase_left = STANCE;
}


//void moveMotor_thread::run()
//{
//    double left_hip_flexion_limit = 120;
//    double left_hip_extension_limit = -10;
//    double right_hip_flexion_limit = 120;
//    double right_hip_extension_limit = -10;
//    double left_knee_flexion_limit  = 120;
//    double right_knee_flexion_limit = 120;
//    double left_knee_extension_limit = 0;
//    double right_knee_extension_limit = 0;

//    QString str_ErrorCode;
////    int stepSize = ui->lineEdit_stepSize->text().toInt()*model_time.size()/100;

//    int step = 0;
//    while(running){
//        if(step > angle_leftHip->size())
//            step = 0;
//        //left: stance phase; right:swing+heel strike
////        motor_leftHip->setPositionProfile(10*80, 1000, 1000, &str_ErrorCode);
////        motor_leftKnee->setPositionProfile(10*80, 1000, 1000, &str_ErrorCode);
////        motor_rightHip->setPositionProfile(20*80, 1000, 1000, &str_ErrorCode);
////        motor_rightKnee->setPositionProfile(20*80, 1000, 1000, &str_ErrorCode);
//        for(step = 8000; step < 9999; step+=90){
//            if(!running)
//                break;
////            if(gaitPhase_left == HEEL_OFF)
////                break;
////            if(step >= angle_leftHip->size())
////                step = 0;
//            if(motor_leftHip->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_leftHip->at(step) > left_hip_flexion_limit-5){
//                    target_position = left_hip_flexion_limit-5;
//                }else if(angle_leftHip->at(step) < left_hip_extension_limit+5){
//                    target_position = left_hip_extension_limit+5;
//                }else{
//                    target_position = angle_leftHip->at(step);
//                }
//                target_position *= -1.0; //if this is left
////                motor_leftHip->MoveToPosition(target_position ,true, &str_ErrorCode);
//                motor_leftHip->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_leftHip->at(step)))*4, 2000, 2000, true, &str_ErrorCode);

//            }

//            else{
//                qDebug() << "motor_leftHip FAIL!!!!!";
//            }

//            if(motor_rightHip->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_rightHip->at(step) > right_hip_flexion_limit-5){
//                    target_position = right_hip_flexion_limit-5;
//                }else if(angle_rightHip->at(step) < right_hip_extension_limit+5){
//                    target_position = right_hip_extension_limit+5;
//                }else{
//                    target_position = angle_rightHip->at(step);
//                }
////                motor_rightHip->MoveToPosition(target_position ,true, &str_ErrorCode);}
//                motor_rightHip->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_rightHip->at(step)))*4, 2000, 2000, true, &str_ErrorCode);}

//            else{
//                qDebug() <<"motor_rightHip FAIL!!!!!";
//            }

//            if(motor_leftKnee->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_leftKnee->at(step) > left_knee_flexion_limit-5){
//                    target_position = left_knee_flexion_limit-5;
//                }else if(angle_leftKnee->at(step) < left_knee_extension_limit+5){
//                    target_position = left_knee_extension_limit+5;
//                }else{
//                    target_position = angle_leftKnee->at(step);
//                }
//                target_position *= -1.0; //if this is left
////                motor_leftKnee->MoveToPosition(target_position,true, &str_ErrorCode);}
//                motor_leftKnee->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_leftKnee->at(step)))*4, 2000, 2000, true, &str_ErrorCode);}

//            else{
//                qDebug() << "motor_leftKnee FAIL!!!!!";
//            }

//            if(motor_rightKnee->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_rightKnee->at(step) > right_knee_flexion_limit-5){
//                    target_position = right_knee_flexion_limit-5;
//                }else if(angle_rightKnee->at(step) < right_knee_extension_limit+5){
//                    target_position = right_knee_extension_limit+5;
//                }else{
//                    target_position = angle_rightKnee->at(step);
//                }
////                motor_rightKnee->MoveToPosition(target_position, true, &str_ErrorCode);}
//                motor_rightKnee->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_rightKnee->at(step)))*4, 2000, 2000, true, &str_ErrorCode);}

//            else{
//                qDebug() << "motor_rightKnee FAIL!!!!!";
//            }

//            //qDebug() << "step = " << QString::number(step);
//                        Sleep(30);
//        }
//        //left: heel off + toe off; right:stance phase
////        motor_leftHip->setPositionProfile(40*80, 1000, 1000, &str_ErrorCode);
////        motor_leftKnee->setPositionProfile(40*80, 1000, 1000, &str_ErrorCode);
////        motor_rightHip->setPositionProfile(10*80, 1000, 1000, &str_ErrorCode);
////        motor_rightKnee->setPositionProfile(10*80, 1000, 1000, &str_ErrorCode);
//        for(step = 0; step < 3000; step+=90){
//            if(!running)
//                break;
////            if(gaitPhase_left == SWING)
////                break;
////            if(step >= angle_leftHip->size())
////                step = 0;
//            if(motor_leftHip->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_leftHip->at(step) > left_hip_flexion_limit-5){
//                    target_position = left_hip_flexion_limit-5;
//                }else if(angle_leftHip->at(step) < left_hip_extension_limit+5){
//                    target_position = left_hip_extension_limit+5;
//                }else{
//                    target_position = angle_leftHip->at(step);
//                }
//                target_position *= -1.0; //if this is left
////                motor_leftHip->MoveToPosition(target_position ,true, &str_ErrorCode);
//                motor_leftHip->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_rightHip->at(step)))*4, 2000, 2000, true, &str_ErrorCode);

//            }

//            else{
//                qDebug() << "motor_leftHip FAIL!!!!!";
//            }

//            if(motor_rightHip->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_rightHip->at(step) > right_hip_flexion_limit-5){
//                    target_position = right_hip_flexion_limit-5;
//                }else if(angle_rightHip->at(step) < right_hip_extension_limit+5){
//                    target_position = right_hip_extension_limit+5;
//                }else{
//                    target_position = angle_rightHip->at(step);
//                }
////                motor_rightHip->MoveToPosition(target_position ,true, &str_ErrorCode);}
//                motor_rightHip->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_rightHip->at(step)))*4, 2000, 2000, true, &str_ErrorCode);}

//            else{
//                qDebug() <<"motor_rightHip FAIL!!!!!";
//            }

//            if(motor_leftKnee->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_leftKnee->at(step) > left_knee_flexion_limit-5){
//                    target_position = left_knee_flexion_limit-5;
//                }else if(angle_leftKnee->at(step) < left_knee_extension_limit+5){
//                    target_position = left_knee_extension_limit+5;
//                }else{
//                    target_position = angle_leftKnee->at(step);
//                }
//                target_position *= -1.0; //if this is left
////                motor_leftKnee->MoveToPosition(target_position,true, &str_ErrorCode);}
//                motor_leftKnee->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_leftKnee->at(step)))*4, 2000, 2000, true, &str_ErrorCode);}

//            else{
//                qDebug() << "motor_leftKnee FAIL!!!!!";
//            }

//            if(motor_rightKnee->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_rightKnee->at(step) > right_knee_flexion_limit-5){
//                    target_position = right_knee_flexion_limit-5;
//                }else if(angle_rightKnee->at(step) < right_knee_extension_limit+5){
//                    target_position = right_knee_extension_limit+5;
//                }else{
//                    target_position = angle_rightKnee->at(step);
//                }
////                motor_rightKnee->MoveToPosition(target_position, true, &str_ErrorCode);}
//                motor_rightKnee->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_rightKnee->at(step)))*4, 2000, 2000, true, &str_ErrorCode);}


//            else{
//                qDebug() << "motor_rightKnee FAIL!!!!!";
//            }

//            //qDebug() << "step = " << QString::number(step);
//                        Sleep(30);
//        }
//        //left: swing + heel strike; right: heel of + toe off
////        motor_leftHip->setPositionProfile(20*80, 1000, 1000, &str_ErrorCode);
////        motor_leftKnee->setPositionProfile(20*80, 1000, 1000, &str_ErrorCode);
////        motor_rightHip->setPositionProfile(40*80, 1000, 1000, &str_ErrorCode);
////        motor_rightKnee->setPositionProfile(40*80, 1000, 1000, &str_ErrorCode);
//        for(step = 3001; step < 7999; step+=90){
//            if(!running)
//                break;
////            if(gaitPhase_left == STANCE)
////                break;
////            if(step >= angle_leftHip->size())
////                step = 0;
//            if(motor_leftHip->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_leftHip->at(step) > left_hip_flexion_limit-5){
//                    target_position = left_hip_flexion_limit-5;
//                }else if(angle_leftHip->at(step) < left_hip_extension_limit+5){
//                    target_position = left_hip_extension_limit+5;
//                }else{
//                    target_position = angle_leftHip->at(step);
//                }
//                target_position *= -1.0; //if this is left
////                motor_leftHip->MoveToPosition(target_position ,true, &str_ErrorCode);
//                motor_leftHip->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_rightHip->at(step)))*4, 2000, 2000, true, &str_ErrorCode);

//            }

//            else{
//                qDebug() << "motor_leftHip FAIL!!!!!";
//            }

//            if(motor_rightHip->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_rightHip->at(step) > right_hip_flexion_limit-5){
//                    target_position = right_hip_flexion_limit-5;
//                }else if(angle_rightHip->at(step) < right_hip_extension_limit+5){
//                    target_position = right_hip_extension_limit+5;
//                }else{
//                    target_position = angle_rightHip->at(step);
//                }
////                motor_rightip->MoveToPosition(target_position ,true, &str_ErrorCode);}
//                motor_rightHip->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_rightHip->at(step)))*4, 2000, 2000, true, &str_ErrorCode);}


//            else{
//                qDebug() <<"motor_rightHip FAIL!!!!!";
//            }

//            if(motor_leftKnee->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_leftKnee->at(step) > left_knee_flexion_limit-5){
//                    target_position = left_knee_flexion_limit-5;
//                }else if(angle_leftKnee->at(step) < left_knee_extension_limit+5){
//                    target_position = left_knee_extension_limit+5;
//                }else{
//                    target_position = angle_leftKnee->at(step);
//                }
//                target_position *= -1.0; //if this is left
////                motor_leftKnee->MoveToPosition(target_position,true, &str_ErrorCode);}
//                motor_leftKnee->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_leftKnee->at(step)))*4, 2000, 2000, true, &str_ErrorCode);}

//                else{
//                qDebug() << "motor_leftKnee FAIL!!!!!";
//            }

//            if(motor_rightKnee->getEnableState(&str_ErrorCode)){
//                double target_position;
//                if(angle_rightKnee->at(step) > right_knee_flexion_limit-5){
//                    target_position = right_knee_flexion_limit-5;
//                }else if(angle_rightKnee->at(step) < right_knee_extension_limit+5){
//                    target_position = right_knee_extension_limit+5;
//                }else{
//                    target_position = angle_rightKnee->at(step);
//                }
////                motor_rightKnee->MoveToPosition(target_position, true, &str_ErrorCode);}
//                motor_rightKnee->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_rightKnee->at(step)))*4, 2000, 2000, true, &str_ErrorCode);}


//            else{
//                qDebug() << "motor_rightKnee FAIL!!!!!";
//            }

//            //qDebug() << "step = " << QString::number(step);
//                        Sleep(30);
//        }

//    }
//}

void moveMotor_thread::run(){
    checkAngleLimitation(angle_leftHip, angle_leftKnee, angle_rightHip, angle_rightKnee);

    QString str_ErrorCode;

    int step = 0;
    while(running){
        if(step > angle_leftHip->size())
            step = 0;
        //left: stance phase; right:swing+heel strike
        for(step = 8000; step < 9999; step+=90){
            if(!running)
                break;
            if(step%500 == 0){
                motor_leftHip->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_leftHip->at(step)))*5, 2000, 2000, &str_ErrorCode);
                motor_leftKnee->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_leftKnee->at(step)))*5, 2000, 2000, &str_ErrorCode);
            }
            if(motor_leftHip->getEnableState(&str_ErrorCode)){
                motor_leftHip->MoveToPosition(-angle_leftHip->at(step) ,true, &str_ErrorCode);
            }
            else{
                qDebug() << "motor_leftHip FAIL!!!!!";
            }
            if(motor_leftKnee->getEnableState(&str_ErrorCode)){
                motor_leftKnee->MoveToPosition(-angle_leftKnee->at(step),true, &str_ErrorCode);}
            else{
                qDebug() << "motor_leftKnee FAIL!!!!!";
            }
            Sleep(50);
        }
        for(step = 8000; step < 9999; step+=90){
            if(!running)
                break;
            if(step%500 == 0){
                motor_rightHip->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_rightHip->at(step)))*5, 2000, 2000, &str_ErrorCode);
                motor_rightKnee->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_leftKnee->at(step)))*5, 2000, 2000, &str_ErrorCode);
            }
            if(motor_rightHip->getEnableState(&str_ErrorCode)){
                motor_rightHip->MoveToPosition(angle_rightHip->at(step) ,true, &str_ErrorCode);}
            else{
                qDebug() <<"motor_rightHip FAIL!!!!!";
            }
            if(motor_rightKnee->getEnableState(&str_ErrorCode)){
                motor_rightKnee->MoveToPosition(angle_rightKnee->at(step), true, &str_ErrorCode);}
            else{
                qDebug() << "motor_rightKnee FAIL!!!!!";
            }
            Sleep(30);
        }
        //left: heel off + toe off; right:stance phase
        for(step = 0; step < 3000; step+=90){
            if(!running)
                break;
            if(step%500 == 0){
                motor_leftHip->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_leftHip->at(step)))*5, 2000, 2000, &str_ErrorCode);
                motor_leftKnee->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_leftKnee->at(step)))*5, 2000, 2000, &str_ErrorCode);
            }
            if(motor_leftHip->getEnableState(&str_ErrorCode)){
                motor_leftHip->MoveToPosition(-angle_leftHip->at(step) ,true, &str_ErrorCode);
            }
            else{
                qDebug() << "motor_leftHip FAIL!!!!!";
            }
            if(motor_leftKnee->getEnableState(&str_ErrorCode)){
                motor_leftKnee->MoveToPosition(-angle_leftKnee->at(step),true, &str_ErrorCode);}
            else{
                qDebug() << "motor_leftKnee FAIL!!!!!";
            }

            Sleep(30);
        }
        for(step = 0; step < 3000; step+=90){
            if(!running)
                break;
            if(step%500 == 0){
                motor_rightHip->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_rightHip->at(step)))*5, 2000, 2000, &str_ErrorCode);
                motor_rightKnee->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_leftKnee->at(step)))*5, 2000, 2000, &str_ErrorCode);
            }
            if(motor_rightHip->getEnableState(&str_ErrorCode)){
                motor_rightHip->MoveToPosition(angle_rightHip->at(step) ,true, &str_ErrorCode);}
            else{
                qDebug() <<"motor_rightHip FAIL!!!!!";
            }
            if(motor_rightKnee->getEnableState(&str_ErrorCode)){
                motor_rightKnee->MoveToPosition(angle_rightKnee->at(step), true, &str_ErrorCode);}
            else{
                qDebug() << "motor_rightKnee FAIL!!!!!";
            }
            Sleep(50);
        }
        //left: swing + heel strike; right: heel of + toe off
        for(step = 3001; step < 7999; step+=90){
            if(!running)
                break;
            if(step%500 == 0){
                motor_leftHip->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_leftHip->at(step)))*5, 2000, 2000, &str_ErrorCode);
                motor_leftKnee->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_leftKnee->at(step)))*5, 2000, 2000, &str_ErrorCode);
            }
            if(motor_leftHip->getEnableState(&str_ErrorCode)){
                motor_leftHip->MoveToPosition(-angle_leftHip->at(step),true, &str_ErrorCode);
            }

            else{
                qDebug() << "motor_leftHip FAIL!!!!!";
            }
            if(motor_leftKnee->getEnableState(&str_ErrorCode)){
                motor_leftKnee->MoveToPosition(-angle_leftKnee->at(step),true, &str_ErrorCode);}
            else{
                qDebug() << "motor_leftKnee FAIL!!!!!";
            }
            Sleep(30);
        }
        for(step = 3001; step < 7999; step+=90){
            if(!running)
                break;
            if(step%500 == 0){
                motor_rightHip->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_rightHip->at(step)))*5, 2000, 2000, &str_ErrorCode);
                motor_rightKnee->setPositionProfile(abs(radPerSecond2RPM(angularVelocity_rightKnee->at(step)))*5, 2000, 2000, &str_ErrorCode);
            }
            if(motor_rightHip->getEnableState(&str_ErrorCode)){
                motor_rightHip->MoveToPosition(angle_rightHip->at(step),true, &str_ErrorCode);}
            else{
                qDebug() <<"motor_rightHip FAIL!!!!!";
            }
            if(motor_rightKnee->getEnableState(&str_ErrorCode)){
                motor_rightKnee->MoveToPosition(angle_rightKnee->at(step), true, &str_ErrorCode);
            }
            else{
                qDebug() << "motor_rightKnee FAIL!!!!!";
            }
            Sleep(30);
        }

    }
}

double moveMotor_thread::radPerSecond2RPM(double radPerSecond)
{
    return radPerSecond*60/(2*M_PI);

}

void moveMotor_thread::checkAngleLimitation(QVector<double> *leftHip, QVector<double> *leftKnee, QVector<double> *rightHip, QVector<double> *rightKnee)
{
    double left_hip_flexion_limit = 120;
    double left_hip_extension_limit = -10;
    double right_hip_flexion_limit = 120;
    double right_hip_extension_limit = -10;
    double left_knee_flexion_limit  = 120;
    double right_knee_flexion_limit = 120;
    double left_knee_extension_limit = 0;
    double right_knee_extension_limit = 0;

    double *data_leftHip = leftHip->data();
    double *data_leftKnee = leftKnee->data();
    double *data_rightHip = rightHip->data();
    double *data_rightKnee = rightKnee->data();

    for(int i = 0; i < leftHip->size(); i++){
        if(leftHip->at(i) > left_hip_flexion_limit-5){
            data_leftHip[i] = left_hip_flexion_limit-5;
        }else if(leftHip->at(i) < left_hip_extension_limit+5){
            data_leftHip[i] = left_hip_extension_limit+5;
        }else{
            data_leftHip[i] = leftHip->at(i);
        }

        if(leftKnee->at(i) > left_knee_flexion_limit-5){
            data_leftKnee[i] = left_knee_flexion_limit-5;
        }else if(leftKnee->at(i) < left_knee_extension_limit+5){
            data_leftKnee[i] = left_knee_extension_limit+5;
        }else{
            data_leftKnee[i] = leftKnee->at(i);
        }

        if(rightHip->at(i) > right_hip_flexion_limit-5){
            data_rightHip[i] = right_hip_flexion_limit-5;
        }else if(rightHip->at(i) < right_hip_extension_limit+5){
            data_rightHip[i] = right_hip_extension_limit+5;
        }else{
            data_rightHip[i] = rightHip->at(i);
        }

        if(rightKnee->at(i) > right_knee_flexion_limit-5){
            data_rightKnee[i] = right_knee_flexion_limit-5;
        }else if(rightKnee->at(i) < right_knee_extension_limit+5){
            data_rightKnee[i] = right_knee_extension_limit+5;
        }else{
            data_rightKnee[i] = rightKnee->at(i);
        }
    }
}
