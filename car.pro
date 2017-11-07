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
        sql.cpp \
        r_costs.h

HEADERS  += mainwindow.h \
    sql.h \
    r_costs.h

FORMS += \
    ui_mainwindow.ui \
    r_costs.ui
