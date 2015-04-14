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

//    Line line(Point{-2.38, -1.62}, 0.4644210041);
//    Ellipse e(Point(3., 3.), 2.5862714475,2.5862714475);

//    std::vector<Point> points;
//    std::cout << Geometry::intersects(e, line, points);

    // Cercle de centre 3, 3 et de rayon 2.5862714475


}
#endif
