#ifndef LENSPROP_H
#define LENSPROP_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "model/lens.h"


/**
 * Modifie la lentille sélectionnée dans l’éditeur.
 */
class LensProp : public PropertiesInterface
{
    Q_OBJECT

    QFormLayout * form_layout_;
    QLabel * x_label_;
    QDoubleSpinBox * x_dsb_;
    QLabel * y_label_;
    QDoubleSpinBox * y_dsb_;
    QLabel * width_label_;
    QDoubleSpinBox * width_dsb_;
    QLabel * height_label_;
    QDoubleSpinBox * height_dsb_;

    QLabel * wl_min_label_;
    QDoubleSpinBox * wl_min_dsb_;
    QLabel * wl_max_label_;
    QDoubleSpinBox * wl_max_dsb_;

    Lens * lens_;

public:
    LensProp(Lens * lens, QWidget * parent = 0);
    ~LensProp();

private:
    void setup_ui();

    /**
     * Applique les changements effectués à l’objet lens qu’il contient.
     */
    void apply() override;
    /**
     * Modifie les spinbox pour qu’elles prennent les valeurs de la lentille.
     */
    void reset() override;
};

#endif // LENSPROP_H
