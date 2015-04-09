#include <QApplication>

#include "view/mainmenu.h"
#include "Tests/test.h"
#include "editor/maineditor.h"


#include "mapreader.h"
#include "mapwriter.h"
#ifndef RUNTEST
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
//    MainMenu * game = new MainMenu();
//    game->show();
//    game->displayMainMenu();
    MainEditor * editor = new MainEditor();
    editor->show();
    return app.exec();


}
#endif
