#include "editor/lensprop.h"


LensProp::LensProp(Lens * lens, QWidget * parent) : lens_{lens}
{
    setupUi();

    lens_->add_observer(this);

    reset();
}

LensProp::~LensProp()
{
    lens_->remove_observer(this);
}


void LensProp::setupUi()
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

    width_label_ = new QLabel();
    width_label_->setText("Width");
    width_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(2, QFormLayout::LabelRole, width_label_);

    width_dsb_ = new QDoubleSpinBox();
    width_dsb_->setMaximum(999.);

    form_layout_->setWidget(2, QFormLayout::FieldRole, width_dsb_);

    height_label_ = new QLabel();
    height_label_->setText("Height");
    height_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(3, QFormLayout::LabelRole, height_label_);

    height_dsb_ = new QDoubleSpinBox();
    height_dsb_->setMaximum(999.);

    form_layout_->setWidget(3, QFormLayout::FieldRole, height_dsb_);

    wl_min_label_ = new QLabel();
    wl_min_label_->setText("Wavelength min");
    wl_min_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(5, QFormLayout::LabelRole, wl_min_label_);

    wl_min_dsb_ = new QDoubleSpinBox();
    wl_min_dsb_->setMaximum(999.);

    form_layout_->setWidget(5, QFormLayout::FieldRole, wl_min_dsb_);

    wl_max_label_ = new QLabel();
    wl_max_label_->setText("Wavelength max");
    wl_max_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(6, QFormLayout::LabelRole, wl_max_label_);

    wl_max_dsb_ = new QDoubleSpinBox();
    wl_max_dsb_->setMaximum(999.);

    form_layout_->setWidget(6, QFormLayout::FieldRole, wl_max_dsb_);

    setLayout(form_layout_);
}

void LensProp::apply()
{
    lens_->set_pos(Point(x_dsb_->value(), y_dsb_->value()));
    lens_->set_width(width_dsb_->value());
    lens_->set_height(height_dsb_->value());
    lens_->set_wl_min(wl_min_dsb_->value());
    lens_->set_wl_max(wl_max_dsb_->value());
}

void LensProp::reset()
{
    x_dsb_->setValue(lens_->position().x());
    y_dsb_->setValue(lens_->position().y());
    width_dsb_->setValue(lens_->width());
    height_dsb_->setValue(lens_->height());
    wl_min_dsb_->setValue(lens_->wl_min());
    wl_max_dsb_->setValue(lens_->wl_max());
}
