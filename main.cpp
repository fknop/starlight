#include <QApplication>

#include "view/mainmenu.h"
#include "tests/test.h"

#include "model/line.h"
#include "utils/umath.h"
#include <iostream>


#ifndef RUNTEST
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MainMenu * game = new MainMenu();
    game->show();
    game->displayMainMenu();

    return app.exec();
}
#endif
