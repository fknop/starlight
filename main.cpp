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


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Level * level = MapReader::getLevel("levels/level1.lvl");
    level->computeRays();

    GraphicsView box(level);
    box.show();

    Point p1(0, 0);
    Point p2(1,1);
    double distance = Point(0,0).distance(p2);
    std::cout << distance << std::endl;
    double angle = std::acos(p2.getX() / distance);
    double angle2 = std::atan2(1,1);
    std::cout << angle << " " << angle2;
    return app.exec();
}
