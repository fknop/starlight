QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = starlight
TEMPLATE = app


SOURCES += main.cpp \
    model/crystal.cpp \
    model/dest.cpp \
    model/lens.cpp \
    model/level.cpp \
    model/mirror.cpp \
    model/nuke.cpp \
    model/point.cpp \
    model/ray.cpp \
    model/source.cpp \
    model/wall.cpp \
    model/linesegment.cpp \
    model/ellipse.cpp \
    model/polarpoint.cpp \
    obs/observable.cpp \
    model/umath.cpp \
    model/element.cpp \
    model/rectangle.cpp \
    model/geometry.cpp \
    model/line.cpp \
    view/button.cpp \
    view/crystalview.cpp \
    view/destinationview.cpp \
    view/lensview.cpp \
    view/mainmenu.cpp \
    view/mapview.cpp \
    view/mirrorview.cpp \
    view/nukeview.cpp \
    view/sourceview.cpp \
    view/wallview.cpp \
    mapreader.cpp


HEADERS += \
    model/crystal.h \
    model/dest.h \
    model/lens.h \
    model/level.h \
    model/mirror.h \
    model/nuke.h \
    model/point.h \
    model/ray.h \
    model/source.h \
    model/wall.h \
    model/linesegment.h \
    model/ellipse.h \
    model/polarpoint.h \
    obs/observer.h \
    obs/observable.h \
    model/umath.h \
    model/element.h \
    model/rectangle.h \
    model/geometry.h \
    model/line.h \
    view/button.h \
    view/crystalview.h \
    view/destinationview.h \
    view/lensview.h \
    view/mainmenu.h \
    view/mapview.h \
    view/mirrorview.h \
    view/nukeview.h \
    view/sourceview.h \
    view/wallview.h \
    mapreader.h


FORMS +=

QMAKE_CXXFLAGS += -std=c++0x -Wall -Wextra -pedantic -fpermissive
