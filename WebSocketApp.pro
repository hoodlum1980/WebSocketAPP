QT += core
QT -= gui

CONFIG += c++11

TARGET = WebSocketApp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    infothread.cpp \
    messageserver.cpp

LIBS += \
       -lboost_system\

INCLUDEPATH += /usr/include/websocketpp/

HEADERS += \
    infothread.h \
    echo_handler.h \
    messageserver.h

DISTFILES += \
    index.html \
    script.js
