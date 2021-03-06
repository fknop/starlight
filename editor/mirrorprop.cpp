#include <QMessageBox>

#include "editor/mirrorprop.h"
#include "utils/constants.h"


MirrorProp::MirrorProp(Mirror * mirror, QWidget * parent) : mirror_{mirror}
{
    mirror_->add_observer(this);
    setup_ui();
    reset();
}

MirrorProp::~MirrorProp()
{
    mirror_->remove_observer(this);
}

void MirrorProp::setup_ui()
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

    length_label_ = new QLabel("Length");
    length_label_->setMinimumSize(QSize(100, 20));

    length_dsb_ = new QDoubleSpinBox();
    length_dsb_->setMaximum(999.);

    xpad_label_ = new QLabel("Xpad");
    xpad_label_->setMinimumSize(QSize(100, 20));

    xpad_dsb_ = new QDoubleSpinBox();
    xpad_dsb_->setMaximum(999.);

    alpha_label_ = new QLabel("Alpha");
    alpha_label_->setMinimumSize(QSize(100, 20));

    alpha_dsb_ = new QDoubleSpinBox();
    alpha_dsb_->setDecimals(5);
    alpha_dsb_->setMaximum(PI*2);
    alpha_dsb_->setMinimum(-PI*2);

    xmin_label_ = new QLabel("X Min");
    xmin_label_->setMinimumSize(QSize(100, 20));

    xmin_dsb_ = new QDoubleSpinBox();
    xmin_dsb_->setMaximum(999.);

    xmax_label_ = new QLabel("X Max");
    xmax_label_->setMinimumSize(QSize(100, 20));

    xmax_dsb_ = new QDoubleSpinBox();
    xmax_dsb_->setMaximum(999.);

    ymin_label_ = new QLabel("Y Min");
    ymin_label_->setMinimumSize(QSize(100, 20));

    ymin_dsb_ = new QDoubleSpinBox();
    ymin_dsb_->setMaximum(999.);

    ymax_label_ = new QLabel("Y Max");
    ymax_label_->setMinimumSize(QSize(100, 20));

    ymax_dsb_ = new QDoubleSpinBox();
    ymax_dsb_->setMaximum(999.);

    alphamin_label_ = new QLabel("Alpha min");
    alphamin_label_->setMinimumSize(QSize(100, 20));

    alphamin_dsb_ = new QDoubleSpinBox();
    alphamin_dsb_->setMaximum(999.);

    alphamax_label_ = new QLabel("Alpha max");
    alphamax_label_->setMinimumSize(QSize(100, 20));

    alphamax_dsb_ = new QDoubleSpinBox();
    alphamax_dsb_->setMaximum(999.);

    form_layout_->setWidget(0, QFormLayout::LabelRole, x_label_);
    form_layout_->setWidget(0, QFormLayout::FieldRole, x_dsb_);
    form_layout_->setWidget(1, QFormLayout::LabelRole, y_label_);
    form_layout_->setWidget(1, QFormLayout::FieldRole, y_dsb_);
    form_layout_->setWidget(2, QFormLayout::LabelRole, length_label_);
    form_layout_->setWidget(2, QFormLayout::FieldRole, length_dsb_);
    form_layout_->setWidget(3, QFormLayout::LabelRole, xpad_label_);
    form_layout_->setWidget(3, QFormLayout::FieldRole, xpad_dsb_);
    form_layout_->setWidget(4, QFormLayout::LabelRole, alpha_label_);
    form_layout_->setWidget(4, QFormLayout::FieldRole, alpha_dsb_);
    form_layout_->setWidget(5, QFormLayout::LabelRole, xmin_label_);
    form_layout_->setWidget(5, QFormLayout::FieldRole, xmin_dsb_);
    form_layout_->setWidget(6, QFormLayout::LabelRole, xmax_label_);
    form_layout_->setWidget(6, QFormLayout::FieldRole, xmax_dsb_);
    form_layout_->setWidget(7, QFormLayout::LabelRole, ymin_label_);
    form_layout_->setWidget(7, QFormLayout::FieldRole, ymin_dsb_);
    form_layout_->setWidget(8, QFormLayout::LabelRole, ymax_label_);
    form_layout_->setWidget(8, QFormLayout::FieldRole, ymax_dsb_);
    form_layout_->setWidget(9, QFormLayout::LabelRole, alphamin_label_);
    form_layout_->setWidget(9, QFormLayout::FieldRole, alphamin_dsb_);
    form_layout_->setWidget(10, QFormLayout::LabelRole, alphamax_label_);
    form_layout_->setWidget(10, QFormLayout::FieldRole, alphamax_dsb_);

    setLayout(form_layout_);
}

void MirrorProp::apply()
{
    bool b = true;
    QString msg;
    if (!mirror_->set_pivot(Point(x_dsb_->value(), y_dsb_->value())))
    {
        msg = "Incorrect pivot";
        b = false;
    }

    if (!mirror_->set_xpad_len(xpad_dsb_->value(), length_dsb_->value()))
    {
        msg += "\nIncorrect length \n Incorrect xpad";
        b = false;
    }

    if (!(mirror_->set_angle(std::fmod(alpha_dsb_->value(), PI*2))))
    {
        msg += "\nIncorrect angle";
        b = false;
    }

    mirror_->set_min(Point(xmin_dsb_->value(), ymin_dsb_->value()));
    mirror_->set_max(Point(xmax_dsb_->value(), ymax_dsb_->value()));
    mirror_->set_alpha_min(alphamin_dsb_->value());
    mirror_->set_alpha_max(alphamax_dsb_->value());

    if (!b)
        QMessageBox::warning(this, "Incorrect Data", msg);

    reset();
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
