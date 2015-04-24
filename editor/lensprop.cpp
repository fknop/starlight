#include <QMessageBox>

#include "editor/lensprop.h"


LensProp::LensProp(Lens * lens, QWidget * parent) : lens_{lens}
{
    lens_->add_observer(this);
    setup_ui();
    reset();
}

LensProp::~LensProp()
{
    lens_->remove_observer(this);
}

void LensProp::setup_ui()
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

    width_label_ = new QLabel("Width");
    width_label_->setMinimumSize(QSize(100, 20));

    width_dsb_ = new QDoubleSpinBox();
    width_dsb_->setMaximum(999.);

    height_label_ = new QLabel("Height");
    height_label_->setMinimumSize(QSize(100, 20));

    height_dsb_ = new QDoubleSpinBox();
    height_dsb_->setMaximum(999.);

    wl_min_label_ = new QLabel("WL. min");
    wl_min_label_->setMinimumSize(QSize(100, 20));

    wl_min_dsb_ = new QDoubleSpinBox();
    wl_min_dsb_->setMaximum(999.);

    wl_max_label_ = new QLabel("WL. max");
    wl_max_label_->setMinimumSize(QSize(100, 20));

    wl_max_dsb_ = new QDoubleSpinBox();
    wl_max_dsb_->setMaximum(999.);

    form_layout_->setWidget(0, QFormLayout::LabelRole, x_label_);
    form_layout_->setWidget(0, QFormLayout::FieldRole, x_dsb_);
    form_layout_->setWidget(1, QFormLayout::LabelRole, y_label_);
    form_layout_->setWidget(1, QFormLayout::FieldRole, y_dsb_);
    form_layout_->setWidget(2, QFormLayout::LabelRole, width_label_);
    form_layout_->setWidget(2, QFormLayout::FieldRole, width_dsb_);
    form_layout_->setWidget(3, QFormLayout::LabelRole, height_label_);
    form_layout_->setWidget(3, QFormLayout::FieldRole, height_dsb_);
    form_layout_->setWidget(5, QFormLayout::LabelRole, wl_min_label_);
    form_layout_->setWidget(5, QFormLayout::FieldRole, wl_min_dsb_);
    form_layout_->setWidget(6, QFormLayout::LabelRole, wl_max_label_);
    form_layout_->setWidget(6, QFormLayout::FieldRole, wl_max_dsb_);

    setLayout(form_layout_);
}

void LensProp::apply()
{
    bool b {true};
    QString msg;
    lens_->set_pos(Point(x_dsb_->value(), y_dsb_->value()));

    if (!lens_->set_width(width_dsb_->value()))
    {
        msg = "Incorrect width";
        b = false;
    }

    if (!lens_->set_height(height_dsb_->value()))
    {
        msg += "\nIncorrect height";
        b = false;
    }

    if (!lens_->set_wl_min(wl_min_dsb_->value()))
    {
        msg += "\nIncorrect min wavelength";
        b = false;
    }

    if (!lens_->set_wl_max(wl_max_dsb_->value()))
    {
        msg += "\nIncorrect max wavelength";
        b = false;
    }

    if (!b)
        QMessageBox::warning(this, "Incorrect Data", msg);

    reset();

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
