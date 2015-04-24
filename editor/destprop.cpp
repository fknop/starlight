#include <QMessageBox>

#include "editor/destprop.h"


DestProp::DestProp(Dest * dest, QWidget * parent) : dest_{dest}
{
    dest_->add_observer(this);
    setup_ui();
    reset();
}

DestProp::~DestProp()
{
    dest_->remove_observer(this);
}

void DestProp::setup_ui()
{
    form_layout_ = new QFormLayout();

    x_label_ = new QLabel("X");
    x_label_->setMinimumSize(QSize(100, 20));

    x_dsb_ = new QDoubleSpinBox();
    x_dsb_->setMaximum(999.);

    y_label_ = new QLabel("Y");
    y_label_->setMinimumSize(QSize(100, 20));

    y_dsb_ = new QDoubleSpinBox();
    y_dsb_->setMaximum(999.);

    edge_label_ = new QLabel("Edge");
    edge_label_->setMinimumSize(QSize(100, 20));

    edge_dsb_ = new QDoubleSpinBox();
    edge_dsb_->setMaximum(999.);

    form_layout_->setWidget(0, QFormLayout::LabelRole, x_label_);
    form_layout_->setWidget(0, QFormLayout::FieldRole, x_dsb_);
    form_layout_->setWidget(1, QFormLayout::LabelRole, y_label_);
    form_layout_->setWidget(1, QFormLayout::FieldRole, y_dsb_);
    form_layout_->setWidget(2, QFormLayout::LabelRole, edge_label_);
    form_layout_->setWidget(2, QFormLayout::FieldRole, edge_dsb_);

    setLayout(form_layout_);
}

void DestProp::apply()
{
    dest_->set_pos(Point(x_dsb_->value(), y_dsb_->value()));
    if (!dest_->set_edge(edge_dsb_->value()))
        QMessageBox::warning(this, "Incorrect Data", "Incorrect Edge");

    reset();
}

void DestProp::reset()
{
    x_dsb_->setValue(dest_->pos().x());
    y_dsb_->setValue(dest_->pos().y());
    edge_dsb_->setValue(dest_->edge());
}
