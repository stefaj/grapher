QT += core gui opengl

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = pon_framework

# project build directories
DESTDIR     = $$system(pwd)
OBJECTS_DIR = $$DESTDIR/Obj
# C++ flags
QMAKE_CXXFLAGS_RELEASE =-O3

TEMPLATE = app

SOURCES += main.cpp \
    network.cpp \
    renderengine.cpp

HEADERS += \
    network.h \
    renderengine.h
