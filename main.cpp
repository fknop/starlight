//#include <iostream>

//#include "model/level.h"
//#include "MapReader.h"
//#include <typeinfo>
//#include "view/Game.hpp"
//#include <QApplication>

//using namespace std;


////int argc, char *argv[]
//int main(int argc, char * argv[])
//{
//    QApplication a(argc, argv);


//    Level * level = MapReader::getLevel("levels/level1.lvl");
//    level->computeRays();
//    GameView * game = new GameView(level);
//    game->show();
//    a.exec();

//    delete level;

//    return 0;

//}







#include <QApplication>
#include "view/MapView.h"
#include "MapReader.h"
#include <iostream>
#include <cmath>
#include "model/polarpoint.h"
#include "model/Geometry.h"
#include "model/ellipse.h"
#include "model/umath.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Level * level = MapReader::getLevel("levels/level1.lvl");
    //level->computeRays();


    LineSegment l (Point(0,0), Point(0, 30));
    Ellipse e(Point(20,20), 20, 10);

    std::vector<Point> points;

    if (int i = e.intersects(l, points))
    {
        std::cout << points.at(0) << std::endl;
        if (i == 2)
            std::cout << points.at(1) << std::endl;
    }



    return 0;

//    MapView box(level);
//    box.show();
//      return app.exec();
}
