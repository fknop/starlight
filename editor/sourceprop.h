#ifndef SOURCEPROP_H
#define SOURCEPROP_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>

#include "model/source.h"

#include "propertiesinterface.h"

class SourceProp : public PropertiesInterface
{
    Q_OBJECT
public:
    SourceProp(Source * source, QWidget *parent = 0);
    void setupUi();

private:
    QFormLayout *formLayout;
    QLabel *x_label;
    QDoubleSpinBox *x_dsb;
    QLabel *y_label;
    QDoubleSpinBox *y_dsb;
    QLabel *edge_label;
    QDoubleSpinBox *edge_dsb;
    QLabel *wavelength_label;
    QDoubleSpinBox *wavelength_dsb;


    Source * source_;

    void apply();
    void reset();

signals:

public slots:

};

#endif // SOURCEPROP_H
