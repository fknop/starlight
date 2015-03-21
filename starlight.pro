QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = starlight
TEMPLATE = app


SOURCES += main.cpp \
    MapReader.cpp \
    view/starlightui.cpp \
    model/crystal.cpp \
    model/dest.cpp \
    model/Geometry.cpp \
    model/lens.cpp \
    model/level.cpp \
    model/Line.cpp \
    model/mirror.cpp \
    model/nuke.cpp \
    model/point.cpp \
    model/ray.cpp \
    model/source.cpp \
    model/wall.cpp \
    linesegment.cpp \
    view/Button.cpp \
    view/MainMenu.cpp

HEADERS += \
    MapReader.h \
    view/starlightui.hpp \
    model/crystal.h \
    model/dest.h \
    model/Geometry.h \
    model/lens.h \
    model/level.h \
    model/Line.h \
    model/mirror.h \
    model/nuke.h \
    model/point.h \
    model/ray.h \
    model/source.h \
    model/wall.h \
    linesegment.h \
    view/Button.h \
    view/MainMenu.h

FORMS += \
    view/starlightui.ui

QMAKE_CXXFLAGS += -std=c++0x -Wall -Wextra -pedantic
