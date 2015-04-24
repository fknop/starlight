#include <QMessageBox>

#include "editor/nukeprop.h"


NukeProp::NukeProp(Nuke * nuke, QWidget * parent) : nuke_{nuke}
{
    nuke_->add_observer(this);
    setup_ui();
    reset();
}

NukeProp::~NukeProp()
{
    nuke_->remove_observer(this);
}

void NukeProp::setup_ui()
{
    form_layout_ = new QFormLayout();

    x_label_ = new QLabel("X");
    x_label_->setMinimumSize(QSize(100, 20));

    y_label_ = new QLabel("Y");
    y_label_->setMinimumSize(QSize(100, 20));

    x_dsb_ = new QDoubleSpinBox();
    x_dsb_->setMaximum(999.);

    y_dsb_ = new QDoubleSpinBox();
    y_dsb_->setMaximum(999.);

    rad_label_ = new QLabel("Radius");
    rad_label_->setMinimumSize(QSize(100, 20));

    rad_dsb_ = new QDoubleSpinBox();
    rad_dsb_->setMaximum(999.);

    form_layout_->setWidget(0, QFormLayout::LabelRole, x_label_);
    form_layout_->setWidget(0, QFormLayout::FieldRole, x_dsb_);
    form_layout_->setWidget(1, QFormLayout::LabelRole, y_label_);
    form_layout_->setWidget(1, QFormLayout::FieldRole, y_dsb_);
    form_layout_->setWidget(2, QFormLayout::LabelRole, rad_label_);
    form_layout_->setWidget(2, QFormLayout::FieldRole, rad_dsb_);

    setLayout(form_layout_);
}

void NukeProp::apply()
{
    nuke_->set_pos(Point(x_dsb_->value(), y_dsb_->value()));

    if (!nuke_->set_radius(rad_dsb_->value()))
        QMessageBox::warning(this, "Incorrect Data", "Incorrect radius");

    reset();
}

void NukeProp::reset()
{
    x_dsb_->setValue(nuke_->position().x());
    y_dsb_->setValue(nuke_->position().y());
    rad_dsb_->setValue(nuke_->radius());
}
