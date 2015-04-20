#include "sourceprop.h"

/**
 * Modifie la source sélectionnée dans l’éditeur.
 * @param source la source sélectionnée.
 * @param parent le widget parent.
 */
SourceProp::SourceProp(Source * source, QWidget * parent) : source_{source}
{
    setupUi();

    source_->add_observer(this);

    reset();
}

SourceProp::~SourceProp()
{
    source_->remove_observer(this);
}

void SourceProp::setupUi()
{
    form_layout_ = new QFormLayout();

    x_label_ = new QLabel();
    x_label_->setText("X");
    x_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(0, QFormLayout::LabelRole, x_label_);

    x_dsb_ = new QDoubleSpinBox();
    x_dsb_->setMaximum(999.);

    form_layout_->setWidget(0, QFormLayout::FieldRole, x_dsb_);

    y_label_ = new QLabel();
    y_label_->setText("Y");
    y_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(1, QFormLayout::LabelRole, y_label_);

    y_dsb_ = new QDoubleSpinBox();
    y_dsb_->setMaximum(999.);

    form_layout_->setWidget(1, QFormLayout::FieldRole, y_dsb_);

    edge_label_ = new QLabel();
    edge_label_->setText("Edge");
    edge_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(2, QFormLayout::LabelRole, edge_label_);

    edge_dsb_ = new QDoubleSpinBox();
    edge_dsb_->setMaximum(999.);

    form_layout_->setWidget(2, QFormLayout::FieldRole, edge_dsb_);

    alpha_label_ = new QLabel();
    alpha_label_->setText("Alpha");
    alpha_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(3, QFormLayout::LabelRole, alpha_label_);

    alpha_dsb_ = new QDoubleSpinBox();
    alpha_dsb_->setMaximum(999.);

    form_layout_->setWidget(3, QFormLayout::FieldRole, alpha_dsb_);

    wavelength_label_ = new QLabel();
    wavelength_label_->setText("Wavelength");
    wavelength_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(4, QFormLayout::LabelRole, wavelength_label_);

    wavelength_dsb_ = new QDoubleSpinBox();
    wavelength_dsb_->setMaximum(999.);

    form_layout_->setWidget(4, QFormLayout::FieldRole, wavelength_dsb_);

    setLayout(form_layout_);
}

/**
 * Applique les changements effectués à l’objet source qu’il contient.
 */
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
