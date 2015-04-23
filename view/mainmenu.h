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

    /**
     * Instancie le menu principal.
     * @param parent le parent.
     */
    MainMenu(QWidget * parent = nullptr);
    ~MainMenu();

    /**
     * Affiche le menu principal.
     */
    void displayMainMenu();

private:
    QGraphicsScene * scene_;

public slots:
    void start();
    void help();
    void editor();
};



#endif // MAINMENU_H
