#include <QApplication>
#include "view/mapview.h"
#include "mapreader.h"
#include <iostream>
#include <cmath>
#include "model/polarpoint.h"
#include "model/geometry.h"
#include "model/ellipse.h"
#include "model/umath.h"
#include "view/mainmenu.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Level * level = MapReader::level("levels/level1.lvl");





    Ellipse e(Point(20,20), 20, 10);
    Line l(Point(0,0), - M_PI / 4);




    MapView box(level);
    box.show();
    return app.exec();
}
