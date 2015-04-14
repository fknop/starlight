#include "destprop.h"

DestProp::DestProp(Dest * dest, QWidget *parent) : dest_{dest}
{
    setupUi();

    dest_->add_observer(this);

    reset();
}

void DestProp::setupUi()
{
    formLayout = new QFormLayout();

    x_label = new QLabel();
    x_label->setText("X");
    x_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(0, QFormLayout::LabelRole, x_label);

    x_dsb = new QDoubleSpinBox();
    x_dsb->setMaximum(999.);

    formLayout->setWidget(0, QFormLayout::FieldRole, x_dsb);

    y_label = new QLabel();
    y_label->setText("Y");
    y_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(1, QFormLayout::LabelRole, y_label);

    y_dsb = new QDoubleSpinBox();
    y_dsb->setMaximum(999.);

    formLayout->setWidget(1, QFormLayout::FieldRole, y_dsb);

    edge_label = new QLabel();
    edge_label->setText("Edge");
    edge_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(2, QFormLayout::LabelRole, edge_label);

    edge_dsb = new QDoubleSpinBox();
    edge_dsb->setMaximum(999.);

    formLayout->setWidget(2, QFormLayout::FieldRole, edge_dsb);

    setLayout(formLayout);
}

void DestProp::reset()
{
    x_dsb->setValue(dest_->pos().x());
    y_dsb->setValue(dest_->pos().y());
    edge_dsb->setValue(dest_->edge());
}

void DestProp::apply()
{
    dest_->set_pos(Point(x_dsb->value(), y_dsb->value()));
    dest_->set_edge(edge_dsb->value());
}
