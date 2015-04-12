#include "wallprop.h"

WallProp::WallProp(Wall *wall, QWidget *parent)
{
    setupUi();
    reset();
}

void WallProp::setupUi()
{
    formLayout = new QFormLayout();

    x1_label = new QLabel();
    x1_label->setText("X");
    x1_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(0, QFormLayout::LabelRole, x1_label);

    x1_dsb = new QDoubleSpinBox();

    formLayout->setWidget(0, QFormLayout::FieldRole, x1_dsb);

    y1_label = new QLabel();
    y1_label->setText("Y");
    y1_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(1, QFormLayout::LabelRole, y1_label);

    y1_dsb = new QDoubleSpinBox();

    formLayout->setWidget(1, QFormLayout::FieldRole, y1_dsb);

    x2_label = new QLabel();
    x2_label->setText("X min");
    x2_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(5, QFormLayout::LabelRole, x2_label);

    x2_dsb = new QDoubleSpinBox();

    formLayout->setWidget(5, QFormLayout::FieldRole, x2_dsb);

    y2_label = new QLabel();
    y2_label->setText("X max");
    y2_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(6, QFormLayout::LabelRole, y2_label);

    y2_dsb = new QDoubleSpinBox();

    formLayout->setWidget(6, QFormLayout::FieldRole, y2_dsb);

    setLayout(formLayout);
}

void WallProp::reset()
{
    x1_dsb->setValue(wall_->start().x());
    y1_dsb->setValue(wall_->start().y());
    x2_dsb->setValue(wall_->end().x());
    y2_dsb->setValue(wall_->end().y());
}

void WallProp::apply()
{
//    wall_->set_pivot(Point(x1_dsb->value(), y1_dsb->value()));
    //mirror_->set_angle();
}
