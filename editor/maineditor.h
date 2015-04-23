#ifndef MAINEDITOR_H
#define MAINEDITOR_H

#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QMainWindow>

#include "editor/elements.h"
#include "editor/properties.h"

#include "model/level.h"

#include "obs/observerinterface.h"

#include "view/mapview.h"


/**
 * Fenêtre principale de l’éditeur.
 */
class MainEditor : public QMainWindow, public ObserverInterface
{
    Q_OBJECT

    QWidget * parent_;
    QMenuBar * menu_bar_;
    QMenu * file_menu_;
    QAction * load_level_action_;
    QAction * save_level_action_;
    QAction * back_menu_action_;
    QAction * quit_action_;
    QAction * help_action_;

    QWidget * central_widget_;
    QHBoxLayout * horizontal_layout_;
    Elements * elements_;
    QVBoxLayout * vertical_layout_1_;

    MapView * mapview_;
    QVBoxLayout * vertical_layout_2_;
    Properties * properties_;

    Level * level_;

public:
    /**
     * Constructeur par défaut de l’éditeur de carte.
     * @param parent la classe parent, normalement le menu principal du jeu.
     */
    explicit MainEditor(QWidget * parent = 0);

private:
    ElementView * selected();

    void setup_ui();

    void closeEvent(QCloseEvent * event) override;
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>()) override;

public slots:
    /**
     * Ajoute un cristal au niveau.
     */
    void add_crystal();
    /**
     * Ajoute une lentille au niveau.
     */
    void add_lens();
    /**
     * Ajoute un miroir au niveau.
     */
    void add_mirror();
    /**
     * Ajoute une bombe au niveau.
     */
    void add_nuke();
    /**
     * Ajoute un mur au niveau.
     */
    void add_wall();

    /**
     * Crée un nouveau niveau.
     * @param width la longueur de la carte.
     * @param height la hauteur de la carte.
     */
    void create_level(int width, int height);
    /**
     * Charge un niveau existant depuis un fichier.
     */
    void load_level();
    /**
     * Sauve le niveau dans un fichier.
     */
    void save_level();
    /**
     * Retourne au menu principal.
     */
    void back_menu();
    /**
     * Ferme l’éditeur avec un message de confirmation.
     */
    void quit();
    /**
     * Supprime l’élément sélectionné du niveau.
     */
    void delete_selected();
};

#endif // MAINEDITOR_H
