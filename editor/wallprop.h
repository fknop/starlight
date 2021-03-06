#ifndef WALLPROP_H
#define WALLPROP_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "model/wall.h"


/**
 * Panel permettant de modifier un mur.
 */
class WallProp : public PropertiesInterface
{
    Q_OBJECT

    QFormLayout * form_layout_;
    QLabel * x1_label_;
    QDoubleSpinBox * x1_dsb_;
    QLabel * y1_label_;
    QDoubleSpinBox * y1_dsb_;
    QLabel * x2_label_;
    QDoubleSpinBox * x2_dsb_;
    QLabel * y2_label_;
    QDoubleSpinBox * y2_dsb_;

    Wall * wall_;

public:
    /**
     * Constructeur du widget permettant d’éditer un mur.
     * @param wall le mur à modifier.
     * @param parent le widget parent.
     */
    WallProp(Wall * wall, QWidget * parent = 0);
    ~WallProp();

private:
    void setup_ui();

    /**
     * Applique les changements effectués à l’objet wall qu’il contient.
     */
    void apply() override;
    /**
     * Modifie les spinbox pour qu’elles prennent les valeurs du mur.
     */
    void reset() override;
};

#endif // WALLPROP_H
