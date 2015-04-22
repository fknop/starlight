#ifndef MIRRORPREFS_H
#define MIRRORPREFS_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "model/mirror.h"


/**
 * Panel permettant de modifier un miroir.
 */
class MirrorProp : public PropertiesInterface
{
    Q_OBJECT
public:
    MirrorProp(Mirror * mirror, QWidget * parent = 0);
    ~MirrorProp();

private:
    QFormLayout * form_layout_;
    QLabel* x_label_;
    QDoubleSpinBox * x_dsb_;
    QLabel * y_label_;
    QDoubleSpinBox * y_dsb_;
    QLabel * length_label_;
    QDoubleSpinBox * length_dsb_;
    QLabel * xpad_label_;
    QDoubleSpinBox * xpad_dsb_;
    QLabel * alpha_label_;
    QDoubleSpinBox * alpha_dsb_;
    QLabel * xmin_label_;
    QDoubleSpinBox * xmin_dsb_;
    QLabel * xmax_label_;
    QDoubleSpinBox * xmax_dsb_;
    QLabel * ymin_label_;
    QDoubleSpinBox * ymin_dsb_;
    QLabel * ymax_label_;
    QDoubleSpinBox * ymax_dsb_;
    QLabel * alphamin_label_;
    QDoubleSpinBox * alphamin_dsb_;
    QLabel * alphamax_label_;
    QDoubleSpinBox * alphamax_dsb_;

    Mirror * mirror_;

    void setup_ui();

    /**
     * Applique les changements effectués à l’objet mirror qu’il contient.
     */
    void apply();
    /**
     * Modifie les spinbox pour qu’elles prennent les valeurs du miroir.
     */
    void reset();

signals:

public slots:

};

#endif // MIRRORPREFS_H
