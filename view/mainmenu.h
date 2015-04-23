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
    /**
     * Lance la fenetre dédiée au jeu.
     */
    void start();
    /**
     * Affiche l’aide du jeu.
     */
    void help();
    /**
     * Lance l’éditeur de carte.
     */
    void editor();
};



#endif // MAINMENU_H
