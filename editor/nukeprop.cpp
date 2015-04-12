#include "nukeprop.h"

NukeProp::NukeProp(Nuke *nuke, QWidget *parent)
{
    setupUi();
    reset();
}

void NukeProp::setupUi()
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
    rad_label->setText("Rad");
    rad_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(2, QFormLayout::LabelRole, rad_label);

    rad_dsb = new QDoubleSpinBox();

    formLayout->setWidget(2, QFormLayout::FieldRole, rad_dsb);

    setLayout(formLayout);
}

void NukeProp::reset()
{
    x_dsb->setValue(nuke_->position().x());
    y_dsb->setValue(nuke_->position().y());
    rad_dsb->setValue(nuke_->radius());
}

void NukeProp::apply()
{
//    nuke_->set_pivot(Point(x_dsb->value(), y_dsb->value()));
    //nuke_->set_angle();
}