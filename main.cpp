#include <QApplication>

#include "view/mainmenu.h"
#include "Tests/test.h"
#include "editor/maineditor.h"


#include "mapreader.h"
#include "mapwriter.h"
#include <sstream>
#include <vector>
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

//    LineSegment l(Point(4,4), Point(8,8));
//    l.rotate(Point(4,4), 0);

//    std::cout << l.start();
//    std::cout << l.end();


//    return 0;
}
#endif
