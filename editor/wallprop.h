#ifndef WALLPROP_H
#define WALLPROP_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>

#include "model/wall.h"

#include "propertiesinterface.h"

class WallProp : public PropertiesInterface
{
    Q_OBJECT
public:
    WallProp(Wall * wall, QWidget *parent = 0);
    ~WallProp();
    void setupUi();

private:
    QFormLayout *formLayout;
    QLabel *x1_label;
    QDoubleSpinBox *x1_dsb;
    QLabel *y1_label;
    QDoubleSpinBox *y1_dsb;
    QLabel *x2_label;
    QDoubleSpinBox *x2_dsb;
    QLabel *y2_label;
    QDoubleSpinBox *y2_dsb;

    Wall * wall_;

    void apply();
    void reset();

signals:

public slots:

};

#endif // WALLPROP_H
