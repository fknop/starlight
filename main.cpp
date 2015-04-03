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
#include "model/constants.h"

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

    Line l(Point(5,5), -M_PI_2);
    Point p(5,6);
    std::cout << Geometry::is_on_good_side(l, p);

    return 0;

}
#endif
