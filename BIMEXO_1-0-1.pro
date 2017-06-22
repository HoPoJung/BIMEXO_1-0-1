#-------------------------------------------------
#
# Project created by QtCreator 2016-08-09T14:54:18
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BIMEXO_1-0-1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    my_maxon_motor.cpp \
    qcustomplot.cpp \
    movemotor_thread.cpp

HEADERS  += mainwindow.h \
    my_maxon_motor.h \
    qcustomplot.h \
    movemotor_thread.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$quote(D:\NTU_Graduate_school\BBLab\Exoskeleton robot\Program\BIMEXO_1-0-1) \
                $$quote(C:\OpenMAT\OpenMAT-1.3.5\include)

LIBS += $$quote(E:\NTU_Graduate_school\BBLab\Exoskeleton robot\Program\BIMEXO_1-0-1\release\EposCmd.lib)\
        $$quote(C:\OpenMAT\OpenMAT-1.3.5\lib\x86\LpSensor.lib) \
        $$quote(C:\OpenMAT\OpenMAT-1.3.5\lib\x86\LpSensorD.lib)
