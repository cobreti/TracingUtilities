#-------------------------------------------------
#
# Project created by QtCreator 2016-02-06T15:31:26
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TraceClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MonitorPanelWidget.cpp \
    sources/MonitorPanel.cpp \
    sources/TraceClientApp.cpp \
    sources/MonitorPanelMsgHandler.cpp

HEADERS  += mainwindow.hpp \
    MainWindow.h \
    MonitorPanelWidget.hpp \
    sources/MonitorPanel.hpp \
    sources/TraceClientApp.hpp \
    sources/MonitorPanelMsgHandler.hpp

FORMS    += mainwindow.ui \
    MonitorPanelWidget.ui

macx:CONFIG(debug, debug|release) {
    LIBS += -L../../libs/macx/debug -lTraceServer
}

win32:CONFIG(debug, debug|release) {
    LIBS += -L../../libs/win32/debug -lTraceServer
}


INCLUDEPATH += ../../TraceServer/TraceServer/includes
