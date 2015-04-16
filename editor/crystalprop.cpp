#include "crystalprop.h"

CrystalProp::CrystalProp(Crystal * crystal, QWidget * parent) : crystal_{crystal}
{
    setupUi();

    crystal_->add_observer(this);

    reset();
}

CrystalProp::~CrystalProp()
{
    crystal_->remove_observer(this);
}

void CrystalProp::setupUi()
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

    mod_label_ = new QLabel();
    mod_label_->setText("Modifier");
    mod_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(3, QFormLayout::LabelRole, mod_label_);

    mod_dsb_ = new QDoubleSpinBox();
    mod_dsb_->setMinimum(-999.);
    mod_dsb_->setMaximum(999.);


    form_layout_->setWidget(3, QFormLayout::FieldRole, mod_dsb_);

    setLayout(form_layout_);
}

void CrystalProp::reset()
{
    x_dsb_->setValue(crystal_->center().x());
    y_dsb_->setValue(crystal_->center().y());
    rad_dsb_->setValue(crystal_->radius());
    mod_dsb_->setValue(crystal_->modifier());
}

void CrystalProp::apply()
{
    crystal_->set_center(Point(x_dsb_->value(), y_dsb_->value()));
    crystal_->set_modifier(mod_dsb_->value());
    crystal_->set_radius(rad_dsb_->value());
}
