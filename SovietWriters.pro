#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T13:33:15
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SovietWriters
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    points.cpp \
    writer.cpp

HEADERS  += mainwindow.h \
    main.h \
    points.h \
    writer.h \
    documentation.h \
    instructions.h

FORMS    += mainwindow.ui

RESOURCES += \
    WriterPhotos\pics.qrc
