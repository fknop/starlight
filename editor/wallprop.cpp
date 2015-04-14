#include "wallprop.h"

WallProp::WallProp(Wall *wall, QWidget *parent) : wall_{wall}
{
    setupUi();

    wall_->add_observer(this);

    reset();
}

WallProp::~WallProp()
{
    wall_->remove_observer(this);
}

void WallProp::setupUi()
{
    formLayout = new QFormLayout();

    x1_label = new QLabel();
    x1_label->setText("X1");
    x1_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(0, QFormLayout::LabelRole, x1_label);

    x1_dsb = new QDoubleSpinBox();
    x1_dsb->setMaximum(999.);

    formLayout->setWidget(0, QFormLayout::FieldRole, x1_dsb);

    y1_label = new QLabel();
    y1_label->setText("Y1");
    y1_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(1, QFormLayout::LabelRole, y1_label);

    y1_dsb = new QDoubleSpinBox();
    y1_dsb->setMaximum(999.);

    formLayout->setWidget(1, QFormLayout::FieldRole, y1_dsb);

    x2_label = new QLabel();
    x2_label->setText("X2");
    x2_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(5, QFormLayout::LabelRole, x2_label);

    x2_dsb = new QDoubleSpinBox();
    x2_dsb->setMaximum(999.);

    formLayout->setWidget(5, QFormLayout::FieldRole, x2_dsb);

    y2_label = new QLabel();
    y2_label->setText("Y2");
    y2_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(6, QFormLayout::LabelRole, y2_label);

    y2_dsb = new QDoubleSpinBox();
    y2_dsb->setMaximum(999.);

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
    wall_->set_start(Point(x1_dsb->value(), y1_dsb->value()));
    wall_->set_end(Point(x2_dsb->value(), y2_dsb->value()));
}
