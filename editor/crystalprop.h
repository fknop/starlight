#ifndef CRYSTALPROP_H
#define CRYSTALPROP_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>

#include "model/crystal.h"

#include "propertiesinterface.h"

class CrystalProp : public PropertiesInterface
{
    Q_OBJECT
public:
    CrystalProp(Crystal * crystal, QWidget *parent = 0);
    void setupUi();

private:
    QFormLayout *formLayout;
    QLabel *x_label;
    QDoubleSpinBox *x_dsb;
    QLabel *y_label;
    QDoubleSpinBox *y_dsb;
    QLabel *rad_label;
    QDoubleSpinBox *rad_dsb;
    QLabel *mod_label;
    QDoubleSpinBox *mod_dsb;

    Crystal * crystal_;

    void apply();
    void reset();

signals:

public slots:

};

#endif // CRYSTALPROP_H
