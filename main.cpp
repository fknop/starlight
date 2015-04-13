#include <QApplication>

#include "view/mainmenu.h"
#include "Tests/test.h"
#include "editor/maineditor.h"


#include "mapreader.h"
#include "mapwriter.h"
#include <sstream>
#include <vector>
#include "model/geometry.h"
#include <cmath>
#include <iostream>
#ifndef RUNTEST
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainMenu * game = new MainMenu();
    game->show();
    game->displayMainMenu();
    return app.exec();

//    LineSegment result;
//    Point p;
//    bool is_point, do_intersect;
//    LineSegment ls1(Point(4,4), Point(8,8));
//    LineSegment ls2(Point(0,0), Point(3,3));
//    do_intersect = Geometry::intersects(ls1, ls2, p, result, is_point);

//    return 0;



}
#endif
