#-------------------------------------------------
#
# Project created by QtCreator 2016-02-06T15:29:59
#
#-------------------------------------------------

QT       -= gui

TARGET = TraceServer
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    Sources/server.cpp

HEADERS += \
    includes/server.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}


macx:CONFIG(debug, debug|release) {
    DESTDIR = ../../libs/macx/debug
}
