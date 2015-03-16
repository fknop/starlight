TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    metier_abs/wall.cpp \
    metier_abs/source.cpp \
    metier_abs/ray.cpp \
    metier_abs/point.cpp \
    metier_abs/nuke.cpp \
    metier_abs/mirror.cpp \
    metier_abs/level.cpp \
    metier_abs/lens.cpp \
    metier_abs/dest.cpp \
    metier_abs/crystal.cpp

HEADERS += \
    metier_abs/wall.h \
    metier_abs/source.h \
    metier_abs/ray.h \
    metier_abs/point.h \
    metier_abs/nuke.h \
    metier_abs/mirror.h \
    metier_abs/level.h \
    metier_abs/lens.h \
    metier_abs/dest.h \
    metier_abs/crystal.h

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic
