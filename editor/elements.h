#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include "model/level.h"

#include "obs/observable.h"


/**
 * Permet de créer un niveau et d’y ajouter des éléments (miroir, lensille, etc.).
 */
class Elements : public QWidget, public Observable
{
    Q_OBJECT

    QVBoxLayout * vertical_layout_;
    QGroupBox * group_box_;
    QLabel * level_height_label_;
    QLabel * level_width_label_;
    QPushButton * level_apply_pb_;
    QPushButton * level_reset_pb_;
    QDoubleSpinBox * level_height_dsb_;
    QDoubleSpinBox * level_width_dsb_;
    QPushButton * add_crystal_pb_;
    QPushButton * add_mirror_pb_;
    QPushButton * add_nuke_pb_;
    QPushButton * add_lens_pb_;
    QPushButton * add_wall_pb_;

    Level * level_;

public:

    /**
     * Instancie un panel permettant de créer des éléments.
     * @param parent le parent.
     */
    explicit Elements(QWidget * parent = 0);

    /**
     * Retourne le niveau instancié par le panel.
     * @return le niveau.
     */
    Level * level();

    /**
     * Modifie la valeur du SpinBox pour la hauteur.
     * @param h la hauteur.
     */
    void set_height(int h);

    /**
     * Modifie la valeur du SpinBox pour la longueur.
     * @param w la longueur.
     */
    void set_width(int w);

    /**
     * Active les boutons du panel.
     * @param b vrai si les boutons sont activés, faux sinon.
     */
    void enable_pushbuttons(bool b);

private:
    void setup_ui();
    void add_connections();

public slots:

    /**
     * Notifie les observateurs de l'ajout d'un cristal.
     */
    void add_crystal();

    /**
     * Notifie les observateurs de l'ajout d'une lentille.
     */
    void add_lens();

    /**
     * Notifie les observateurs de l'ajout d'un miroir.
     */
    void add_mirror();

    /**
     * Notifie les observateurs de l'ajout d'une bombe.
     */
    void add_nuke();

    /**
     * Notifie les observateurs de l'ajout d'un mur.
     */
    void add_wall();

    /**
     * Notifie les observateurs de la création d'un niveau.
     */
    void create_level();

    /**
     * Notifie les observateurs de la supression d'un niveau.
     */
    void reset_level();
};

#endif // ELEMENTS_H
