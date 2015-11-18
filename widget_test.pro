#-------------------------------------------------
#
# Project created by QtCreator 2015-09-25T16:13:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widget_test
TEMPLATE = app
CONFIG += -static


SOURCES += main.cpp\
        mainwindow.cpp \
    logprocess.cpp \
    countnumber.cpp \
    directoryoperation.cpp

HEADERS  += mainwindow.h \
    test.h \
    processinginfo.h \
    logprocess.h \
    countnumber.h \
    directoryoperation.h \

FORMS    += mainwindow.ui
