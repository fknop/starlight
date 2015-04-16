QT += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = starlight
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x -Wall -Wextra -pedantic -fpermissive

HEADERS += \
    mapreader.h \
    model/crystal.h \
    model/dest.h \
    model/element.h \
    model/ellipse.h \
    model/lens.h \
    model/level.h \
    model/line.h \
    model/linesegment.h \
    model/mirror.h \
    model/nuke.h \
    model/point.h \
    model/ray.h \
    model/rectangle.h \
    model/source.h \
    model/umath.h \
    model/wall.h \
    obs/observable.h \
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
    Tests/test.h \
    model/constants.h \
    view/rayview.h \
    obs/observerinterface.h \
    view/mainwindow.h \
    editor/maineditor.h \
    editor/properties.h \
    editor/mirrorprop.h \
    mapwriter.h \
    editor/elements.h \
    editor/propertiesinterface.h \
    view/elementview.h \
    editor/crystalprop.h \
    editor/lensprop.h \
    editor/nukeprop.h \
    editor/wallprop.h \
    editor/sourceprop.h \
    editor/destprop.h

SOURCES += \
    mapreader.cpp \
    model/crystal.cpp \
    model/dest.cpp \
    model/ellipse.cpp \
    model/umath.cpp \
    model/lens.cpp \
    model/level.cpp \
    model/line.cpp \
    model/linesegment.cpp \
    model/mirror.cpp \
    model/nuke.cpp \
    model/point.cpp \
    model/ray.cpp \
    model/rectangle.cpp \
    model/source.cpp \
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
    Tests/intersectionstest.cpp \
    view/rayview.cpp \
    Tests/sortpointtest.cpp \
    view/mainwindow.cpp \
    editor/maineditor.cpp \
    editor/properties.cpp \
    editor/mirrorprop.cpp \
    mapwriter.cpp \
    editor/elements.cpp \
    Tests/gametest.cpp \
    view/elementview.cpp \
    editor/crystalprop.cpp \
    editor/lensprop.cpp \
    editor/nukeprop.cpp \
    editor/wallprop.cpp \
    editor/sourceprop.cpp \
    editor/destprop.cpp

RESOURCES += \
    ressources.qrc
