#include <iostream>

#include "model/level.h"
#include "MapReader.h"
#include <typeinfo>
#include "view/Game.hpp"
#include <QApplication>

using namespace std;

//int argc, char *argv[]
int main(int argc, char * argv[])
{


    QApplication a(argc, argv);


    MapReader map("levels/level1.lvl");

    Level * level = map.getLevel();
    level->computeRays();
    GameView * game = new GameView(level);
    game->show();
    a.exec();

    delete level;

    return 0;



}

