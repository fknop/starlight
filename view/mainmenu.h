#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsView>
#include <QGraphicsScene>

class MainMenu : public QGraphicsView
{

    Q_OBJECT

public:
    MainMenu(QWidget * parent = NULL);
    ~MainMenu();

    void displayMainMenu();

private:
    QGraphicsScene * scene_;
    MainWindow * main_window_;

public slots:
    void start();
    void help();
};



#endif // MAINMENU_H
