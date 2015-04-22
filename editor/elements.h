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
 * @param parent le widget parent, la fenêtre principale de l’éditeur en l’occurrence.
 */
class Elements : public QWidget, public Observable
{
    Q_OBJECT
public:
    explicit Elements(QWidget * parent = 0);
    Level * level();

    void set_height(int h);
    void set_width(int w);

    void enable_pushbuttons(bool b);

private:
    void setup_ui();
    void add_connections();

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


signals:

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
     * Crée un nouveau niveau avec les dimensions précisées.
     */
    void create_level();
    /**
     * Supprime le niveau actuel.
     */
    void reset_level();

};

#endif // ELEMENTS_H
