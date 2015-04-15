#include <QApplication>

#include "view/mainmenu.h"
#include "Tests/test.h"

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
