#ifndef DESTPROP_H
#define DESTPROP_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "model/dest.h"


class DestProp : public PropertiesInterface
{
    Q_OBJECT
public:
    DestProp(Dest * dest, QWidget * parent = 0);
    ~DestProp();
    void setupUi();

private:
    QFormLayout * form_layout_;
    QLabel * x_label;
    QDoubleSpinBox * x_dsb;
    QLabel * y_label;
    QDoubleSpinBox * y_dsb;
    QLabel * edge_label;
    QDoubleSpinBox * edge_dsb;

    Dest * dest_;

    void apply();
    void reset();
signals:

public slots:

};

#endif // DESTPROP_H
