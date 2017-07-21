#-------------------------------------------------
#
# Project created by QtCreator 2017-07-18T21:58:45
#
#-------------------------------------------------

QT       += core gui network

TARGET = Intelligent
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialservice.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp \
    enddevice.cpp \
    motor.cpp \
    temp_humi_ligh.cpp \
    camerainit.cpp \
    video.cpp \
    pwm.cpp \
    smoke.cpp \
    pir.cpp

HEADERS  += mainwindow.h \
    serialservice.h \
    qextserialbase.h \
    posix_qextserialport.h \
    enddevice.h \
    motor.h \
    constant.h\
    temp_humi_ligh.h \
    camerainit.h \
    video.h \
    constant.h \
    pwm.h \
    smoke.h \
    pir.h

FORMS    += mainwindow.ui \
            video.ui
