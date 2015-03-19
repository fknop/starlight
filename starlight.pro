QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = starlight
TEMPLATE = app


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
    metier_abs/crystal.cpp \
    MapReader.cpp \
    view/starlightui.cpp \
    Geometry.cpp \
    Line.cpp

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
    metier_abs/crystal.h \
    MapReader.h \
    view/starlightui.hpp \
    Geometry.h \
    Line.h

FORMS += \
    view/starlightui.ui

QMAKE_CXXFLAGS += -std=c++0x -Wall -Wextra -pedantic
