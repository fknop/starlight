#include "nukeprop.h"

/**
 * Modifie la bombe sélectionnée dans l’éditeur.
 * @param nuke la bombe sélectionnée.
 * @param parent le widget parent.
 */
NukeProp::NukeProp(Nuke * nuke, QWidget * parent) : nuke_{nuke}
{
    setupUi();

    nuke_->add_observer(this);

    reset();
}

NukeProp::~NukeProp()
{
    nuke_->remove_observer(this);
}

void NukeProp::setupUi()
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

    rad_label_ = new QLabel();
    rad_label_->setText("Radius");
    rad_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(2, QFormLayout::LabelRole, rad_label_);

    rad_dsb_ = new QDoubleSpinBox();
    rad_dsb_->setMaximum(999.);

    form_layout_->setWidget(2, QFormLayout::FieldRole, rad_dsb_);

    setLayout(form_layout_);
}

/**
 * Applique les changements effectués à l’objet nuke qu’il contient.
 */
void NukeProp::apply()
{
    nuke_->set_pos(Point(x_dsb_->value(), y_dsb_->value()));
    nuke_->set_radius(rad_dsb_->value());
}

/**
 * Modifie les spinbox pour qu’elles prennent les valeurs de la bombe.
 */
void NukeProp::reset()
{
    x_dsb_->setValue(nuke_->position().x());
    y_dsb_->setValue(nuke_->position().y());
    rad_dsb_->setValue(nuke_->radius());
}
