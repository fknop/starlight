#include <iostream>

#include "model/level.h"
#include "MapReader.h"
#include <typeinfo>
#include "view/Game.hpp"
#include <QApplication>

using namespace std;

void test(Level *l)
{
    l = new Level(5,5);
    std::cout << l->getHeight() << std::endl;
}

//int argc, char *argv[]
int main(int argc, char * argv[])
{
    Level *l = nullptr;

    test(l);

    std::cout << l->getHeight() << std::endl;


    //QApplication a(argc, argv);


    //MapReader map("levels/level1.lvl");

    //Level * level = MapReader::getLevel("levels/level1.lvl");
    //level->computeRays();
//    GameView * game = new GameView(level);
//    game->show();
//    a.exec();



    //delete level;

    return 0;

}

