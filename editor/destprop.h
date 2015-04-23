#ifndef DESTPROP_H
#define DESTPROP_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "model/dest.h"


/**
 * Panel permettant de modifier la destination.
 */
class DestProp : public PropertiesInterface
{
    Q_OBJECT
public:

    /**
     * Instancie un panel de propriétés pour la destination.
     * @param dest la destination.
     * @param parent le parent.
     */
    DestProp(Dest * dest, QWidget * parent = 0);
    ~DestProp();

private:
    QFormLayout * form_layout_;
    QLabel * x_label_;
    QDoubleSpinBox * x_dsb_;
    QLabel * y_label_;
    QDoubleSpinBox * y_dsb_;
    QLabel * edge_label_;
    QDoubleSpinBox * edge_dsb_;

    Dest * dest_;

    void setup_ui();

    /**
     * Applique les changements effectués à l’objet dest qu’il contient.
     */
    void apply() override;
    /**
     * Modifie les spinbox pour qu’elles prennent les valeurs de la destination.
     */
    void reset() override;
};

#endif // DESTPROP_H
