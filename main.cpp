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

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Level * level = MapReader::getLevel("levels/level1.lvl");
    level->computeRays();

    GraphicsView box(level);
    box.show();


    return app.exec();
}
