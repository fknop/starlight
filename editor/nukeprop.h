#ifndef NUKEPROP_H
#define NUKEPROP_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "model/nuke.h"


/**
 * Modifie la bombe sélectionnée dans l’éditeur.
 * @param nuke la bombe sélectionnée.
 * @param parent le widget parent.
 */
class NukeProp : public PropertiesInterface
{
    Q_OBJECT
public:
    NukeProp(Nuke * nuke, QWidget * parent = 0);
    ~NukeProp();
    void setupUi();

private:
    QFormLayout * form_layout_;
    QLabel * x_label_;
    QDoubleSpinBox * x_dsb_;
    QLabel * y_label_;
    QDoubleSpinBox * y_dsb_;
    QLabel * rad_label_;
    QDoubleSpinBox * rad_dsb_;

    Nuke * nuke_;

    /**
     * Applique les changements effectués à l’objet nuke qu’il contient.
     */
    void apply();
    /**
     * Modifie les spinbox pour qu’elles prennent les valeurs de la bombe.
     */
    void reset();

signals:

public slots:

};

#endif // NUKEPROP_H
