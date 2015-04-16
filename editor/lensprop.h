#ifndef LENSPROP_H
#define LENSPROP_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "model/lens.h"


class LensProp : public PropertiesInterface
{
    Q_OBJECT
public:
    LensProp(Lens * lens, QWidget * parent = 0);
    ~LensProp();
    void setupUi();

private:
    QFormLayout * formLayout;
    QLabel * x_label;
    QDoubleSpinBox * x_dsb;
    QLabel * y_label;
    QDoubleSpinBox * y_dsb;
    QLabel * width_label;
    QDoubleSpinBox * width_dsb;
    QLabel * height_label;
    QDoubleSpinBox * height_dsb;

    QLabel * wl_min_label;
    QDoubleSpinBox * wl_min_dsb;
    QLabel * wl_max_label;
    QDoubleSpinBox * wl_max_dsb;

    Lens * lens_;

    void apply();
    void reset();

signals:

public slots:

};

#endif // LENSPROP_H
