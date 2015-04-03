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
    //QApplication app(argc, argv);
    //Level * level = MapReader::level("levels/level1.lvl");


//    MapView box(&level);
//    box.show();
//    return app.exec();


    std::vector<Point> vectors
    {
                Point(4,4),
                Point(5,5),
                Point(2,2),
                Point(10,10),
                Point(15,15),
                Point(3,3),
                Point(6,6),
                Point(7,7),
                Point(1,1),
                Point(3,3),
                Point(9,9)
    };

    std::sort(vectors.begin(), vectors.end(),
        [](const Point& p1, const Point& p2) -> bool
    {
        double da = p1.distance(Point(0,0));
        double db = p2.distance(Point(0,0));
        return da < db;
    });

    for (auto &i : vectors)
        std::cout << i << std::endl;


    return 0;

}
#endif
