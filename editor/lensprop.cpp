#include "lensprop.h"

LensProp::LensProp(Lens * lens, QWidget *parent) : lens_{lens}
{
    setupUi();
    reset();
}


void LensProp::setupUi()
{
    formLayout = new QFormLayout();

    x_label = new QLabel();
    x_label->setText("X");
    x_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(0, QFormLayout::LabelRole, x_label);

    x_dsb = new QDoubleSpinBox();

    formLayout->setWidget(0, QFormLayout::FieldRole, x_dsb);

    y_label = new QLabel();
    y_label->setText("Y");
    y_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(1, QFormLayout::LabelRole, y_label);

    y_dsb = new QDoubleSpinBox();

    formLayout->setWidget(1, QFormLayout::FieldRole, y_dsb);

    width_label = new QLabel();
    width_label->setText("Width");
    width_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(2, QFormLayout::LabelRole, width_label);

    width_dsb = new QDoubleSpinBox();

    formLayout->setWidget(2, QFormLayout::FieldRole, width_dsb);

    height_label = new QLabel();
    height_label->setText("Height");
    height_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(3, QFormLayout::LabelRole, height_label);

    height_dsb = new QDoubleSpinBox();

    formLayout->setWidget(3, QFormLayout::FieldRole, height_dsb);

    wl_min_label = new QLabel();
    wl_min_label->setText("Wavelength min");
    wl_min_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(5, QFormLayout::LabelRole, wl_min_label);

    wl_min_dsb = new QDoubleSpinBox();

    formLayout->setWidget(5, QFormLayout::FieldRole, wl_min_dsb);

    wl_max_label = new QLabel();
    wl_max_label->setText("Wavelength max");
    wl_max_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(6, QFormLayout::LabelRole, wl_max_label);

    wl_max_dsb = new QDoubleSpinBox();

    formLayout->setWidget(6, QFormLayout::FieldRole, wl_max_dsb);


    setLayout(formLayout);
}

void LensProp::reset()
{
    x_dsb->setValue(lens_->position().x());
    y_dsb->setValue(lens_->position().y());
    width_dsb->setValue(lens_->width());
    height_dsb->setValue(lens_->height());
    wl_min_dsb->setValue(lens_->wl_min());
    wl_max_dsb->setValue(lens_->wl_max());
}

void LensProp::apply()
{
//    lens_->set_pivot(Point(x_dsb->value(), y_dsb->value()));
    //lens_->set_angle();
}
