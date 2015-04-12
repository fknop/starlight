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
//    Line l(Point(0,0), Point(5,5));
//    Line l2(Point(5,0), M_PI_4);
//    Point p;
//    bool b;
//    bool i = Geometry::intersects(l, l2, p, b);

//    return 0;


}
#endif
