#ifndef NUKEPROP_H
#define NUKEPROP_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>

#include "model/nuke.h"

#include "propertiesinterface.h"

class NukeProp : public PropertiesInterface
{
    Q_OBJECT
public:
    NukeProp(Nuke * nuke, QWidget *parent = 0);
    ~NukeProp();
    void setupUi();

private:
    QFormLayout *formLayout;
    QLabel *x_label;
    QDoubleSpinBox *x_dsb;
    QLabel *y_label;
    QDoubleSpinBox *y_dsb;
    QLabel *rad_label;
    QDoubleSpinBox *rad_dsb;


    Nuke * nuke_;

    void apply();
    void reset();



signals:

public slots:

};

#endif // NUKEPROP_H
