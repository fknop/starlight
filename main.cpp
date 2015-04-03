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
//    QApplication app(argc, argv);
//    Level * level = MapReader::level("levels/level1.lvl");
//    level->compute_rays();
//    MapView box(level);
//    box.show();
//    return app.exec();

    Point p(3, 17);
    PolarPoint pp(p);


    std::cout << pp << std::endl;
    std::cout << pp.to_point() << std::endl;
    return 0;

}
