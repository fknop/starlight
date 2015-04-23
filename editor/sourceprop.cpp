#include "editor/sourceprop.h"


SourceProp::SourceProp(Source * source, QWidget * parent) : source_{source}
{
    source_->add_observer(this);
    setup_ui();
    reset();
}

SourceProp::~SourceProp()
{
    source_->remove_observer(this);
}

void SourceProp::setup_ui()
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

    alpha_label_ = new QLabel("Alpha");
    alpha_label_->setMinimumSize(QSize(100, 20));

    alpha_dsb_ = new QDoubleSpinBox();
    alpha_dsb_->setMaximum(999.);

    wavelength_label_ = new QLabel("Wavelength");
    wavelength_label_->setMinimumSize(QSize(100, 20));

    wavelength_dsb_ = new QDoubleSpinBox();
    wavelength_dsb_->setMaximum(999.);

    form_layout_->setWidget(0, QFormLayout::LabelRole, x_label_);
    form_layout_->setWidget(0, QFormLayout::FieldRole, x_dsb_);
    form_layout_->setWidget(1, QFormLayout::LabelRole, y_label_);
    form_layout_->setWidget(1, QFormLayout::FieldRole, y_dsb_);
    form_layout_->setWidget(2, QFormLayout::LabelRole, edge_label_);
    form_layout_->setWidget(2, QFormLayout::FieldRole, edge_dsb_);
    form_layout_->setWidget(3, QFormLayout::LabelRole, alpha_label_);
    form_layout_->setWidget(3, QFormLayout::FieldRole, alpha_dsb_);
    form_layout_->setWidget(4, QFormLayout::LabelRole, wavelength_label_);
    form_layout_->setWidget(4, QFormLayout::FieldRole, wavelength_dsb_);

    setLayout(form_layout_);
}

void SourceProp::apply()
{
    source_->set_pos(Point(x_dsb_->value(), y_dsb_->value()));
    source_->set_edge(edge_dsb_->value());
    source_->set_alpha(alpha_dsb_->value());
    source_->set_wavelength(wavelength_dsb_->value());
}

void SourceProp::reset()
{
    x_dsb_->setValue(source_->pos().x());
    y_dsb_->setValue(source_->pos().y());
    edge_dsb_->setValue(source_->edge());
    alpha_dsb_->setValue(source_->angle());
    wavelength_dsb_->setValue(source_->wavelength());
}
