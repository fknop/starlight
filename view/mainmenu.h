#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsView>


class MainWindow;

/**
 * Représente le menu principal.
 */
class MainMenu : public QGraphicsView
{

    Q_OBJECT

public:
    MainMenu(QWidget * parent = NULL);
    ~MainMenu();

    void displayMainMenu();

    static const std::string STARLIGHT_RULES;

private:
    QGraphicsScene * scene_;
    MainWindow * main_window_;

public slots:
    void start();
    void help();
    void editor();
};



#endif // MAINMENU_H
