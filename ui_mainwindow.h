/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Measurement;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionConnect_All;
    QAction *actionDisconnect_All;
    QAction *actionCalibration;
    QAction *actionJoint_Angle_Data;
    QAction *actionJoint_Angular_Velocity_Data;
    QAction *actionLeft_Foot;
    QAction *actionRight_Foot;
    QAction *actionStart_Timer;
    QAction *actionStart_Measurement;
    QAction *actionStop_Measurement;
    QAction *actionwaist;
    QAction *actionStand;
    QAction *actionSit;
    QAction *actionActivate_Profile_Position_Mode;
    QAction *actionActivate_Profile_Velocity_Mode;
    QAction *actionStand_ver2;
    QAction *actionSit_ver2;
    QWidget *centralWidget;
    QPushButton *pushButton_enable;
    QPushButton *pushButton_disable;
    QPushButton *pushButton_move;
    QLabel *label_left_hip_status;
    QLabel *label_right_hip_status;
    QLabel *label_left_knee_status;
    QLabel *label_right_knee_status;
    QLineEdit *lineEdit_gaitCadence;
    QLineEdit *lineEdit_stepSize;
    QLabel *label_motor_speed;
    QLabel *label_motor_speed_2;
    QPushButton *pushButton_move_withVelocity;
    QTabWidget *tabWidget;
    QWidget *JointAngleData;
    QCustomPlot *gait_monitor_1;
    QWidget *tab_4;
    QCustomPlot *gaitCadence_monitor;
    QWidget *tab;
    QCustomPlot *gaitEvent_left;
    QCustomPlot *gaitEvent_right;
    QWidget *tab_2;
    QCustomPlot *qcustomPlot_gaitCadence;
    QLabel *label_left_foot_IMU_status;
    QLabel *label_right_foot_IMU_status;
    QLabel *label_waist_IMU_status;
    QLabel *label_target_gaitCadence;
    QLineEdit *lineEdit_targetGaitCadence;
    QRadioButton *radioButton_walking;
    QRadioButton *radioButton_stairAcent;
    QRadioButton *radioButton_stairDecent;
    QPushButton *pushButton_threadTest;
    QPushButton *pushButton_stopThread;
    QPushButton *pushButton_moveWithVelocity;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen_Gait_Data;
    QMenu *menuExtras;
    QMenu *menuConnect_IMUs;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1037, 683);
        actionNew_Measurement = new QAction(MainWindow);
        actionNew_Measurement->setObjectName(QStringLiteral("actionNew_Measurement"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionConnect_All = new QAction(MainWindow);
        actionConnect_All->setObjectName(QStringLiteral("actionConnect_All"));
        actionDisconnect_All = new QAction(MainWindow);
        actionDisconnect_All->setObjectName(QStringLiteral("actionDisconnect_All"));
        actionCalibration = new QAction(MainWindow);
        actionCalibration->setObjectName(QStringLiteral("actionCalibration"));
        actionJoint_Angle_Data = new QAction(MainWindow);
        actionJoint_Angle_Data->setObjectName(QStringLiteral("actionJoint_Angle_Data"));
        actionJoint_Angular_Velocity_Data = new QAction(MainWindow);
        actionJoint_Angular_Velocity_Data->setObjectName(QStringLiteral("actionJoint_Angular_Velocity_Data"));
        actionLeft_Foot = new QAction(MainWindow);
        actionLeft_Foot->setObjectName(QStringLiteral("actionLeft_Foot"));
        actionRight_Foot = new QAction(MainWindow);
        actionRight_Foot->setObjectName(QStringLiteral("actionRight_Foot"));
        actionStart_Timer = new QAction(MainWindow);
        actionStart_Timer->setObjectName(QStringLiteral("actionStart_Timer"));
        actionStart_Measurement = new QAction(MainWindow);
        actionStart_Measurement->setObjectName(QStringLiteral("actionStart_Measurement"));
        actionStop_Measurement = new QAction(MainWindow);
        actionStop_Measurement->setObjectName(QStringLiteral("actionStop_Measurement"));
        actionwaist = new QAction(MainWindow);
        actionwaist->setObjectName(QStringLiteral("actionwaist"));
        actionStand = new QAction(MainWindow);
        actionStand->setObjectName(QStringLiteral("actionStand"));
        actionSit = new QAction(MainWindow);
        actionSit->setObjectName(QStringLiteral("actionSit"));
        actionActivate_Profile_Position_Mode = new QAction(MainWindow);
        actionActivate_Profile_Position_Mode->setObjectName(QStringLiteral("actionActivate_Profile_Position_Mode"));
        actionActivate_Profile_Velocity_Mode = new QAction(MainWindow);
        actionActivate_Profile_Velocity_Mode->setObjectName(QStringLiteral("actionActivate_Profile_Velocity_Mode"));
        actionStand_ver2 = new QAction(MainWindow);
        actionStand_ver2->setObjectName(QStringLiteral("actionStand_ver2"));
        actionSit_ver2 = new QAction(MainWindow);
        actionSit_ver2->setObjectName(QStringLiteral("actionSit_ver2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_enable = new QPushButton(centralWidget);
        pushButton_enable->setObjectName(QStringLiteral("pushButton_enable"));
        pushButton_enable->setEnabled(false);
        pushButton_enable->setGeometry(QRect(10, 10, 121, 31));
        QFont font;
        font.setFamily(QStringLiteral("Elephant"));
        font.setPointSize(11);
        pushButton_enable->setFont(font);
        pushButton_disable = new QPushButton(centralWidget);
        pushButton_disable->setObjectName(QStringLiteral("pushButton_disable"));
        pushButton_disable->setEnabled(false);
        pushButton_disable->setGeometry(QRect(150, 10, 201, 31));
        pushButton_disable->setFont(font);
        pushButton_move = new QPushButton(centralWidget);
        pushButton_move->setObjectName(QStringLiteral("pushButton_move"));
        pushButton_move->setGeometry(QRect(390, 500, 131, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Elephant"));
        font1.setPointSize(18);
        pushButton_move->setFont(font1);
        label_left_hip_status = new QLabel(centralWidget);
        label_left_hip_status->setObjectName(QStringLiteral("label_left_hip_status"));
        label_left_hip_status->setGeometry(QRect(370, 0, 111, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("Elephant"));
        font2.setPointSize(14);
        label_left_hip_status->setFont(font2);
        label_right_hip_status = new QLabel(centralWidget);
        label_right_hip_status->setObjectName(QStringLiteral("label_right_hip_status"));
        label_right_hip_status->setGeometry(QRect(500, 0, 131, 61));
        label_right_hip_status->setFont(font2);
        label_left_knee_status = new QLabel(centralWidget);
        label_left_knee_status->setObjectName(QStringLiteral("label_left_knee_status"));
        label_left_knee_status->setGeometry(QRect(640, 0, 121, 61));
        label_left_knee_status->setFont(font2);
        label_right_knee_status = new QLabel(centralWidget);
        label_right_knee_status->setObjectName(QStringLiteral("label_right_knee_status"));
        label_right_knee_status->setGeometry(QRect(770, 0, 131, 61));
        label_right_knee_status->setFont(font2);
        lineEdit_gaitCadence = new QLineEdit(centralWidget);
        lineEdit_gaitCadence->setObjectName(QStringLiteral("lineEdit_gaitCadence"));
        lineEdit_gaitCadence->setGeometry(QRect(240, 550, 121, 31));
        QFont font3;
        font3.setPointSize(17);
        lineEdit_gaitCadence->setFont(font3);
        lineEdit_stepSize = new QLineEdit(centralWidget);
        lineEdit_stepSize->setObjectName(QStringLiteral("lineEdit_stepSize"));
        lineEdit_stepSize->setGeometry(QRect(240, 590, 121, 31));
        label_motor_speed = new QLabel(centralWidget);
        label_motor_speed->setObjectName(QStringLiteral("label_motor_speed"));
        label_motor_speed->setGeometry(QRect(20, 550, 201, 31));
        label_motor_speed->setFont(font2);
        label_motor_speed_2 = new QLabel(centralWidget);
        label_motor_speed_2->setObjectName(QStringLiteral("label_motor_speed_2"));
        label_motor_speed_2->setGeometry(QRect(20, 590, 161, 31));
        label_motor_speed_2->setFont(font2);
        pushButton_move_withVelocity = new QPushButton(centralWidget);
        pushButton_move_withVelocity->setObjectName(QStringLiteral("pushButton_move_withVelocity"));
        pushButton_move_withVelocity->setGeometry(QRect(530, 500, 241, 71));
        QFont font4;
        font4.setFamily(QStringLiteral("Elephant"));
        font4.setPointSize(12);
        pushButton_move_withVelocity->setFont(font4);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 50, 861, 431));
        JointAngleData = new QWidget();
        JointAngleData->setObjectName(QStringLiteral("JointAngleData"));
        gait_monitor_1 = new QCustomPlot(JointAngleData);
        gait_monitor_1->setObjectName(QStringLiteral("gait_monitor_1"));
        gait_monitor_1->setGeometry(QRect(0, 0, 851, 411));
        tabWidget->addTab(JointAngleData, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gaitCadence_monitor = new QCustomPlot(tab_4);
        gaitCadence_monitor->setObjectName(QStringLiteral("gaitCadence_monitor"));
        gaitCadence_monitor->setGeometry(QRect(0, 0, 851, 411));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gaitEvent_left = new QCustomPlot(tab);
        gaitEvent_left->setObjectName(QStringLiteral("gaitEvent_left"));
        gaitEvent_left->setGeometry(QRect(0, 0, 851, 205));
        gaitEvent_right = new QCustomPlot(tab);
        gaitEvent_right->setObjectName(QStringLiteral("gaitEvent_right"));
        gaitEvent_right->setGeometry(QRect(0, 200, 851, 205));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        qcustomPlot_gaitCadence = new QCustomPlot(tab_2);
        qcustomPlot_gaitCadence->setObjectName(QStringLiteral("qcustomPlot_gaitCadence"));
        qcustomPlot_gaitCadence->setGeometry(QRect(0, 0, 851, 411));
        tabWidget->addTab(tab_2, QString());
        label_left_foot_IMU_status = new QLabel(centralWidget);
        label_left_foot_IMU_status->setObjectName(QStringLiteral("label_left_foot_IMU_status"));
        label_left_foot_IMU_status->setGeometry(QRect(880, 130, 121, 41));
        label_left_foot_IMU_status->setFont(font4);
        label_right_foot_IMU_status = new QLabel(centralWidget);
        label_right_foot_IMU_status->setObjectName(QStringLiteral("label_right_foot_IMU_status"));
        label_right_foot_IMU_status->setGeometry(QRect(880, 180, 131, 41));
        label_right_foot_IMU_status->setFont(font4);
        label_waist_IMU_status = new QLabel(centralWidget);
        label_waist_IMU_status->setObjectName(QStringLiteral("label_waist_IMU_status"));
        label_waist_IMU_status->setGeometry(QRect(880, 90, 101, 31));
        label_waist_IMU_status->setFont(font4);
        label_target_gaitCadence = new QLabel(centralWidget);
        label_target_gaitCadence->setObjectName(QStringLiteral("label_target_gaitCadence"));
        label_target_gaitCadence->setGeometry(QRect(20, 510, 201, 31));
        label_target_gaitCadence->setFont(font2);
        lineEdit_targetGaitCadence = new QLineEdit(centralWidget);
        lineEdit_targetGaitCadence->setObjectName(QStringLiteral("lineEdit_targetGaitCadence"));
        lineEdit_targetGaitCadence->setGeometry(QRect(240, 510, 121, 31));
        lineEdit_targetGaitCadence->setFont(font3);
        radioButton_walking = new QRadioButton(centralWidget);
        radioButton_walking->setObjectName(QStringLiteral("radioButton_walking"));
        radioButton_walking->setGeometry(QRect(880, 240, 101, 21));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial Unicode MS"));
        font5.setPointSize(12);
        radioButton_walking->setFont(font5);
        radioButton_stairAcent = new QRadioButton(centralWidget);
        radioButton_stairAcent->setObjectName(QStringLiteral("radioButton_stairAcent"));
        radioButton_stairAcent->setGeometry(QRect(880, 280, 111, 16));
        radioButton_stairAcent->setFont(font5);
        radioButton_stairDecent = new QRadioButton(centralWidget);
        radioButton_stairDecent->setObjectName(QStringLiteral("radioButton_stairDecent"));
        radioButton_stairDecent->setGeometry(QRect(880, 310, 111, 16));
        QFont font6;
        font6.setFamily(QStringLiteral("Arial"));
        font6.setPointSize(12);
        radioButton_stairDecent->setFont(font6);
        pushButton_threadTest = new QPushButton(centralWidget);
        pushButton_threadTest->setObjectName(QStringLiteral("pushButton_threadTest"));
        pushButton_threadTest->setGeometry(QRect(780, 500, 161, 71));
        QFont font7;
        font7.setFamily(QStringLiteral("Arial Black"));
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setWeight(75);
        pushButton_threadTest->setFont(font7);
        pushButton_stopThread = new QPushButton(centralWidget);
        pushButton_stopThread->setObjectName(QStringLiteral("pushButton_stopThread"));
        pushButton_stopThread->setGeometry(QRect(780, 580, 161, 51));
        pushButton_stopThread->setFont(font7);
        pushButton_moveWithVelocity = new QPushButton(centralWidget);
        pushButton_moveWithVelocity->setObjectName(QStringLiteral("pushButton_moveWithVelocity"));
        pushButton_moveWithVelocity->setEnabled(false);
        pushButton_moveWithVelocity->setGeometry(QRect(530, 580, 241, 51));
        QFont font8;
        font8.setFamily(QStringLiteral("Arial Black"));
        font8.setPointSize(16);
        font8.setBold(true);
        font8.setWeight(75);
        pushButton_moveWithVelocity->setFont(font8);
        MainWindow->setCentralWidget(centralWidget);
        pushButton_enable->raise();
        pushButton_disable->raise();
        pushButton_move->raise();
        label_left_hip_status->raise();
        label_right_hip_status->raise();
        label_left_knee_status->raise();
        label_right_knee_status->raise();
        lineEdit_gaitCadence->raise();
        lineEdit_stepSize->raise();
        label_motor_speed->raise();
        label_motor_speed_2->raise();
        pushButton_move_withVelocity->raise();
        label_left_foot_IMU_status->raise();
        label_right_foot_IMU_status->raise();
        label_waist_IMU_status->raise();
        tabWidget->raise();
        label_target_gaitCadence->raise();
        lineEdit_targetGaitCadence->raise();
        radioButton_walking->raise();
        radioButton_stairAcent->raise();
        radioButton_stairDecent->raise();
        pushButton_threadTest->raise();
        pushButton_stopThread->raise();
        pushButton_moveWithVelocity->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1037, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOpen_Gait_Data = new QMenu(menuFile);
        menuOpen_Gait_Data->setObjectName(QStringLiteral("menuOpen_Gait_Data"));
        menuExtras = new QMenu(menuBar);
        menuExtras->setObjectName(QStringLiteral("menuExtras"));
        menuConnect_IMUs = new QMenu(menuExtras);
        menuConnect_IMUs->setObjectName(QStringLiteral("menuConnect_IMUs"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuExtras->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(menuOpen_Gait_Data->menuAction());
        menuFile->addAction(actionNew_Measurement);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuOpen_Gait_Data->addAction(actionJoint_Angle_Data);
        menuOpen_Gait_Data->addAction(actionJoint_Angular_Velocity_Data);
        menuExtras->addAction(actionConnect_All);
        menuExtras->addAction(menuConnect_IMUs->menuAction());
        menuExtras->addAction(actionDisconnect_All);
        menuExtras->addSeparator();
        menuExtras->addAction(actionActivate_Profile_Position_Mode);
        menuExtras->addAction(actionActivate_Profile_Velocity_Mode);
        menuExtras->addSeparator();
        menuExtras->addAction(actionCalibration);
        menuExtras->addAction(actionStand);
        menuExtras->addAction(actionStand_ver2);
        menuExtras->addAction(actionSit);
        menuExtras->addAction(actionSit_ver2);
        menuExtras->addSeparator();
        menuExtras->addAction(actionStart_Timer);
        menuExtras->addAction(actionStart_Measurement);
        menuExtras->addAction(actionStop_Measurement);
        menuConnect_IMUs->addAction(actionLeft_Foot);
        menuConnect_IMUs->addAction(actionRight_Foot);
        menuConnect_IMUs->addAction(actionwaist);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew_Measurement->setText(QApplication::translate("MainWindow", "New Measurement", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save Measurement", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionConnect_All->setText(QApplication::translate("MainWindow", "Connect All Motor", 0));
        actionDisconnect_All->setText(QApplication::translate("MainWindow", "Disconnect All", 0));
        actionCalibration->setText(QApplication::translate("MainWindow", "Calibration", 0));
        actionJoint_Angle_Data->setText(QApplication::translate("MainWindow", "Joint Angle Data", 0));
        actionJoint_Angular_Velocity_Data->setText(QApplication::translate("MainWindow", "Joint Angular Velocity Data", 0));
        actionLeft_Foot->setText(QApplication::translate("MainWindow", "Left Foot", 0));
        actionRight_Foot->setText(QApplication::translate("MainWindow", "Right Foot", 0));
        actionStart_Timer->setText(QApplication::translate("MainWindow", "Start Timer", 0));
        actionStart_Measurement->setText(QApplication::translate("MainWindow", "Start IMUs Recording", 0));
        actionStop_Measurement->setText(QApplication::translate("MainWindow", "Stop IMUs Recording", 0));
        actionwaist->setText(QApplication::translate("MainWindow", "Waist", 0));
        actionStand->setText(QApplication::translate("MainWindow", "Stand", 0));
        actionSit->setText(QApplication::translate("MainWindow", "Sit", 0));
        actionActivate_Profile_Position_Mode->setText(QApplication::translate("MainWindow", "Activate Profile Position Mode", 0));
        actionActivate_Profile_Velocity_Mode->setText(QApplication::translate("MainWindow", "Activate Profile Velocity Mode", 0));
        actionStand_ver2->setText(QApplication::translate("MainWindow", "Stand_ver2", 0));
        actionSit_ver2->setText(QApplication::translate("MainWindow", "Sit_ver2", 0));
        pushButton_enable->setText(QApplication::translate("MainWindow", "Enable Motors", 0));
        pushButton_disable->setText(QApplication::translate("MainWindow", "Disable Motors (ctrl + D)", 0));
        pushButton_disable->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        pushButton_move->setText(QApplication::translate("MainWindow", "Move", 0));
        label_left_hip_status->setText(QApplication::translate("MainWindow", "   Left Hip", 0));
        label_right_hip_status->setText(QApplication::translate("MainWindow", "   Right Hip", 0));
        label_left_knee_status->setText(QApplication::translate("MainWindow", "   Left Knee", 0));
        label_right_knee_status->setText(QApplication::translate("MainWindow", "  Right Knee", 0));
        lineEdit_gaitCadence->setText(QString());
        label_motor_speed->setText(QApplication::translate("MainWindow", "Gait Cadence", 0));
        label_motor_speed_2->setText(QApplication::translate("MainWindow", "Step Size (%)", 0));
        pushButton_move_withVelocity->setText(QApplication::translate("MainWindow", "Move to Position with Velocity", 0));
        tabWidget->setTabText(tabWidget->indexOf(JointAngleData), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Tab 2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Page", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Page", 0));
        label_left_foot_IMU_status->setText(QApplication::translate("MainWindow", "Left Foot IMU", 0));
        label_right_foot_IMU_status->setText(QApplication::translate("MainWindow", "Right Foot IMU", 0));
        label_waist_IMU_status->setText(QApplication::translate("MainWindow", "Waist IMU", 0));
        label_target_gaitCadence->setText(QApplication::translate("MainWindow", "Target Gait Cadence", 0));
        lineEdit_targetGaitCadence->setText(QString());
        radioButton_walking->setText(QApplication::translate("MainWindow", "Walking", 0));
        radioButton_stairAcent->setText(QApplication::translate("MainWindow", "Stair Acent", 0));
        radioButton_stairDecent->setText(QApplication::translate("MainWindow", "Stair Decent", 0));
        pushButton_threadTest->setText(QApplication::translate("MainWindow", "RUN", 0));
        pushButton_stopThread->setText(QApplication::translate("MainWindow", "Stop", 0));
        pushButton_moveWithVelocity->setText(QApplication::translate("MainWindow", "Move with Velocity", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuOpen_Gait_Data->setTitle(QApplication::translate("MainWindow", "Open Gait Data", 0));
        menuExtras->setTitle(QApplication::translate("MainWindow", "Extras", 0));
        menuConnect_IMUs->setTitle(QApplication::translate("MainWindow", "Connect IMUs", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
