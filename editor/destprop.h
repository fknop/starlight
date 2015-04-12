#ifndef DESTPROP_H
#define DESTPROP_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>

#include "model/dest.h"

#include "propertiesinterface.h"

class DestProp : public PropertiesInterface
{
    Q_OBJECT
public:
    DestProp(Dest * dest, QWidget *parent = 0);
    void setupUi();

private:
    QFormLayout *formLayout;
    QLabel *x_label;
    QDoubleSpinBox *x_dsb;
    QLabel *y_label;
    QDoubleSpinBox *y_dsb;
    QLabel *edge_label;
    QDoubleSpinBox *edge_dsb;
    QLabel *xpad_label;
    QDoubleSpinBox *xpad_dsb;
    QLabel *alpha_label;
    QDoubleSpinBox *alpha_dsb;
    QLabel *xmin_label;
    QDoubleSpinBox *xmin_dsb;
    QLabel *xmax_label;
    QDoubleSpinBox *xmax_dsb;
    QLabel *ymin_label;
    QDoubleSpinBox *ymin_dsb;
    QLabel *ymax_label;
    QDoubleSpinBox *ymax_dsb;
    QLabel *alphamin_label;
    QDoubleSpinBox *alphamin_dsb;
    QLabel *alphamax_label;
    QDoubleSpinBox *alphamax_dsb;

    Dest * dest_;

    void apply();
    void reset();
signals:

public slots:

};

#endif // DESTPROP_H
