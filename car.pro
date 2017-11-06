#-------------------------------------------------
#
# Project created by QtCreator 2017-11-06T18:57:26
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = car
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    r_costs.cpp

HEADERS  += mainwindow.h \
    r_costs.h

FORMS += \
    ui_mainwindow.ui \
    r_costs.ui
