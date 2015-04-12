#include "crystalprop.h"

CrystalProp::CrystalProp(Crystal *crystal, QWidget *parent) : crystal_{crystal}
{
    setupUi();
    reset();
}

void CrystalProp::setupUi()
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

    rad_label = new QLabel();
    rad_label->setText("Radius");
    rad_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(2, QFormLayout::LabelRole, rad_label);

    rad_dsb = new QDoubleSpinBox();

    formLayout->setWidget(2, QFormLayout::FieldRole, rad_dsb);

    mod_label = new QLabel();
    mod_label->setText("Modifier");
    mod_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(3, QFormLayout::LabelRole, mod_label);

    mod_dsb = new QDoubleSpinBox();

    formLayout->setWidget(3, QFormLayout::FieldRole, mod_dsb);

    setLayout(formLayout);
}

void CrystalProp::reset()
{
    x_dsb->setValue(crystal_->center().x());
    y_dsb->setValue(crystal_->center().y());
    rad_dsb->setValue(crystal_->radius());
    mod_dsb->setValue(crystal_->modifier());
}

void CrystalProp::apply()
{
//    crystal_->set_center(Point(x_dsb->value(), y_dsb->value()));
    //crystal_->set_angle();
}
