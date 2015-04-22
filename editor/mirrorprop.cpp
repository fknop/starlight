#include "editor/mirrorprop.h"
#include "utils/constants.h"


MirrorProp::MirrorProp(Mirror * mirror, QWidget * parent) : mirror_{mirror}
{
    setupUi();

    mirror_->add_observer(this);

    reset();
}

MirrorProp::~MirrorProp()
{
    mirror_->remove_observer(this);
}

void MirrorProp::setupUi()
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

    length_label_ = new QLabel();
    length_label_->setText("Length");
    length_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(2, QFormLayout::LabelRole, length_label_);

    length_dsb_ = new QDoubleSpinBox();
    length_dsb_->setMaximum(999.);

    form_layout_->setWidget(2, QFormLayout::FieldRole, length_dsb_);

    xpad_label_ = new QLabel();
    xpad_label_->setText("Xpad");
    xpad_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(3, QFormLayout::LabelRole, xpad_label_);

    xpad_dsb_ = new QDoubleSpinBox();
    xpad_dsb_->setMaximum(999.);

    form_layout_->setWidget(3, QFormLayout::FieldRole, xpad_dsb_);

    alpha_label_ = new QLabel();
    alpha_label_->setText("Alpha");
    alpha_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(4, QFormLayout::LabelRole, alpha_label_);

    alpha_dsb_ = new QDoubleSpinBox();
    alpha_dsb_->setDecimals(5);
    alpha_dsb_->setMaximum(PI*2);
    alpha_dsb_->setMinimum(-PI*2);


    form_layout_->setWidget(4, QFormLayout::FieldRole, alpha_dsb_);

    xmin_label_ = new QLabel();
    xmin_label_->setText("X min");
    xmin_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(5, QFormLayout::LabelRole, xmin_label_);

    xmin_dsb_ = new QDoubleSpinBox();
    xmin_dsb_->setMaximum(999.);

    form_layout_->setWidget(5, QFormLayout::FieldRole, xmin_dsb_);

    xmax_label_ = new QLabel();
    xmax_label_->setText("X max");
    xmax_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(6, QFormLayout::LabelRole, xmax_label_);

    xmax_dsb_ = new QDoubleSpinBox();
    xmax_dsb_->setMaximum(999.);

    form_layout_->setWidget(6, QFormLayout::FieldRole, xmax_dsb_);

    ymin_label_ = new QLabel();
    ymin_label_->setText("Y min");
    ymin_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(7, QFormLayout::LabelRole, ymin_label_);

    ymin_dsb_ = new QDoubleSpinBox();
    ymin_dsb_->setMaximum(999.);

    form_layout_->setWidget(7, QFormLayout::FieldRole, ymin_dsb_);

    ymax_label_ = new QLabel();
    ymax_label_->setText("Y max");
    ymax_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(8, QFormLayout::LabelRole, ymax_label_);

    ymax_dsb_ = new QDoubleSpinBox();
    ymax_dsb_->setMaximum(999.);

    form_layout_->setWidget(8, QFormLayout::FieldRole, ymax_dsb_);

    alphamin_label_ = new QLabel();
    alphamin_label_->setText("Alpha min");
    alphamin_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(9, QFormLayout::LabelRole, alphamin_label_);

    alphamin_dsb_ = new QDoubleSpinBox();
    alphamin_dsb_->setMaximum(999.);

    form_layout_->setWidget(9, QFormLayout::FieldRole, alphamin_dsb_);

    alphamax_label_ = new QLabel();
    alphamax_label_->setText("Alpha max");
    alphamax_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(10, QFormLayout::LabelRole, alphamax_label_);

    alphamax_dsb_ = new QDoubleSpinBox();
    alphamax_dsb_->setMaximum(999.);

    form_layout_->setWidget(10, QFormLayout::FieldRole, alphamax_dsb_);

    setLayout(form_layout_);
}

void MirrorProp::apply()
{
    mirror_->set_pivot(Point(x_dsb_->value(), y_dsb_->value()));
    mirror_->set_len(length_dsb_->value());
    mirror_->set_xpad(xpad_dsb_->value());
    mirror_->set_angle(std::fmod(alpha_dsb_->value(), PI*2));
    mirror_->set_min(Point(xmin_dsb_->value(), ymin_dsb_->value()));
    mirror_->set_max(Point(xmax_dsb_->value(), ymax_dsb_->value()));
    mirror_->set_alpha_min(alphamin_dsb_->value());
    mirror_->set_alpha_max(alphamax_dsb_->value());
}

void MirrorProp::reset()
{
    x_dsb_->setValue(mirror_->pivot().x());
    y_dsb_->setValue(mirror_->pivot().y());
    length_dsb_->setValue(mirror_->length());
    xpad_dsb_->setValue(mirror_->x_pad());
    alpha_dsb_->setValue(std::fmod(mirror_->angle(), PI*2));
    xmin_dsb_->setValue(mirror_->min_pivot().x());
    xmax_dsb_->setValue(mirror_->max_pivot().x());
    ymin_dsb_->setValue(mirror_->min_pivot().y());
    ymax_dsb_->setValue(mirror_->max_pivot().y());
    alphamin_dsb_->setValue(mirror_->min_angle());
    alphamax_dsb_->setValue(mirror_->max_angle());
}
