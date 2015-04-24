#include <QMessageBox>

#include "editor/wallprop.h"


WallProp::WallProp(Wall * wall, QWidget * parent) : wall_{wall}
{
    wall_->add_observer(this);
    setup_ui();
    reset();
}

WallProp::~WallProp()
{
    wall_->remove_observer(this);
}

void WallProp::setup_ui()
{
    form_layout_ = new QFormLayout();

    x1_label_ = new QLabel("X1");
    x1_label_->setMinimumSize(QSize(100, 20));

    x1_dsb_ = new QDoubleSpinBox();
    x1_dsb_->setMaximum(999.);
    x1_dsb_->setMinimum(-999.);

    y1_label_ = new QLabel("Y1");
    y1_label_->setMinimumSize(QSize(100, 20));

    y1_dsb_ = new QDoubleSpinBox();
    y1_dsb_->setMaximum(999.);
    y1_dsb_->setMinimum(-999.);

    x2_label_ = new QLabel("X2");
    x2_label_->setMinimumSize(QSize(100, 20));

    x2_dsb_ = new QDoubleSpinBox();
    x2_dsb_->setMaximum(999.);
    x2_dsb_->setMinimum(-999.);

    y2_label_ = new QLabel("Y2");
    y2_label_->setMinimumSize(QSize(100, 20));

    y2_dsb_ = new QDoubleSpinBox();
    y2_dsb_->setMaximum(999.);
    y2_dsb_->setMinimum(-999.);

    form_layout_->setWidget(0, QFormLayout::LabelRole, x1_label_);
    form_layout_->setWidget(0, QFormLayout::FieldRole, x1_dsb_);
    form_layout_->setWidget(1, QFormLayout::LabelRole, y1_label_);
    form_layout_->setWidget(1, QFormLayout::FieldRole, y1_dsb_);
    form_layout_->setWidget(5, QFormLayout::LabelRole, x2_label_);
    form_layout_->setWidget(5, QFormLayout::FieldRole, x2_dsb_);
    form_layout_->setWidget(6, QFormLayout::LabelRole, y2_label_);
    form_layout_->setWidget(6, QFormLayout::FieldRole, y2_dsb_);

    setLayout(form_layout_);
}

void WallProp::apply()
{
    bool b = true;
    QString msg;
    if (!wall_->set_start(Point(x1_dsb_->value(), y1_dsb_->value())))
    {
        msg = "Incorrect start";
        b = false;
    }
    if (!wall_->set_end(Point(x2_dsb_->value(), y2_dsb_->value())))
    {
        msg += "\nIncorrect end";
        b = false;
    }

    if (!b)
        QMessageBox::warning(this, "Incorrect Data", msg);

    reset();

}

void WallProp::reset()
{
    x1_dsb_->setValue(wall_->start().x());
    y1_dsb_->setValue(wall_->start().y());
    x2_dsb_->setValue(wall_->end().x());
    y2_dsb_->setValue(wall_->end().y());
}
