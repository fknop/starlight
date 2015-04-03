QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = starlight
TEMPLATE = app






FORMS +=

QMAKE_CXXFLAGS += -std=c++0x -Wall -Wextra -pedantic -fpermissive

HEADERS += \
    mapreader.h \
    model/crystal.h \
    model/dest.h \
    model/element.h \
    model/ellipse.h \
    model/geometry.h \
    model/lens.h \
    model/level.h \
    model/line.h \
    model/linesegment.h \
    model/mirror.h \
    model/nuke.h \
    model/point.h \
    model/polarpoint.h \
    model/ray.h \
    model/rectangle.h \
    model/source.h \
    model/umath.h \
    model/wall.h \
    obs/observable.h \
    obs/observer.h \
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
    Tests/catch.hpp \
    Tests/test.h

SOURCES += \
    mapreader.cpp \
    model/crystal.cpp \
    model/dest.cpp \
    model/element.cpp \
    model/ellipse.cpp \
    model/geometry.cpp \
    model/lens.cpp \
    model/level.cpp \
    model/line.cpp \
    model/linesegment.cpp \
    model/mirror.cpp \
    model/nuke.cpp \
    model/point.cpp \
    model/polarpoint.cpp \
    model/ray.cpp \
    model/rectangle.cpp \
    model/source.cpp \
    model/umath.cpp \
    model/wall.cpp \
    obs/observable.cpp \
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
    main.cpp \
    Tests/pointtest.cpp \
    Tests/intersectionstest.cpp
