QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = starlight
TEMPLATE = app


SOURCES += main.cpp \
    MapReader.cpp \
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
    model/linesegment.cpp \
    view/Button.cpp \
    view/MainMenu.cpp \
    view/WallView.cpp \
    view/MapView.cpp \
    view/MirrorView.cpp \
    model/ellipse.cpp \
    view/SourceView.cpp \
    view/DestinationView.cpp \
    model/polarpoint.cpp \
    obs/observable.cpp \
    model/umath.cpp \
    view/NukeView.cpp


HEADERS += \
    MapReader.h \
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
    model/linesegment.h \
    view/Button.h \
    view/MainMenu.h \
    view/WallView.h \
    view/MirrorView.h \
    view/MapView.h \
    model/ellipse.h \
    view/SourceView.h \
    view/DestinationView.h \
    model/polarpoint.h \
    obs/observer.h \
    obs/observable.h \
    model/umath.h \
    view/NukeView.h


FORMS +=

QMAKE_CXXFLAGS += -std=c++0x -Wall -Wextra -pedantic -fpermissive
