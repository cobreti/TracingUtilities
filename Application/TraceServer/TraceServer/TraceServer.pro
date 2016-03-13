#-------------------------------------------------
#
# Project created by QtCreator 2016-02-06T15:29:59
#
#-------------------------------------------------

CONFIG += c++11

QT      -= gui
QT      += network

TARGET = TraceServer
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    Sources/server.cpp \
    Sources/inputblock.cpp \
    Sources/inputblockmgr.cpp \
    Sources/networkutility.cpp \
    Sources/tcpinputblock.cpp \
    Sources/socketreceiver.cpp \
    Sources/dataparser.cpp \
    Sources/timestamptraceformater.cpp \
    Sources/rawtrace.cpp \
    Sources/primarystorage.cpp \
    Sources/messagebus.cpp \
    Sources/monitors/connectionsmonitor.cpp

HEADERS += \
    includes/server.hpp \
    includes/inputblock.hpp \
    includes/inputblockmgr.hpp \
    includes/exceptions/itemalreadyexistsincontainer.hpp \
    includes/exceptions/iteminsertionfailure.hpp \
    includes/networkutility.hpp \
    includes/tcpinputblock.hpp \
    includes/socketreceiver.hpp \
    includes/databuffer.hpp \
    includes/dataparser.hpp \
    includes/timestamptraceformater.hpp \
    includes/rawtrace.hpp \
    includes/primarystorage.hpp \
    includes/messagebus.hpp \
    includes/monitors/connectionsmonitor.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += ./includes

macx:CONFIG(debug, debug|release) {
    DESTDIR = ../../libs/macx/debug
}

win32:CONFIG(debug, debug|release) {
    DESTDIR = ../../libs/win32/debug
}

