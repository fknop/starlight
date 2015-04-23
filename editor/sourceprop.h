#ifndef SOURCEPROP_H
#define SOURCEPROP_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "model/source.h"


/**
 * Panel permettant de modifier la source.
 */
class SourceProp : public PropertiesInterface
{
    Q_OBJECT

    QFormLayout * form_layout_;
    QLabel * x_label_;
    QDoubleSpinBox * x_dsb_;
    QLabel * y_label_;
    QDoubleSpinBox * y_dsb_;
    QLabel * edge_label_;
    QDoubleSpinBox * alpha_dsb_;
    QLabel * alpha_label_;
    QDoubleSpinBox * edge_dsb_;
    QLabel * wavelength_label_;
    QDoubleSpinBox * wavelength_dsb_;

    Source * source_;

public:
    /**
     * Constructeur du widget permettant de modifier la source.
     * @param source la source à modifier.
     * @param parent le widget parent.
     */
    SourceProp(Source * source, QWidget * parent = 0);
    ~SourceProp();

private:
    void setup_ui();

    /**
     * Applique les changements effectués à l’objet source qu’il contient.
     */
    void apply() override;
    /**
     * Modifie les spinbox pour qu’elles prennent les valeurs de la source.
     */
    void reset() override;
};

#endif // SOURCEPROP_H
