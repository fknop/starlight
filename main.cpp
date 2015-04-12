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
//    Line l(Point(0.4,4), 0);
//    LineSegment l2(Point(4.2,0.3), Point(4.2,10.2));
//    Point p;
//    LineSegment seg;
//    bool b;
//    bool i = Geometry::intersects(l, l2, p, seg, b);
//    std::cout << p;
//    return 0;



}
#endif
