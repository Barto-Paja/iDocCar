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
        r_costs.cpp

HEADERS  += mainwindow.h \
    sql.h \
    r_costs.h

FORMS += \
    r_costs.ui \
    mainwindow.ui

RESOURCES += \
    gui_icons.qrc
