#ifndef CRYSTALPROP_H
#define CRYSTALPROP_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>

#include "model/crystal.h"

#include "editor/propertiesinterface.h"

/**
 * Panel permettant de modifier un cristal.
 */
class CrystalProp : public PropertiesInterface
{
    Q_OBJECT
public:
    CrystalProp(Crystal * crystal, QWidget * parent = 0);
    ~CrystalProp();
    void setupUi();

private:
    QFormLayout * form_layout_;
    QLabel * x_label_;
    QDoubleSpinBox * x_dsb_;
    QLabel * y_label_;
    QDoubleSpinBox * y_dsb_;
    QLabel * rad_label_;
    QDoubleSpinBox * rad_dsb_;
    QLabel * mod_label_;
    QDoubleSpinBox * mod_dsb_;

    Crystal * crystal_;

    /**
     * Applique les changements effectués à l’objet crystal qu’il contient.
     */
    void apply();
    /**
     * Modifie les spinbox pour qu’elles prennent les valeurs du cristal.
     */
    void reset();

signals:

public slots:

};

#endif // CRYSTALPROP_H
