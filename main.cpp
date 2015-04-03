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

#include "Tests/test.h"

#ifndef RUNTEST
int main(int argc, char **argv)
{
//    QApplication app(argc, argv);
//    Level * level = MapReader::level("levels/level1.lvl");
//    level->compute_rays();
//    MapView box(level);
//    box.show();
//    return app.exec();

    Line l(Point(0,0),  -M_PI_4);
    std::cout << Geometry::rad_to_slope(l.angle());
    return 0;

}
#endif
