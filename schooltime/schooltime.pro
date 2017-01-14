#-------------------------------------------------
#
# Project created by QtCreator 2014-12-25T14:46:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = schooltime
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


win32: LIBS += -L$$PWD/ -lschooltime_library

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/schooltime_library.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/libschooltime_library.a
