#include <QApplication>

#include "view/mainmenu.h"
#include "tests/test.h"

#include "model/linesegment.h"
#ifndef RUNTEST
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MainMenu * game = new MainMenu();
    game->show();
    game->displayMainMenu();

    return app.exec();

//    LineSegment l(Point(4,4), Point(8,8));
//    l.rotate(Point(4,4), PI);
//    std::cout << l.start();
//    std::cout << l.end();
//    l.rotate(Point(4,4), PI);
//    std::cout << l.start();
//    std::cout << l.end();
//    return 0;
}
#endif
