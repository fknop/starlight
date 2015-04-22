#ifndef CRYSTALPROP_H
#define CRYSTALPROP_H


#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "model/crystal.h"



/**
 * Panel permettant de modifier un cristal.
 */
class CrystalProp : public PropertiesInterface
{
    Q_OBJECT
public:
    CrystalProp(Crystal * crystal, QWidget * parent = 0);
    ~CrystalProp();

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

    void setup_ui();

    /**
     * Applique les changements effectués à l’objet crystal qu’il contient.
     */
    void apply() override;
    /**
     * Modifie les spinbox pour qu’elles prennent les valeurs du cristal.
     */
    void reset() override;

signals:

public slots:

};

#endif // CRYSTALPROP_H
