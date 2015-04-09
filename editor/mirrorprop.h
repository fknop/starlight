#ifndef MIRRORPREFS_H
#define MIRRORPREFS_H

#include <QWidget>
#include <QButtonGroup>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>

#include "model/mirror.h"

class MirrorProp : public QWidget
{
    Q_OBJECT
public:
    explicit MirrorProp(QWidget *parent = 0);
    void setupUi();

private:
    QFormLayout *formLayout;
    QLabel *x_label;
    QDoubleSpinBox *x_dsb;
    QLabel *y_label;
    QDoubleSpinBox *y_dsb;
    QLabel *length_label;
    QDoubleSpinBox *length_dsb;
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

    Mirror * mirror_;

    void apply();


signals:

public slots:

};

#endif // MIRRORPREFS_H
