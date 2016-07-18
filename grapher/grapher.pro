QT += core gui opengl

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = grapher.out

# project build directories
DESTDIR     = $$system(pwd)
OBJECTS_DIR = $$DESTDIR/Obj
# C++ flags
QMAKE_CXXFLAGS_RELEASE =-O3

TEMPLATE = app

SOURCES += main.cpp \
    renderengine.cpp

HEADERS += \
    renderengine.h

LIBS += -L/usr/local/lib -lGLU
