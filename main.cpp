#include <QApplication>
#include "view/MapView.h"
#include "MapReader.h"
#include <iostream>
#include <cmath>
#include "model/polarpoint.h"
#include "model/Geometry.h"
#include "model/ellipse.h"
#include "model/umath.h"
#include "view/mainmenu.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Level * level = MapReader::level("level1.lvl");





//    Game game;

//    game.show();
//    return app.exec();

//    Mirror r(Point(1,1), 0, 15, 1.5);
//    Element * e =  &r;
//    std::cout << e->isMirror();

    Ellipse e(Point(20,20), 20, 10);
    Line l(Point(0,0), - M_PI / 4);

//    std::vector<Point> points;
//    if (e.intersects(l, points) > 0) {
//        for (auto &i : points)
//        std::cout << i;
//    }

//     return 0;


    MapView box(level);
    box.show();
      return app.exec();
}
