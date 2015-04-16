#ifndef NUKEPROP_H
#define NUKEPROP_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "model/nuke.h"

#include "propertiesinterface.h"

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

    void apply();
    void reset();

signals:

public slots:

};

#endif // NUKEPROP_H
