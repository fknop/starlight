QT += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = starlight
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x -Wall -Wextra -pedantic -fpermissive -Wno-unused

HEADERS += \
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
    tests/catch.hpp \
    tests/test.h \
    view/rayview.h \
    obs/observerinterface.h \
    view/mainwindow.h \
    editor/maineditor.h \
    editor/properties.h \
    editor/mirrorprop.h \
    editor/elements.h \
    editor/propertiesinterface.h \
    view/elementview.h \
    editor/crystalprop.h \
    editor/lensprop.h \
    editor/nukeprop.h \
    editor/wallprop.h \
    editor/sourceprop.h \
    editor/destprop.h \
    utils/constants.h \
    utils/mapreader.h \
    utils/mapwriter.h \
    utils/umath.h

SOURCES += \
    model/crystal.cpp \
    model/dest.cpp \
    model/ellipse.cpp \
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
    tests/pointtest.cpp \
    tests/intersectionstest.cpp \
    view/rayview.cpp \
    tests/sortpointtest.cpp \
    view/mainwindow.cpp \
    editor/maineditor.cpp \
    editor/properties.cpp \
    editor/mirrorprop.cpp \
    editor/elements.cpp \
    tests/gametest.cpp \
    view/elementview.cpp \
    editor/crystalprop.cpp \
    editor/lensprop.cpp \
    editor/nukeprop.cpp \
    editor/wallprop.cpp \
    editor/sourceprop.cpp \
    editor/destprop.cpp \
    utils/mapreader.cpp \
    utils/mapwriter.cpp \
    utils/umath.cpp \
    tests/umathtest.cpp

RESOURCES += \
    ressources.qrc
