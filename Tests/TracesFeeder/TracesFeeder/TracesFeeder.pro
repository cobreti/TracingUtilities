#-------------------------------------------------
#
# Project created by QtCreator 2016-02-06T15:32:12
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TracesFeeder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sources/application.cpp \
    sources/outputItemMgr.cpp \
    sources/outputitem.cpp

HEADERS  += mainwindow.hpp \
    sources/application.hpp \
    sources/outputItemMgr.hpp \
    sources/outputitem.hpp

FORMS    += mainwindow.ui
