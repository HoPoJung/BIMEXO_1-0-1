#include "mainwindow.h"
#include "ui_mainwindow.h"

#define HIP_FLEXION_LIMITATION 120
#define HIP_EXTENSION_LIMITATION -10
#define KNEE_FLEXION_LIMITATION 120
#define KNEE_EXTENTION_LIMITATION 0


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    motor_left_hip = new my_maxon_motor();
    motor_right_hip = new my_maxon_motor();
    motor_left_knee = new my_maxon_motor();
    motor_right_knee = new my_maxon_motor();
    timer = new QTimer(this);
    timer->stop();
    timer->setInterval(100);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(checkMotorStatus()) );
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(checkSensorStatus()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateIMUData()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(recordData_Thread()));
    QObject::connect(this, SIGNAL(sendHeelStrikeTime(double)), this, SLOT(receiveHeelStrikeEventTime(double)));
    //timer->start(10);
    Max_profile_velocity = 1600;
    Max_following_error = 3000;
    Max_acceleration = 1000;
    Max_decceleration = 1000;
    moveMotor = new moveMotor_thread();
    //moveMotor = new moveMotor_thread();


//    QLineEdit *placeHolder = new QLineEdit;
//    placeHolder->setPlaceholderText(QStringLiteral("Please select step interval"));
//    ui->comboBox_stepInterval->setLineEdit(placeHolder);
    ui->gaitEvent_left->addGraph();
    ui->gaitEvent_right->addGraph();
    ui->qcustomPlot_gaitCadence->addGraph();
    ui->qcustomPlot_gaitCadence->addGraph();
    for(int i= 0; i < 4; i++){
        ui->gait_monitor_1->addGraph();
    }
    for(int i= 0; i < 4; i++){
        ui->gaitCadence_monitor->addGraph();
    }


    this->recordOrNot = false;
    this->b_saving_file = false;
    manager = LpmsSensorManagerFactory();

    //define default angular velocity gait parameter
    walk.ramp_max = 20;
    walk.ramp_y = 20;
    walk.stancePhase_period = 50;
    walk.knee_sin_x = 85;
    walk.knee_sin_y = 27;
    walk.knee_sin_amp = 66;
    walk.hip_sin_x = 80;
    walk.hip_sin_y = 20;
    walk.hip_sin_amp = 55;

    status_walking = false;
    status_stairAcent = false;
    status_stairDecent = false;
}

double MainWindow::radPerSecond2RPM(double radPerSecond)
{
    return radPerSecond*60/(2*M_PI);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_enable_clicked()
{
    QString str_errorcode;
    motor_left_hip->setEnabled(&str_errorcode);
    motor_right_hip->setEnabled(&str_errorcode);
    motor_left_knee->setEnabled(&str_errorcode);
    motor_right_knee->setEnabled(&str_errorcode);
    qDebug() << QString("error code = 0x%1").arg(str_errorcode, 1, 16);
}

void MainWindow::on_pushButton_disable_clicked()
{
    QString str_errorcode;
    motor_left_hip->setDisabled(&str_errorcode);
    motor_right_hip->setDisabled(&str_errorcode);
    motor_left_knee->setDisabled(&str_errorcode);
    motor_right_knee->setDisabled(&str_errorcode);
    qDebug() << QString("error code = 0x%1").arg(str_errorcode, 1, 16);
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename;
    QString file_dir;
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("Model (*.model *.txt)"));
    file_dir = filename.mid(0, filename.lastIndexOf('/') + 1);

    if(filename.isEmpty())
    {
        QMessageBox::information(this, "Error", "There isn't any .model file");
        return;
    }

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "Error", "Read file failed");
    }

    model_time.clear();
    model_mean_left_hip.clear();
    model_mean_left_knee.clear();
    model_mean_right_hip.clear();
    model_mean_right_knee.clear();
    model_std_left_hip.clear();
    model_std_left_knee.clear();
    model_std_left_hip.clear();
    model_std_right_hip.clear();
    model_std_right_knee.clear();
    int counter = 0;

    while(!file.atEnd()){
        QString line = file.readLine();
        QStringList qs_list = line.split(',');
        model_time.push_back(counter);
        model_mean_left_hip.push_back(qs_list.at(1).toDouble());
        model_mean_right_hip.push_back(qs_list.at(3).toDouble());
        model_mean_left_knee.push_back(qs_list.at(5).toDouble());
        model_mean_right_knee.push_back(qs_list.at(7).toDouble());
        model_std_left_hip.push_back(qs_list.at(2).toDouble());
        model_std_right_hip.push_back(qs_list.at(4).toDouble());
        model_std_left_knee.push_back(qs_list.at(6).toDouble());
        model_std_right_knee.push_back(qs_list.at(8).toDouble());
        counter++;
    }


    ui->gait_monitor_1->graph(0)->setData(model_time, model_mean_left_hip);
    ui->gait_monitor_1->graph(1)->setData(model_time, model_mean_right_hip);
    ui->gait_monitor_1->graph(2)->setData(model_time, model_mean_left_knee);
    ui->gait_monitor_1->graph(3)->setData(model_time, model_mean_right_knee);
    ui->gait_monitor_1->xAxis->setLabel("time");
    ui->gait_monitor_1->yAxis->setLabel("angle (degree)");
    ui->gait_monitor_1->yAxis->setRange(-10, 90);
    ui->gait_monitor_1->xAxis->setRange(0, 10000);
    ui->gait_monitor_1->xAxis->setVisible(true);
    ui->gait_monitor_1->xAxis->setTickLabels(true);
    ui->gait_monitor_1->yAxis->setVisible(true);
    ui->gait_monitor_1->graph(1)->setPen(QPen(Qt::red));
    ui->gait_monitor_1->graph(0)->setPen(QPen(Qt::blue));
    ui->gait_monitor_1->graph(2)->setPen(QPen(Qt::green));
    ui->gait_monitor_1->graph(3)->setPen(QPen(Qt::black));
    ui->gait_monitor_1->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->gait_monitor_1->graph(1)->setBrush(QBrush(QColor(255, 0, 0, 20)));
    ui->gait_monitor_1->graph(2)->setBrush(QBrush(QColor(0, 255, 0, 20)));
    ui->gait_monitor_1->graph(3)->setBrush(QBrush(QColor(0, 0, 0, 20)));
    ui->gait_monitor_1->replot();
}

void MainWindow::on_actionConnect_All_triggered()
{
    QString str_error;
    bool motor_is_connected = motor_left_hip->openDevice(&str_error) && motor_right_hip->openDevice(&str_error) && motor_left_knee->openDevice(&str_error) &&
            motor_right_knee->openDevice(&str_error);

    if(motor_is_connected == 0)
    {
        QMessageBox::information(this, "Error", "Motors are not conntected.");
        return;
    }
    QMessageBox::information(this, "BIMEXO",  "Connection secceeded");
//    this->Max_profile_velocity = 500;

    //setup angular velocity data
    lowerLimbAngularVelocityGenerator(&angularVelocity_leftHip, &angularVelocity_leftKnee, &angularVelocity_rightHip, &angularVelocity_rightKnee, &walk);
    displayAngularVelocityGaitData(&angularVelocity_leftHip, &angularVelocity_leftKnee, &angularVelocity_rightHip, &angularVelocity_rightKnee);
}

void MainWindow::on_actionDisconnect_All_triggered()
{
    motor_left_hip->closeALLDevice();
    motor_right_hip->closeALLDevice();
    motor_left_knee->closeALLDevice();
    motor_right_knee->closeALLDevice();
    ui->pushButton_enable->setDisabled(true);
    ui->pushButton_disable->setDisabled(true);
}

void MainWindow::on_pushButton_move_clicked()
{

    double left_hip_flexion_limit = 120;
    double left_hip_extension_limit = -10;
    double right_hip_flexion_limit = 120;
    double right_hip_extension_limit = -10;
    double left_knee_flexion_limit  = 120;
    double right_knee_flexion_limit = 120;
    double left_knee_extension_limit = 0;
    double right_knee_extension_limit = 0;

    QString str_ErrorCode;
    int stepSize = ui->lineEdit_stepSize->text().toInt()*model_time.size()/100;

    static int step = 0;
    if(step >= model_mean_left_hip.size())
        step = 0;
    if(motor_left_hip->getEnableState(&str_ErrorCode)){
        double target_position;
        if(model_mean_left_hip.at(step) > left_hip_flexion_limit-5){
            target_position = left_hip_flexion_limit-5;
        }else if(model_mean_left_hip.at(step) < left_hip_extension_limit+5){
            target_position = left_hip_extension_limit+5;
        }else{
            target_position = model_mean_left_hip.at(step);
        }
        target_position *= -1.0; //if this is left
        qDebug() << "left_hip = " << QString::number(model_mean_left_hip.at(step));
        motor_left_hip->MoveToPosition(target_position, true, &str_ErrorCode);}
    else{
        qDebug() << "motor_left_hip FAIL!!!!!";
    }

    if(motor_right_hip->getEnableState(&str_ErrorCode)){
        double target_position;
        if(model_mean_right_hip.at(step) > right_hip_flexion_limit-5){
            target_position = right_hip_flexion_limit-5;
        }else if(model_mean_right_hip.at(step) < right_hip_extension_limit+5){
            target_position = right_hip_extension_limit+5;
        }else{
            target_position = model_mean_right_hip.at(step);
        }
        qDebug() << "right_hip = " << QString::number(model_mean_right_hip.at(step));
        motor_right_hip->MoveToPosition(target_position, true, &str_ErrorCode);}
    else{
        qDebug() <<"motor_right_hip FAIL!!!!!";
    }

    if(motor_left_knee->getEnableState(&str_ErrorCode)){
        double target_position;
        if(model_mean_left_knee.at(step) > left_knee_flexion_limit-5){
            target_position = left_knee_flexion_limit-5;
        }else if(model_mean_left_knee.at(step) < left_knee_extension_limit+5){
            target_position = left_knee_extension_limit+5;
        }else{
            target_position = model_mean_left_knee.at(step);
        }
        target_position *= -1.0; //if this is left
        qDebug() << "left_knee = " << QString::number(model_mean_left_knee.at(step));
        motor_left_knee->MoveToPosition(target_position, true, &str_ErrorCode);}
    else{
        qDebug() << "motor_left_knee FAIL!!!!!";
    }

    if(motor_right_knee->getEnableState(&str_ErrorCode)){
        double target_position;
        if(model_mean_right_knee.at(step) > right_knee_flexion_limit-5){
            target_position = right_knee_flexion_limit-5;
        }else if(model_mean_right_knee.at(step) < right_knee_extension_limit+5){
            target_position = right_knee_extension_limit+5;
        }else{
            target_position = model_mean_right_knee.at(step);
        }
        qDebug() << "right_knee = " << QString::number(model_mean_right_knee.at(step));
        motor_right_knee->MoveToPosition(target_position, true, &str_ErrorCode);}
    else{
        qDebug() << "motor_right_knee FAIL!!!!!";
    }

    qDebug() << "step = " << QString::number(step);
    step += stepSize;
//    QVector<double> targetLeftHip;
//    QVector<double> targetRightHip;
//    QVector<double> targetLeftKnee;
//    QVector<double> targetrightKnee;

//    for(int i = 0; i < 10000*stepSize; i++)
//    {
//        targetLeftHip.append(model_mean_left_hip.at(i));
//        targetRightHip.append(model_mean_right_hip.at(i));
//        targetLeftKnee.append(model_mean_left_knee.at(i));
//        targetrightKnee.append(model_mean_right_knee.at(i));
//    }

//    stepSize += stepSize;
//    if(stepSize > 10000)
//        stepSize -= 10000;

//    moveMotor->setArg(motor_left_hip, motor_right_hip, motor_left_knee, motor_right_knee,
//                      &targetLeftHip, &targetRightHip, &targetLeftKnee, &targetrightKnee);
//    moveMotor->start();

}

void MainWindow::checkMotorStatus()
{

    QString str_errorCode;
    if (motor_left_hip->getEnableState(&str_errorCode))
        ui->label_left_hip_status->setStyleSheet("QLabel { background-color : green; color : black; }");
    else
        ui->label_left_hip_status->setStyleSheet("QLabel { background-color : red; color: black; }");
    if (motor_right_hip->getEnableState(&str_errorCode))
        ui->label_right_hip_status->setStyleSheet("QLabel { background-color : green; color : black; }");
    else
        ui->label_right_hip_status->setStyleSheet("QLabel { background-color : red; color: black; }");
    if (motor_left_knee->getEnableState(&str_errorCode))
        ui->label_left_knee_status->setStyleSheet("QLabel { background-color : green; color : black; }");
    else
        ui->label_left_knee_status->setStyleSheet("QLabel { background-color : red; color: black; }");
    if (motor_right_knee->getEnableState(&str_errorCode))
        ui->label_right_knee_status->setStyleSheet("QLabel { background-color : green; color : black; }");
    else
        ui->label_right_knee_status->setStyleSheet("QLabel { background-color : red; color: black; }");
}

void MainWindow::on_actionCalibration_triggered()
{
    QString str_ErrorCode;
    motor_left_hip->calibration(85335, HM_POSITIVE_LIMIT_SWITCH, &str_ErrorCode);
    motor_right_hip->calibration(85335, HM_NEGATIVE_LIMIT_SWITCH, &str_ErrorCode);
    motor_left_hip->WaitForHomingAttained(&str_ErrorCode);
    motor_right_hip->WaitForHomingAttained(&str_ErrorCode);

    motor_left_knee->calibration(0, HM_POSITIVE_LIMIT_SWITCH, &str_ErrorCode);
    motor_right_knee->calibration(0, HM_NEGATIVE_LIMIT_SWITCH, &str_ErrorCode);
    motor_left_knee->WaitForHomingAttained(&str_ErrorCode);
    motor_right_knee->WaitForHomingAttained(&str_ErrorCode);

}

void MainWindow::on_actionJoint_Angle_Data_triggered()
{
    QString filename;
    QString file_dir;
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("Model (*.model *.txt)"));
    file_dir = filename.mid(0, filename.lastIndexOf('/') + 1);

    if(filename.isEmpty())
    {
        QMessageBox::information(this, "Error", "There isn't any .model file");
        return;
    }

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "Error", "Read file failed");
    }

    model_time.clear();
    model_mean_left_hip.clear();
    model_mean_left_knee.clear();
    model_mean_right_hip.clear();
    model_mean_right_knee.clear();
    model_std_left_hip.clear();
    model_std_left_knee.clear();
    model_std_left_hip.clear();
    model_std_right_hip.clear();
    model_std_right_knee.clear();
    int counter = 0;

    while(!file.atEnd()){
        QString line = file.readLine();
        QStringList qs_list = line.split(',');
        model_time.push_back(counter);
        model_mean_left_hip.push_back(qs_list.at(0).toDouble());
        model_mean_left_knee.push_back(qs_list.at(1).toDouble());
        model_mean_right_hip.push_back(qs_list.at(2).toDouble());
        model_mean_right_knee.push_back(qs_list.at(3).toDouble());
        counter++;
    }


    ui->gait_monitor_1->graph(0)->setData(model_time, model_mean_left_hip);
    ui->gait_monitor_1->graph(1)->setData(model_time, model_mean_right_hip);
    ui->gait_monitor_1->graph(2)->setData(model_time, model_mean_left_knee);
    ui->gait_monitor_1->graph(3)->setData(model_time, model_mean_right_knee);
    ui->gait_monitor_1->xAxis->setLabel("time");
    ui->gait_monitor_1->yAxis->setLabel("angle (degree)");
    ui->gait_monitor_1->yAxis->setRange(-20, 90);
    ui->gait_monitor_1->xAxis->setRange(0, model_time.last()+10);
    ui->gait_monitor_1->xAxis->setVisible(true);
    ui->gait_monitor_1->xAxis->setTickLabels(true);
    ui->gait_monitor_1->yAxis->setVisible(true);
    ui->gait_monitor_1->graph(1)->setPen(QPen(Qt::red));
    ui->gait_monitor_1->graph(0)->setPen(QPen(Qt::blue));
    ui->gait_monitor_1->graph(2)->setPen(QPen(Qt::green));
    ui->gait_monitor_1->graph(3)->setPen(QPen(Qt::black));
    ui->gait_monitor_1->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->gait_monitor_1->graph(1)->setBrush(QBrush(QColor(255, 0, 0, 20)));
    ui->gait_monitor_1->graph(2)->setBrush(QBrush(QColor(0, 255, 0, 20)));
    ui->gait_monitor_1->graph(3)->setBrush(QBrush(QColor(0, 0, 0, 20)));
    ui->gait_monitor_1->replot();
}

void MainWindow::on_actionJoint_Angular_Velocity_Data_triggered()
{
    QString filename;
    QString file_dir;
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("Model (*.model *.txt)"));
    file_dir = filename.mid(0, filename.lastIndexOf('/') + 1);

    if(filename.isEmpty())
    {
        QMessageBox::information(this, "Error", "There isn't any .model file");
        return;
    }

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "Error", "Read file failed");
    }

    model_time.clear();
    angularVelocity_leftHip.clear();
    angularVelocity_leftKnee.clear();
    angularVelocity_rightHip.clear();
    angularVelocity_rightKnee.clear();

    int counter = 0;

    while(!file.atEnd()){
        QString line = file.readLine();
        QStringList qs_list = line.split(',');
        model_time.push_back(counter);
        angularVelocity_leftHip.push_back(qs_list.at(0).toDouble());
        angularVelocity_leftKnee.push_back(qs_list.at(2).toDouble());
        angularVelocity_rightHip.push_back(qs_list.at(1).toDouble());
        angularVelocity_rightKnee.push_back(qs_list.at(3).toDouble());
        counter++;
    }


    ui->gaitCadence_monitor->graph(0)->setData(model_time, angularVelocity_leftHip);
    ui->gaitCadence_monitor->graph(1)->setData(model_time, angularVelocity_leftKnee);
    ui->gaitCadence_monitor->graph(2)->setData(model_time, angularVelocity_rightHip);
    ui->gaitCadence_monitor->graph(3)->setData(model_time, angularVelocity_rightKnee);
    ui->gaitCadence_monitor->xAxis->setLabel("time");
    ui->gaitCadence_monitor->yAxis->setLabel("angular Velocity (degree/second)");
    ui->gaitCadence_monitor->yAxis->setRange(-50, 60);
    ui->gaitCadence_monitor->xAxis->setRange(0, model_time.last()+10);
    ui->gaitCadence_monitor->xAxis->setVisible(true);
    ui->gaitCadence_monitor->xAxis->setTickLabels(true);
    ui->gaitCadence_monitor->yAxis->setVisible(true);
    ui->gaitCadence_monitor->graph(1)->setPen(QPen(Qt::red));
    ui->gaitCadence_monitor->graph(0)->setPen(QPen(Qt::blue));
    ui->gaitCadence_monitor->graph(2)->setPen(QPen(Qt::green));
    ui->gaitCadence_monitor->graph(3)->setPen(QPen(Qt::black));
    ui->gaitCadence_monitor->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->gaitCadence_monitor->graph(1)->setBrush(QBrush(QColor(255, 0, 0, 20)));
    ui->gaitCadence_monitor->graph(2)->setBrush(QBrush(QColor(0, 255, 0, 20)));
    ui->gaitCadence_monitor->graph(3)->setBrush(QBrush(QColor(0, 0, 0, 20)));
    ui->gaitCadence_monitor->replot();

}

void MainWindow::on_pushButton_move_withVelocity_clicked()
{
    double left_hip_flexion_limit = 120;
    double left_hip_extension_limit = -10;
    double right_hip_flexion_limit = 120;
    double right_hip_extension_limit = -10;
    double left_knee_flexion_limit  = 120;
    double right_knee_flexion_limit = 120;
    double left_knee_extension_limit = 0;
    double right_knee_extension_limit = 0;

    QString str_ErrorCode;
//    int stepSize = ui->lineEdit_stepSize->text().toInt()*model_time.size()/100;

    int step = 0;
    for(step = 0; step < model_mean_left_hip.size(); step += 100){
        if(step >= model_mean_left_hip.size())
            step = 0;
        if(motor_left_hip->getEnableState(&str_ErrorCode)){
            double target_position;
            if(model_mean_left_hip.at(step) > left_hip_flexion_limit-5){
                target_position = left_hip_flexion_limit-5;
            }else if(model_mean_left_hip.at(step) < left_hip_extension_limit+5){
                target_position = left_hip_extension_limit+5;
            }else{
                target_position = model_mean_left_hip.at(step);
            }
            target_position *= -1.0; //if this is left
            //qDebug() << "left_hip = " << QString::number(model_mean_left_hip.at(step));
            motor_left_hip->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_leftHip.at(step)))*100, Max_acceleration, Max_decceleration ,true, &str_ErrorCode);}
        else{
            qDebug() << "motor_left_hip FAIL!!!!!";
        }

        if(motor_right_hip->getEnableState(&str_ErrorCode)){
            double target_position;
            if(model_mean_right_hip.at(step) > right_hip_flexion_limit-5){
                target_position = right_hip_flexion_limit-5;
            }else if(model_mean_right_hip.at(step) < right_hip_extension_limit+5){
                target_position = right_hip_extension_limit+5;
            }else{
                target_position = model_mean_right_hip.at(step);
            }
            //qDebug() << "right_hip = " << QString::number(model_mean_right_hip.at(step));
            motor_right_hip->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_leftHip.at(step)))*100, Max_acceleration, Max_decceleration  ,true, &str_ErrorCode);}
        else{
            qDebug() <<"motor_right_hip FAIL!!!!!";
        }

        if(motor_left_knee->getEnableState(&str_ErrorCode)){
            double target_position;
            if(model_mean_left_knee.at(step) > left_knee_flexion_limit-5){
                target_position = left_knee_flexion_limit-5;
            }else if(model_mean_left_knee.at(step) < left_knee_extension_limit+5){
                target_position = left_knee_extension_limit+5;
            }else{
                target_position = model_mean_left_knee.at(step);
            }
            target_position *= -1.0; //if this is left
            //qDebug() << "left_knee = " << QString::number(model_mean_left_knee.at(step));
            motor_left_knee->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_leftHip.at(step)))*100, Max_acceleration, Max_decceleration ,true, &str_ErrorCode);}
        else{
            qDebug() << "motor_left_knee FAIL!!!!!";
        }

        if(motor_right_knee->getEnableState(&str_ErrorCode)){
            double target_position;
            if(model_mean_right_knee.at(step) > right_knee_flexion_limit-5){
                target_position = right_knee_flexion_limit-5;
            }else if(model_mean_right_knee.at(step) < right_knee_extension_limit+5){
                target_position = right_knee_extension_limit+5;
            }else{
                target_position = model_mean_right_knee.at(step);
            }
            //qDebug() << "right_knee = " << QString::number(model_mean_right_knee.at(step));
            motor_right_knee->MoveToPositionWithVelocity(target_position, abs(radPerSecond2RPM(angularVelocity_leftHip.at(step)))*100, Max_acceleration, Max_decceleration  ,true, &str_ErrorCode);}
        else{
            qDebug() << "motor_right_knee FAIL!!!!!";
        }

        qDebug() << "step = " << QString::number(step);
        Sleep(100);
    }
    //step += stepSize;
}

void MainWindow::on_actionLeft_Foot_triggered()
{
    lpms_LF = manager->addSensor(DEVICE_LPMS_B, "00:04:3E:9F:E0:CF");
//    lpms_LF->setOrientationOffset(0);
//    lpms_LF->saveCalibrationData();
    while(1){
        if(lpms_LF->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED && lpms_LF->hasImuData()){
            break;
        }
    }
    ui->label_left_foot_IMU_status->setStyleSheet("QLabel { background-color : green; color : black; }");
}

void MainWindow::on_actionRight_Foot_triggered()
{
    lpms_RF = manager->addSensor(DEVICE_LPMS_B, "00:04:3E:9F:E1:4B");
//    lpms_RF->setOrientationOffset(0);
//    lpms_RF->saveCalibrationData();
    while(1){
        if(lpms_RF->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED && lpms_RF->hasImuData()){
            break;
        }
    }
    ui->label_right_foot_IMU_status->setStyleSheet("QLabel { background-color : green; color : black; }");
}

void MainWindow::checkSensorStatus()
{
    if(recordOrNot){
        if(lpms_LF->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED && lpms_LF->hasImuData())
            ui->label_left_foot_IMU_status->setStyleSheet("QLabel{background-color : green}");
        else
            ui->label_left_foot_IMU_status->setStyleSheet("QLabel{background-color : red}");

        if(lpms_RF->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED && lpms_RF->hasImuData())
            ui->label_right_foot_IMU_status->setStyleSheet("QLabel{background-color : green}");
        else
            ui->label_right_foot_IMU_status->setStyleSheet("QLabel{background-color : red}");

        if(lpms_waist->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED && lpms_waist->hasImuData())
            ui->label_waist_IMU_status->setStyleSheet("QLabel{background-color : green}");
        else
            ui->label_waist_IMU_status->setStyleSheet("QLabel{background-color : red}");
    }

}

void MainWindow::updateIMUData()
{
    QString errorCode;
    if(recordOrNot){
        static double milisecond;
        bool sensorConnected_hasData = lpms_RF->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED && lpms_RF->hasImuData() &&
                lpms_LF->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED && lpms_LF->hasImuData();

        if (sensorConnected_hasData)
        {
            //imudata.r[0] = roll(bank)
            //imudata.r[1] = pitch(alttitude)
            //imudata.r[2] = yaw(heading)


            d_leftFoot = lpms_LF->getCurrentData();
            d_rightFoot = lpms_RF->getCurrentData();
            d_waist = lpms_waist->getCurrentData();
            //angular velocity data

            gyro_leftFoot[0] = d_leftFoot.g[0];
            gyro_leftFoot[1] = d_leftFoot.g[1];
            gyro_leftFoot[2] = d_leftFoot.g[2];

            gyro_rightFoot[0] = d_rightFoot.g[0];
            gyro_rightFoot[1] = d_rightFoot.g[1];
            gyro_rightFoot[2] = d_rightFoot.g[2];

            waist_angle.push_back(d_waist.r[0]);
            waist_gyro.push_back(d_waist.g[0]);

            moveMotor->IMU_waist = d_waist.r[0];
            moveMotor->IMU_waist_gyro = d_waist.g[0];

            //update motor velocity and position
            motor_left_hip->getPositionProfile(&leftHipVelocity, &leftHipAcceleration, &leftHipDecceleration, &errorCode);
            motor_right_hip->getPositionProfile(&rightHipVelocity, &rightHipAcceleration, &rightHipDecceleration, &errorCode);
            motor_left_knee->getPositionProfile(&leftKneeVelocity, &leftKneeAcceleration, &leftKneeDecceleration, &errorCode);
            motor_right_knee->getPositionProfile(&rightKneeVelocity, &rightKneeAcceleration, &rightKneeDecceleration, &errorCode);

            leftFootAngularVelocity.push_back(-gyro_leftFoot[0]);
            rightFootAngularVelocity.push_back(-gyro_rightFoot[0]);
            if(leftFootAngularVelocity.size() > 2){
                gaitEventDetection(&milisecond, &leftFootAngularVelocity, &rightFootAngularVelocity, &leftGaitEvent, &rightGaitEvent);
                leftFootAngularVelocity.pop_front();
                rightFootAngularVelocity.pop_front();
            }
            this->gaitTime.push_back(milisecond);
            if(!gaitTime.isEmpty())
                plotGaitPhaseDetectionResult(&leftGaitEvent, &rightGaitEvent, &gaitTime);
            milisecond += 0.1;

        }
    }
}


void MainWindow::on_actionStart_Timer_triggered()
{
    timer->start();
}

void MainWindow::on_actionStart_Measurement_triggered()
{
    this->recordOrNot = true;
}

void MainWindow::on_actionStop_Measurement_triggered()
{
    this->recordOrNot = false;
}

int leftLegFiniteState = 1;
int rightLegFiniteState = 1;

void MainWindow::gaitEventDetection(double *gait_time, QVector<double> *leftFootGyro, QVector<double> *rightFootGyro, QVector<double>* leftGaitEvent, QVector<double>* rightGaitEvent)
{
    //*******
    /* Gait Event Definition for normal walk
     * Heel strike: 5
     * Stance: 1
     * Heel off: 2
     * Toe off: 3
     * Swing: 4
     * Gait Event Transition Definition
     * T1: Stance -> Heel off
     * T2: Heel off -> Toe off
     * T3: Toe off -> Swing
     * T4: Swing -> Heel Strike
     * T5: Heel strike -> Stance
     * T6: Toe off -> Stance
     * Gait Event Definition for Exoskeleton walk
     * Stance: 1
     * Heel off: 2
     * Toe off: 3
     * Swing: 4
     * Gait Event Transition Definition
     * T1: Stance -> Heel off
     * T2: Heel off -> Toe off
     * T3: Toe off -> Swing
     * T4: Swing -> Stance
     * T5: Toe off -> Stance
     */
    //*******

    //left Foot(normal walk)
    /*for (int i = 1; i < leftFootGyro->size()-1; i++){
        switch (leftLegFiniteState){
        case 5: // heel strike
            if(leftFootGyro->at(i) < 10 && leftFootGyro->at(i) > -20){
                leftGaitEvent->push_back(1);
                leftLegFiniteState = 1;
                sendHeelStrikeTime(*gait_time);
            }
            else{
                leftGaitEvent->push_back(5);
                leftLegFiniteState = 5;
            }
            break;
        case 1: //stance
            if(leftFootGyro->at(i) < -20 && leftFootGyro->at(i) < leftFootGyro->at(i-1)){
                leftGaitEvent->push_back(2);
                leftLegFiniteState = 2;
            }
            else{
                leftGaitEvent->push_back(1);
                leftLegFiniteState = 1;
                moveMotor->gaitPhase_left = 1; // stance phase
            }
            break;
        case 2: //Heel off
            if(leftFootGyro->at(i) < -90 && leftFootGyro->at(i) < leftFootGyro->at(i-1) && leftFootGyro->at(i) < leftFootGyro->at(i+1)){
                leftGaitEvent->push_back(3);
                leftLegFiniteState = 3;
                }
            else{
                leftGaitEvent->push_back(2);
                leftLegFiniteState = 2;
                moveMotor->gaitPhase_left = 2;
            }
            break;
        case 3: //Toe off
            if(leftFootGyro->at(i) > 100 && leftFootGyro->at(i) > leftFootGyro->at(i-1) && leftFootGyro->at(i) > leftFootGyro->at(i+1)){
                leftGaitEvent->push_back(4);
                leftLegFiniteState = 4;
            }
            else{
                leftGaitEvent->push_back(3);
                leftLegFiniteState = 3;
            }
            break;
        case 4: //swing
            if(leftFootGyro->at(i) < -50 && leftFootGyro->at(i) < leftFootGyro->at(i-1) && leftFootGyro->at(i) < leftFootGyro->at(i+1)){
                leftGaitEvent->push_back(5);
                leftLegFiniteState = 5;
            }
            else{
                leftGaitEvent->push_back(4);
                leftLegFiniteState = 4;
                moveMotor->gaitPhase_left = 4;
            }
            break;
        }
    }*/
    //right Foot(normal walk)
    /*for (int i = 1; i < rightFootGyro->size()-1; i++){
        switch (rightLegFiniteState){
        case 5: // heel strike
            if(rightFootGyro->at(i) < 10 && rightFootGyro->at(i) > -20){
                rightGaitEvent->push_back(1);
                rightLegFiniteState = 1;
            }
            else{
                rightGaitEvent->push_back(5);
                rightLegFiniteState = 5;
            }
            break;
        case 1: //stance
            if(rightFootGyro->at(i) < -20 && rightFootGyro->at(i) < rightFootGyro->at(i-1)){
                rightGaitEvent->push_back(2);
                rightLegFiniteState = 2;
                }
            else{
                rightGaitEvent->push_back(1);
                rightLegFiniteState = 1;
            }
            break;
        case 2: //Heel off
            if(rightFootGyro->at(i) < -90 && rightFootGyro->at(i) < rightFootGyro->at(i-1) && rightFootGyro->at(i) < rightFootGyro->at(i+1)){
                rightGaitEvent->push_back(3);
                rightLegFiniteState = 3;
            }
            else{
                rightGaitEvent->push_back(2);
                rightLegFiniteState = 2;
            }
            break;
        case 3: //Toe off
            if(rightFootGyro->at(i) > 100 && rightFootGyro->at(i) > rightFootGyro->at(i-1) && rightFootGyro->at(i) > rightFootGyro->at(i+1)){
                rightGaitEvent->push_back(4);
                rightLegFiniteState = 4;
            }
            else{
                rightGaitEvent->push_back(3);
                rightLegFiniteState = 3;
            }
            break;
        case 4: //swing
            if(rightFootGyro->at(i) < -50 && rightFootGyro->at(i) < rightFootGyro->at(i-1) && rightFootGyro->at(i) < rightFootGyro->at(i+1)){
                rightGaitEvent->push_back(5);
                rightLegFiniteState = 5;
            }
            else{
                rightGaitEvent->push_back(4);
                rightLegFiniteState = 4;
            }
            break;
        }
    }*/
    //left Foot (exoskeleton walk)
    for (int i = 1; i < leftFootGyro->size()-1; i++){
        switch (leftLegFiniteState){
        case 5: // heel strike
            if(leftFootGyro->at(i) > 50 && leftFootGyro->at(i) > leftFootGyro->at(i+1) && leftFootGyro->at(i) > leftFootGyro->at(i-1)){
                leftGaitEvent->push_back(1);
                leftLegFiniteState = 1;
                sendHeelStrikeTime(*gait_time);
            }
            else{
                leftGaitEvent->push_back(5);
                leftLegFiniteState = 5;
            }
            break;
        case 1: //stance
            if(leftFootGyro->at(i) < 0 && leftFootGyro->at(i) < leftFootGyro->at(i-1)){
                leftGaitEvent->push_back(2);
                leftLegFiniteState = 2;
            }
            else{
                leftGaitEvent->push_back(1);
                leftLegFiniteState = 1;
                moveMotor->gaitPhase_left = 1; // stance phase
            }
            break;
        case 2: //Heel off
            if(leftFootGyro->at(i) < -30 && leftFootGyro->at(i) < leftFootGyro->at(i-1) && leftFootGyro->at(i) < leftFootGyro->at(i+1)){
                leftGaitEvent->push_back(3);
                leftLegFiniteState = 3;
                }
            else{
                leftGaitEvent->push_back(2);
                leftLegFiniteState = 2;
                moveMotor->gaitPhase_left = 2;
            }
            break;
        case 3: //Toe off
            if(leftFootGyro->at(i) > 50 && leftFootGyro->at(i) > leftFootGyro->at(i-1) && leftFootGyro->at(i) > leftFootGyro->at(i+1)){
                leftGaitEvent->push_back(4);
                leftLegFiniteState = 4;
            }
            else{
                leftGaitEvent->push_back(3);
                leftLegFiniteState = 3;
            }
            break;
        case 4: //swing
            if(leftFootGyro->at(i) < 10 && leftFootGyro->at(i) < leftFootGyro->at(i-1) && leftFootGyro->at(i) < leftFootGyro->at(i+1)){
                leftGaitEvent->push_back(5);
                leftLegFiniteState = 5;
            }
            else{
                leftGaitEvent->push_back(4);
                leftLegFiniteState = 4;
                moveMotor->gaitPhase_left = 4;
            }
            break;
        }
    }
    //right Foot (exoskeleton walk)
    for (int i = 1; i < rightFootGyro->size()-1; i++){
        switch (rightLegFiniteState){
        case 5: // heel strike
            if(rightFootGyro->at(i) > 50 && rightFootGyro->at(i) > rightFootGyro->at(i+1) && rightFootGyro->at(i) > leftFootGyro->at(i-1)){
                rightGaitEvent->push_back(1);
                rightLegFiniteState = 1;
            }
            else{
                leftGaitEvent->push_back(5);
                leftLegFiniteState = 5;
            }
            break;
        case 1: //stance
            if(rightFootGyro->at(i) < 0 && rightFootGyro->at(i) < rightFootGyro->at(i-1)){
                rightGaitEvent->push_back(2);
                rightLegFiniteState = 2;
            }
            else{
                rightGaitEvent->push_back(1);
                rightLegFiniteState = 1;
            }
            break;
        case 2: //Heel off
            if(rightFootGyro->at(i) < -30 && rightFootGyro->at(i) < rightFootGyro->at(i-1) && rightFootGyro->at(i) < rightFootGyro->at(i+1)){
                rightGaitEvent->push_back(3);
                rightLegFiniteState = 3;
            }
            else{
                rightGaitEvent->push_back(2);
                rightLegFiniteState = 2;
            }
            break;
        case 3: //Toe off
            if(rightFootGyro->at(i) > 50 && rightFootGyro->at(i) > rightFootGyro->at(i-1) && rightFootGyro->at(i) > rightFootGyro->at(i+1)){
                rightGaitEvent->push_back(4);
                rightLegFiniteState = 4;
            }
            else{
                rightGaitEvent->push_back(3);
                rightLegFiniteState = 3;
            }
            break;
        case 4: //swing
            if(rightFootGyro->at(i) < 10 && rightFootGyro->at(i) < rightFootGyro->at(i-1) && rightFootGyro->at(i) < rightFootGyro->at(i+1)){
                rightGaitEvent->push_back(5);
                rightLegFiniteState = 5;
            }
            else{
                rightGaitEvent->push_back(4);
                rightLegFiniteState = 4;
            }
            break;
        }
    }

}

void MainWindow::displayAngularVelocityGaitData(QVector<double> *leftHip_angularVelocity, QVector<double> *leftknee_angularVelocity, QVector<double> *rightHip_angularVelocity, QVector<double> *rightKnee_angularVelocity)
{
    QVector<double> time(10000);

    for(int i = 0; i < time.size(); i++){
        time[i] = i;
    }

    ui->gaitCadence_monitor->graph(0)->setData(time, *leftHip_angularVelocity);
    ui->gaitCadence_monitor->graph(1)->setData(time, *leftknee_angularVelocity);
    ui->gaitCadence_monitor->graph(2)->setData(time, *rightHip_angularVelocity);
    ui->gaitCadence_monitor->graph(3)->setData(time, *rightKnee_angularVelocity);
    ui->gaitCadence_monitor->xAxis->setLabel("time");
    ui->gaitCadence_monitor->yAxis->setLabel("angular Velocity (degree/second)");
    ui->gaitCadence_monitor->yAxis->setRange(-70, 20);
    ui->gaitCadence_monitor->xAxis->setRange(0, time.last()+10);
    ui->gaitCadence_monitor->xAxis->setVisible(true);
    ui->gaitCadence_monitor->xAxis->setTickLabels(true);
    ui->gaitCadence_monitor->yAxis->setVisible(true);
    ui->gaitCadence_monitor->graph(1)->setPen(QPen(Qt::red));
    ui->gaitCadence_monitor->graph(0)->setPen(QPen(Qt::blue));
    ui->gaitCadence_monitor->graph(2)->setPen(QPen(Qt::green));
    ui->gaitCadence_monitor->graph(3)->setPen(QPen(Qt::black));
    ui->gaitCadence_monitor->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->gaitCadence_monitor->graph(1)->setBrush(QBrush(QColor(255, 0, 0, 20)));
    ui->gaitCadence_monitor->graph(2)->setBrush(QBrush(QColor(0, 255, 0, 20)));
    ui->gaitCadence_monitor->graph(3)->setBrush(QBrush(QColor(0, 0, 0, 20)));
    ui->gaitCadence_monitor->replot();
}

void MainWindow::lowerLimbAngularVelocityGenerator(QVector<double> *leftHip_angularVelocity, QVector<double> *leftKnee_angularVelocity, QVector<double> *rightHip_angularVelocity, QVector<double> *rightKnee_angularVelocity, parametricAngularVelocityModel *angularVelocity_parameter)
{

    QVector<double> time_left(10000);
    QVector<double> time_right(10000);
    double tmp_left = 0;
    double tmp_right = 0;
    for(int i = 0; i < time_left.size(); i++){
        if(time_left.at(i) < 5001){
            time_left[i] = tmp_left;
            time_right[i] = 50+tmp_right;
        }
        else{
            time_left[i] = tmp_left;
            time_right[i] = tmp_right;
        }
        tmp_left += 0.01;
        tmp_right += 0.01;
    }

    leftHip_angularVelocity->clear();
    leftKnee_angularVelocity->clear();
    rightHip_angularVelocity->clear();
    rightKnee_angularVelocity->clear();

    //left leg
    for(int i = 0; i < 10000; i++){
        //hip joint
        double leftHip_ramp = (angularVelocity_parameter->ramp_max/angularVelocity_parameter->stancePhase_period)*time_left[i]+angularVelocity_parameter->ramp_y;
        int tmp = 100*(time_left.at(i)-angularVelocity_parameter->hip_sin_x);
        double leftHip_sin = -(angularVelocity_parameter->hip_sin_amp - angularVelocity_parameter->hip_sin_y)*sin(2*M_PI*(tmp%10000)/10000.0)+angularVelocity_parameter->hip_sin_y;
        leftHip_angularVelocity->append(-std::min(leftHip_ramp, leftHip_sin));

        //knee joint
        double leftKnee_ramp = (angularVelocity_parameter->ramp_max/angularVelocity_parameter->stancePhase_period)*time_left[i]+angularVelocity_parameter->ramp_y;
        tmp = 100*(time_left[i]-angularVelocity_parameter->knee_sin_x);
        double leftKnee_sin = -(angularVelocity_parameter->knee_sin_amp - angularVelocity_parameter->knee_sin_y)*sin(2*M_PI*(tmp%10000)/10000.0)+angularVelocity_parameter->knee_sin_y;
        leftKnee_angularVelocity->append(-std::min(leftKnee_ramp, leftKnee_sin));
    }

    //right leg
    for(int i = 0; i < 10000; i++){
        //hip joint
        double rightHip_ramp = (angularVelocity_parameter->ramp_max/angularVelocity_parameter->stancePhase_period)*time_right[i]+angularVelocity_parameter->ramp_y;
        int tmp = 100*(time_right[i]-angularVelocity_parameter->hip_sin_x);
        double rightHip_sin = -(angularVelocity_parameter->hip_sin_amp - angularVelocity_parameter->hip_sin_y)*sin(2*M_PI*(tmp%10000)/10000.0)+angularVelocity_parameter->hip_sin_y;
        rightHip_angularVelocity->append(-std::min(rightHip_ramp, rightHip_sin));

        //knee joint
        double rightKnee_ramp = (angularVelocity_parameter->ramp_max/angularVelocity_parameter->stancePhase_period)*time_right[i]+angularVelocity_parameter->ramp_y;
        tmp = 100*(time_right[i]-angularVelocity_parameter->knee_sin_x);
        double rightKnee_sin = -(angularVelocity_parameter->knee_sin_amp - angularVelocity_parameter->knee_sin_y)*sin(2*M_PI*(tmp%10000)/10000.0)+angularVelocity_parameter->knee_sin_y;
        rightKnee_angularVelocity->append(-std::min(rightKnee_ramp, rightKnee_sin));
    }

}

void MainWindow::exoskeletonControl()
{
    double heelStrike_last = heelStrikeTime.last();
    static double heelStrike_previous;
    if(heelStrikeTime.size() < 2){
         heelStrike_previous = 0;
    }
    double p_gain = 0.1;
    double gaitCadence = 60/(heelStrike_last - heelStrike_previous); //gait frequency(step/min)
    double targetGaitCadence = ui->lineEdit_targetGaitCadence->text().toDouble();
    double error_gaitCadence = p_gain*(targetGaitCadence - gaitCadence)/targetGaitCadence;

    for(int i = 0; i < angularVelocity_leftHip.size(); i++){
        angularVelocity_leftHip[i] += angularVelocity_leftHip[i]*error_gaitCadence;
        angularVelocity_leftKnee[i] += angularVelocity_leftKnee[i]*error_gaitCadence;
        angularVelocity_rightHip[i] += angularVelocity_rightHip[i]*error_gaitCadence;
        angularVelocity_rightKnee[i] += angularVelocity_rightKnee[i]*error_gaitCadence;
    }
    displayAngularVelocityGaitData(&angularVelocity_leftHip, &angularVelocity_leftKnee, &angularVelocity_rightHip, &angularVelocity_rightKnee);
    plotGaitCadenceTrackingResult(&this->gaitCadence, &gaitCadence_target, &gaitTime);

    ui->lineEdit_gaitCadence->setText(QString::number(gaitCadence));
    this->gaitCadence.push_back(gaitCadence);
    this->gaitCadence_target.push_back(targetGaitCadence);
    
    heelStrike_previous = heelStrike_last;
}

void MainWindow::receiveHeelStrikeEventTime(double heelStrikeEvent)
{
    heelStrikeTime.append(heelStrikeEvent);
    if(heelStrikeTime.size() > 2)
        exoskeletonControl();
}


void MainWindow::plotGaitPhaseDetectionResult(QVector<double> *leftGaitEvent, QVector<double> *rightGaitEvent, QVector<double> *time)
{
    if(!time->isEmpty()){
        ui->gaitEvent_left->graph(0)->setData(*time, *leftGaitEvent);
        ui->gaitEvent_left->xAxis->setLabel("time (second)");
        ui->gaitEvent_left->yAxis->setLabel("Left gait phase");
        ui->gaitEvent_left->yAxis->setRange(-1, 6);
        ui->gaitEvent_left->xAxis->setRange(0, time->last());
        ui->gaitEvent_left->xAxis->setVisible(true);
        ui->gaitEvent_left->xAxis->setTickLabels(true);
        ui->gaitEvent_left->yAxis->setVisible(true);
        ui->gaitEvent_left->graph(0)->setPen(QPen(Qt::red));
        ui->gaitEvent_left->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
        ui->gaitEvent_left->replot();

        ui->gaitEvent_right->graph(0)->setData(*time, *rightGaitEvent);
        ui->gaitEvent_left->xAxis->setLabel("time (second)");
        ui->gaitEvent_left->yAxis->setLabel("Right gait phase");
        ui->gaitEvent_right->yAxis->setRange(-1, 6);
        ui->gaitEvent_right->xAxis->setRange(0, time->last());
        ui->gaitEvent_right->xAxis->setVisible(true);
        ui->gaitEvent_right->xAxis->setTickLabels(true);
        ui->gaitEvent_right->yAxis->setVisible(true);
        ui->gaitEvent_right->graph(0)->setPen(QPen(Qt::blue));
        ui->gaitEvent_right->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20)));
        ui->gaitEvent_right->replot();
    }
}

void MainWindow::plotGaitCadenceTrackingResult(QVector<double> *gaitCadence, QVector<double> *targetGaitCadence, QVector<double> *gaitTime)
{
    qDebug() << *targetGaitCadence;
    if(!gaitTime->isEmpty()){
        ui->qcustomPlot_gaitCadence->graph(0)->setData(*gaitTime, *gaitCadence);
        ui->qcustomPlot_gaitCadence->graph(1)->setData(*gaitTime, *targetGaitCadence);
        //plot setting
        ui->qcustomPlot_gaitCadence->xAxis->setLabel("time");
        ui->qcustomPlot_gaitCadence->yAxis->setLabel("gait cadence (step/min)");
        ui->qcustomPlot_gaitCadence->yAxis->setRange(-10, 70);
        ui->qcustomPlot_gaitCadence->xAxis->setRange(0, gaitTime->last());
        ui->qcustomPlot_gaitCadence->xAxis->setVisible(true);
        ui->qcustomPlot_gaitCadence->xAxis->setTickLabels(true);
        ui->qcustomPlot_gaitCadence->yAxis->setVisible(true);
        ui->qcustomPlot_gaitCadence->graph(0)->setPen(QPen(Qt::red));
        ui->qcustomPlot_gaitCadence->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
        ui->qcustomPlot_gaitCadence->graph(0)->setPen(QPen(Qt::blue));
        ui->qcustomPlot_gaitCadence->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20)));
        ui->qcustomPlot_gaitCadence->replot();
    }
}

void MainWindow::on_actionwaist_triggered()
{
    lpms_waist = manager->addSensor(DEVICE_LPMS_B, "00:04:3E:9F:E0:B3");
//    lpms_waist->setOrientationOffset(0);
//    lpms_waist->saveCalibrationData();
    while(1){
        if(lpms_waist->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED && lpms_waist->hasImuData()){
            break;
        }
    }
    ui->label_waist_IMU_status->setStyleSheet("QLabel{background-color : green}");
}

void MainWindow::on_radioButton_walking_clicked()
{
    status_walking = true;
    status_stairAcent = false;
    status_stairDecent = false;
}

void MainWindow::on_radioButton_stairAcent_clicked()
{
    status_walking = false;
    status_stairAcent = true;
    status_stairDecent = false;
}

void MainWindow::on_radioButton_stairDecent_clicked()
{
    status_walking = false;
    status_stairAcent = false;
    status_stairDecent = true;
}

void MainWindow::on_actionNew_Measurement_triggered()
{
    QLocale locale = QLocale(QLocale::English);
    QDate date = QDate::currentDate();
    QString dateString = locale.toString(date, "yyyyMMdd");
    QTime time = QTime::currentTime();
    QString timeString = locale.toString(time, "hhmmss");
    QString filePath = "./Data/" + dateString + "_" + timeString + ".csv";

    if(timer->isActive())
    {
        if(!QDir("Folder").exists())
            QDir().mkdir("Data");
        file = new QFile(filePath);
        QTextStream out(file);
        out << "gyro_leftFoot" << ", " << "gyro_rightFoot"
                << ", " << "gaitTime" << ", " << "waist_angle"
                << ", " << "waist_gyro"<< ", " << "leftGaitEvent"
                << ", " << "rightGaitEvent" << ", " << "left hip velocity" << ", "
                << "right hip velocity" << ", " << "left knee velocity" << ", "
                << "right knee velocity" ;/*<< ", " << "left hip position" << ", "
                << "right hip position" << ", " << "left knee position" << ", "
                << "right knee position";*/
        out << endl;
        b_saving_file = true;
    }
    else
        qDebug() << "Please start timer fisrt";
    file->open(QIODevice::WriteOnly | QIODevice::Text);
}

void MainWindow::recordData_Thread()
{
    QFuture<void> future = QtConcurrent::run(this, &MainWindow::recordData);
    future.waitForFinished();
}

void MainWindow::recordData()
{
  if(b_saving_file)
    {
        QTextStream out(file);
        //        QTextStream euler_out(eulerAngleFile);
        out << QString::number(gyro_leftFoot[0]) << ", " << QString::number(gyro_rightFoot[0])
                << ", " << QString::number(gaitTime.last()) << ", " << QString::number(waist_angle.last())
                << ", " << QString::number(waist_gyro.last()) << ", " << QString::number(leftGaitEvent.last())
                << ", " << QString::number(rightGaitEvent.last()) << ", " << QString::number(leftHipVelocity)
                << ", " << QString::number(rightHipVelocity) << ", " << QString::number(leftKneeVelocity)
                << ", " << QString::number(rightKneeVelocity);
        out << endl;
    }

}

void MainWindow::on_actionSave_triggered()
{
    b_saving_file = false;
    file->close();
}

void MainWindow::on_pushButton_threadTest_clicked()
{
//    QVector<double> mean_leftHip, mean_leftKnee, mean_rightHip, mean_rightKnee;
//    QVector<double> mean_angularVelocity_leftHip, mean_angularVelocity_rightHip, mean_angularVelocity_leftKnee, mean_angularVelocity_rightKnee;
//    double counter = 0;
//    double tmp_LH = 0, tmp_LK = 0, tmp_RH = 0, tmp_RK = 0, tmp_AC_LH = 0, tmp_AC_RH = 0, tmp_AC_LK = 0, tmp_AC_RK = 0;
//    for(int i = 0; i < model_mean_left_hip.size(); i++){
//        tmp_LH += model_mean_left_hip.at(i);
//        tmp_RH += model_mean_right_hip.at(i);
//        tmp_LK += model_mean_left_knee.at(i);
//        tmp_RK += model_mean_right_knee.at(i);

//        tmp_AC_LH += angularVelocity_leftHip.at(i);
//        tmp_AC_RH += angularVelocity_rightHip.at(i);
//        tmp_AC_LK += angularVelocity_leftKnee.at(i);
//        tmp_AC_RK += angularVelocity_rightKnee.at(i);

//        if(counter == 10){
//            mean_leftHip.push_back(tmp_LH/counter);
//            mean_rightHip.push_back(tmp_RH/counter);
//            mean_leftKnee.push_back(tmp_LK/counter);
//            mean_rightKnee.push_back(tmp_RK/counter);

//            mean_angularVelocity_leftHip.push_back(tmp_AC_LH/counter);
//            mean_angularVelocity_leftKnee.push_back(tmp_AC_LK/counter);
//            mean_angularVelocity_rightHip.push_back(tmp_AC_RH/counter);
//            mean_angularVelocity_rightKnee.push_back(tmp_AC_RK/counter);

//            tmp_LH = 0;
//            tmp_RH = 0;
//            tmp_LK = 0;
//            tmp_RK = 0;

//            tmp_AC_LH = 0;
//            tmp_AC_LK = 0;
//            tmp_AC_RH = 0;
//            tmp_AC_RK = 0;

//            counter = 0;
//        }
//        counter++;
//    }
//    this->model_mean_left_hip = mean_leftHip;
//    this->model_mean_left_knee = mean_leftKnee;
//    this->model_mean_right_hip = mean_rightHip;
//    this->model_mean_right_knee = mean_rightKnee;
//    this->angularVelocity_leftHip = mean_angularVelocity_leftHip;
//    this->angularVelocity_leftKnee = mean_angularVelocity_leftKnee;
//    this->angularVelocity_rightHip = mean_angularVelocity_rightHip;
//    this->angularVelocity_rightKnee = mean_angularVelocity_rightKnee;


    moveMotor->motor_leftHip = this->motor_left_hip;
    moveMotor->motor_leftKnee = this->motor_left_knee;
    moveMotor->motor_rightHip = this->motor_right_hip;
    moveMotor->motor_rightKnee = this->motor_right_knee;

    moveMotor->angle_leftHip = &(this->model_mean_left_hip);
    moveMotor->angle_leftKnee = &(this->model_mean_left_knee);
    moveMotor->angle_rightHip = &(this->model_mean_right_hip);
    moveMotor->angle_rightKnee = &(this->model_mean_right_knee);

    moveMotor->angularVelocity_leftHip = &(this->angularVelocity_leftHip);
    moveMotor->angularVelocity_rightHip = &(this->angularVelocity_rightHip);
    moveMotor->angularVelocity_leftKnee = &(this->angularVelocity_leftKnee);
    moveMotor->angularVelocity_rightKnee = &(this->angularVelocity_rightKnee);

    moveMotor->start();
}

void MainWindow::on_actionStand_triggered()
{
    QString str_ErrorCode;
    bool motorEnableState = motor_left_hip->getEnableState(&str_ErrorCode) && motor_right_hip->getEnableState(&str_ErrorCode) && motor_left_knee->getEnableState(&str_ErrorCode) && motor_right_knee->getEnableState(&str_ErrorCode);
    double velocity = 700;
    double acceleration = 500;
    double decceleration = 500;
    motor_left_hip->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_left_knee->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_right_hip->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_right_knee->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    if(motorEnableState){
        motor_left_knee ->MoveToPosition(-5, true, &str_ErrorCode);
        motor_right_knee->MoveToPosition(5, true, &str_ErrorCode);
        motor_left_hip  ->MoveToPosition(0, true, &str_ErrorCode);
        motor_right_hip ->MoveToPosition(0, true, &str_ErrorCode);

    }
}

void MainWindow::on_actionSit_triggered()
{
    QString str_ErrorCode;
    bool motorEnableState = motor_left_hip->getEnableState(&str_ErrorCode) && motor_right_hip->getEnableState(&str_ErrorCode) && motor_left_knee->getEnableState(&str_ErrorCode) && motor_right_knee->getEnableState(&str_ErrorCode);
    double velocity = 700;
    double acceleration = 500;
    double decceleration = 500;
    motor_left_hip->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_left_knee->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_right_hip->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_right_knee->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    if(motorEnableState){
        motor_left_hip  ->MoveToPosition(-90, true, &str_ErrorCode);
        motor_right_hip ->MoveToPosition(90, true, &str_ErrorCode);
        motor_left_knee ->MoveToPosition(-90, true, &str_ErrorCode);
        motor_right_knee->MoveToPosition(90, true, &str_ErrorCode);
    }
}

void MainWindow::on_pushButton_stopThread_clicked()
{
    moveMotor->running = !moveMotor->running;
    if(moveMotor->running == true)
        ui->pushButton_stopThread->setText("Stop");
    else
        ui->pushButton_stopThread->setText("Resume");
}

void MainWindow::on_pushButton_moveWithVelocity_clicked()
{
    QString errorCode;

    for(int i = 0; i < angularVelocity_leftHip.size(); i++){
        motor_left_hip->MoveWithVelocity(angularVelocity_leftHip.at(i)*20, &errorCode);
        motor_right_hip->MoveWithVelocity(-angularVelocity_rightHip.at(i)*20, &errorCode);
        motor_left_knee->MoveWithVelocity(angularVelocity_leftKnee.at(i)*20, &errorCode);
        motor_right_knee->MoveWithVelocity(-angularVelocity_rightKnee.at(i)*20, &errorCode);
    }
}

void MainWindow::on_actionActivate_Profile_Position_Mode_triggered()
{
    motor_left_hip->init(1, Max_profile_velocity, Max_following_error, Max_acceleration);
    motor_right_hip->init(2, Max_profile_velocity, Max_following_error, Max_acceleration);
    motor_left_knee->init(3, Max_profile_velocity, Max_following_error, Max_acceleration);
    motor_right_knee->init(4, Max_profile_velocity, Max_following_error, Max_acceleration);

    ui->pushButton_enable->setEnabled(true);
    ui->pushButton_disable->setEnabled(true);
}

void MainWindow::on_actionActivate_Profile_Velocity_Mode_triggered()
{
    motor_left_hip->init_profileVelocityMode(1, Max_profile_velocity, Max_following_error, Max_acceleration, Max_decceleration);
    motor_right_hip->init_profileVelocityMode(2, Max_profile_velocity, Max_following_error, Max_acceleration, Max_decceleration);
    motor_left_knee->init_profileVelocityMode(3, Max_profile_velocity, Max_following_error, Max_acceleration, Max_decceleration);
    motor_right_knee->init_profileVelocityMode(4, Max_profile_velocity, Max_following_error, Max_acceleration, Max_decceleration);

    ui->pushButton_enable->setEnabled(true);
    ui->pushButton_disable->setEnabled(true);
}

void MainWindow::on_actionStand_ver2_triggered()
{
    QString str_ErrorCode;
    bool motorEnableState = motor_left_hip->getEnableState(&str_ErrorCode) && motor_right_hip->getEnableState(&str_ErrorCode) && motor_left_knee->getEnableState(&str_ErrorCode) && motor_right_knee->getEnableState(&str_ErrorCode);
    double velocity = 700;
    double acceleration = 500;
    double decceleration = 500;
    double preStandAngle = 5;  //(degree)
    motor_left_hip->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_left_knee->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_right_hip->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_right_knee->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    if(motorEnableState){
        motor_left_hip->MoveToPosition(-90-preStandAngle, true, &str_ErrorCode);
        motor_right_hip->MoveToPosition(90+preStandAngle, true, &str_ErrorCode);
        Sleep(50);
        motor_left_hip->MoveToPosition(-90, true, &str_ErrorCode);
        motor_right_hip->MoveToPosition(90, true, &str_ErrorCode);
        motor_left_knee ->MoveToPosition(-5, true, &str_ErrorCode);
        motor_right_knee->MoveToPosition(5, true, &str_ErrorCode);
        motor_left_hip  ->MoveToPosition(0, true, &str_ErrorCode);
        motor_right_hip ->MoveToPosition(0, true, &str_ErrorCode);

    }
}

void MainWindow::on_actionSit_ver2_triggered()
{
    QString str_ErrorCode;
    bool motorEnableState = motor_left_hip->getEnableState(&str_ErrorCode) && motor_right_hip->getEnableState(&str_ErrorCode) && motor_left_knee->getEnableState(&str_ErrorCode) && motor_right_knee->getEnableState(&str_ErrorCode);
    double velocity = 700;
    double acceleration = 500;
    double decceleration = 500;
    double preSitAngle = 20;
    motor_left_hip->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_left_knee->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_right_hip->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    motor_right_knee->setPositionProfile(velocity, acceleration, decceleration, &str_ErrorCode);
    if(motorEnableState){
        motor_left_hip  ->MoveToPosition(-preSitAngle, true, &str_ErrorCode);
        motor_right_hip ->MoveToPosition(preSitAngle, true, &str_ErrorCode);
        Sleep(50);
        motor_left_hip  ->MoveToPosition(-90, true, &str_ErrorCode);
        motor_right_hip ->MoveToPosition(90, true, &str_ErrorCode);
        motor_left_knee ->MoveToPosition(-90, true, &str_ErrorCode);
        motor_right_knee->MoveToPosition(90, true, &str_ErrorCode);
    }
}
