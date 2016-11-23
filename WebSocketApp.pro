QT += core
QT -= gui

CONFIG += c++11

TARGET = WebSocketApp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    infothread.cpp

LIBS += \
       -lboost_system\

INCLUDEPATH += /usr/include/websocketpp/

HEADERS += \
    echo_handler.hpp \
    infothread.h

DISTFILES += \
    index.html \
    script.js
