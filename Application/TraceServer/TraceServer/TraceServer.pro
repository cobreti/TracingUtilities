#-------------------------------------------------
#
# Project created by QtCreator 2016-02-06T15:29:59
#
#-------------------------------------------------

QT       -= gui

TARGET = TraceServer
TEMPLATE = lib
CONFIG += staticlib

SOURCES += traceserver.cpp

HEADERS += traceserver.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}
