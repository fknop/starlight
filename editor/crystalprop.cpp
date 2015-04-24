#include <QMessageBox>

#include "editor/crystalprop.h"

/**
 * Modifie le cristal sélectionné dans l’éditeur.
 * @param crystal le cristal sélectionné.
 * @param parent le widget parent.
 */
CrystalProp::CrystalProp(Crystal * crystal, QWidget * parent) : crystal_{crystal}
{
    crystal_->add_observer(this);
    setup_ui();
    reset();
}

CrystalProp::~CrystalProp()
{
    crystal_->remove_observer(this);
}

void CrystalProp::setup_ui()
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

    rad_label_ = new QLabel("Radius");
    rad_label_->setMinimumSize(QSize(100, 20));

    rad_dsb_ = new QDoubleSpinBox();
    rad_dsb_->setMaximum(999.);

    mod_label_ = new QLabel("Modifier");
    mod_label_->setMinimumSize(QSize(100, 20));

    mod_dsb_ = new QDoubleSpinBox();
    mod_dsb_->setMinimum(-999.);
    mod_dsb_->setMaximum(999.);

    form_layout_->setWidget(0, QFormLayout::LabelRole, x_label_);
    form_layout_->setWidget(0, QFormLayout::FieldRole, x_dsb_);
    form_layout_->setWidget(1, QFormLayout::LabelRole, y_label_);
    form_layout_->setWidget(1, QFormLayout::FieldRole, y_dsb_);
    form_layout_->setWidget(2, QFormLayout::LabelRole, rad_label_);
    form_layout_->setWidget(2, QFormLayout::FieldRole, rad_dsb_);
    form_layout_->setWidget(3, QFormLayout::LabelRole, mod_label_);
    form_layout_->setWidget(3, QFormLayout::FieldRole, mod_dsb_);

    setLayout(form_layout_);
}

void CrystalProp::apply()
{
    crystal_->set_center(Point(x_dsb_->value(), y_dsb_->value()));
    crystal_->set_modifier(mod_dsb_->value());

    if (!crystal_->set_radius(rad_dsb_->value()))
        QMessageBox::warning(this, "Incorrect Data", "Incorrect radius");

    reset();
}

void CrystalProp::reset()
{
    x_dsb_->setValue(crystal_->center().x());
    y_dsb_->setValue(crystal_->center().y());
    rad_dsb_->setValue(crystal_->radius());
    mod_dsb_->setValue(crystal_->modifier());
}
