QT += core gui opengl

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = pon_framework

# project build directories
DESTDIR     = $$system(pwd)
OBJECTS_DIR = $$DESTDIR/Obj
# C++ flags
QMAKE_CXXFLAGS_RELEASE =-O3

# Cuda sources
CUDA_SOURCES +=

unix {
# Path to cuda toolkit install
CUDA_DIR      = /opt/cuda
# Path to header and libs files
INCLUDEPATH  += $$CUDA_DIR/include
QMAKE_LIBDIR += $$CUDA_DIR/lib64
LIBS += -L/usr/local/lib -lGLU
}


# libs used in your code
LIBS += -lcudart -lcuda
# GPU architecture
CUDA_ARCH     = sm_35
# Here are some NVCC flags I've always used by default.
NVCCFLAGS     = --compiler-options -std=c++98 # -fno-strict-aliasing -use_fast_math --ptxas-options=-v


# Prepare the extra compiler configuration (taken from the nvidia forum - i'm not an expert in this part)
CUDA_INC = $$join(INCLUDEPATH,' -I','-I',' ')

cuda.commands = $$CUDA_DIR/bin/nvcc -m64 -O3 -arch=$$CUDA_ARCH -c $$NVCCFLAGS \
                $$CUDA_INC $$LIBS  ${QMAKE_FILE_NAME} -o ${QMAKE_FILE_OUT} \
                2>&1 | sed -r \"s/\\(([0-9]+)\\)/:\\1/g\" 1>&2
# nvcc error printout format ever so slightly different from gcc
# http://forums.nvidia.com/index.php?showtopic=171651

cuda.dependency_type = TYPE_C # there was a typo here. Thanks workmate!
cuda.depend_command = $$CUDA_DIR/bin/nvcc -O3 -M $$CUDA_INC $$NVCCFLAGS   ${QMAKE_FILE_NAME}

cuda.input = CUDA_SOURCES
cuda.output = ${OBJECTS_DIR}${QMAKE_FILE_BASE}_cuda.o
# Tell Qt that we want add more stuff to the Makefile
QMAKE_EXTRA_COMPILERS += cuda
DISTFILES +=

TEMPLATE = app

SOURCES += main.cpp \
    network.cpp \
    renderengine.cpp

HEADERS += \
    network.h \
    renderengine.h
