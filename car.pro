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
        r_costs.cpp \
    mainmenugui.cpp \
    newcar.cpp \
    newtank.cpp \
    reg_user.cpp \
    newrepair.cpp \
    r_workshop.cpp \
    admin.cpp \
    ed_user.cpp

HEADERS  += mainwindow.h \
    sql.h \
    r_costs.h \
    mainmenugui.h \
    newcar.h \
    newtank.h \
    reg_user.h \
    newrepair.h \
    r_workshop.h \
    admin.h \
    ed_user.h


FORMS += \
    r_costs.ui \
    mainwindow.ui \
    mainmenugui.ui \
    newcar.ui \
    newtank.ui \
    reg_user.ui \
    newrepair.ui \
    r_workshop.ui \
    admin.ui \
    ed_user.ui

RESOURCES += \
    gui_icons.qrc
