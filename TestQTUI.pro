#-------------------------------------------------
#
# Project created by QtCreator 2011-07-25T10:25:22
#
#-------------------------------------------------

QT       += core gui

TARGET = TestQTUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    alarmpage.cpp \
    mappredefinedpage.cpp \
    alarmmanage.cpp \
    carmanagepage.cpp \
    dashboarditem.cpp \
    realtimeinfoview.cpp \
    realtimepage.cpp \
    flowlayout.cpp \
    buttonwidget.cpp \
    curveitem.cpp

HEADERS  += mainwindow.h \
    alarmpage.h \
    mappredefinedpage.h \
    alarmmanage.h \
    carmanagepage.h \
    dashboarditem.h \
    realtimeinfoview.h \
    realtimepage.h \
    flowlayout.h \
    buttonwidget.h \
    curveitem.h

TRANSLATIONS = arrowpad_cn.ts


SHARED_FOLDER = ../shared

include($$SHARED_FOLDER/shared.pri)

OTHER_FILES +=
