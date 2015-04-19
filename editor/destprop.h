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
    QLabel * x_label_;
    QDoubleSpinBox * x_dsb_;
    QLabel * y_label_;
    QDoubleSpinBox * y_dsb_;
    QLabel * edge_label_;
    QDoubleSpinBox * edge_dsb_;

    Dest * dest_;

    void apply();
    void reset();
signals:

public slots:

};

#endif // DESTPROP_H
