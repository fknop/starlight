#include "mirrorprop.h"

MirrorProp::MirrorProp(Mirror *mirror, QWidget *parent) :
    QWidget(parent), mirror_{mirror}
{
    setupUi();
    reset();
}

void MirrorProp::setupUi()
{
    formLayout = new QFormLayout();

    x_label = new QLabel();
    x_label->setText("X");
    x_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(0, QFormLayout::LabelRole, x_label);

    x_dsb = new QDoubleSpinBox();

    formLayout->setWidget(0, QFormLayout::FieldRole, x_dsb);

    y_label = new QLabel();
    y_label->setText("Y");
    y_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(1, QFormLayout::LabelRole, y_label);

    y_dsb = new QDoubleSpinBox();

    formLayout->setWidget(1, QFormLayout::FieldRole, y_dsb);

    length_label = new QLabel();
    length_label->setText("Length");
    length_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(2, QFormLayout::LabelRole, length_label);

    length_dsb = new QDoubleSpinBox();

    formLayout->setWidget(2, QFormLayout::FieldRole, length_dsb);

    xpad_label = new QLabel();
    xpad_label->setText("Xpad");
    xpad_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(3, QFormLayout::LabelRole, xpad_label);

    xpad_dsb = new QDoubleSpinBox();

    formLayout->setWidget(3, QFormLayout::FieldRole, xpad_dsb);

    alpha_label = new QLabel();
    alpha_label->setText("Alpha");
    alpha_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(4, QFormLayout::LabelRole, alpha_label);

    alpha_dsb = new QDoubleSpinBox();

    formLayout->setWidget(4, QFormLayout::FieldRole, alpha_dsb);

    xmin_label = new QLabel();
    xmin_label->setText("X min");
    xmin_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(5, QFormLayout::LabelRole, xmin_label);

    xmin_dsb = new QDoubleSpinBox();

    formLayout->setWidget(5, QFormLayout::FieldRole, xmin_dsb);

    xmax_label = new QLabel();
    xmax_label->setText("X max");
    xmax_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(6, QFormLayout::LabelRole, xmax_label);

    xmax_dsb = new QDoubleSpinBox();

    formLayout->setWidget(6, QFormLayout::FieldRole, xmax_dsb);

    ymin_label = new QLabel();
    ymin_label->setText("Y min");
    ymin_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(7, QFormLayout::LabelRole, ymin_label);

    ymin_dsb = new QDoubleSpinBox();

    formLayout->setWidget(7, QFormLayout::FieldRole, ymin_dsb);

    ymax_label = new QLabel();
    ymax_label->setText("Y max");
    ymax_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(8, QFormLayout::LabelRole, ymax_label);

    ymax_dsb = new QDoubleSpinBox();

    formLayout->setWidget(8, QFormLayout::FieldRole, ymax_dsb);

    alphamin_label = new QLabel();
    alphamin_label->setText("Alpha min");
    alphamin_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(9, QFormLayout::LabelRole, alphamin_label);

    alphamin_dsb = new QDoubleSpinBox();

    formLayout->setWidget(9, QFormLayout::FieldRole, alphamin_dsb);

    alphamax_label = new QLabel();
    alphamax_label->setText("Alpha max");
    alphamax_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(10, QFormLayout::LabelRole, alphamax_label);

    alphamax_dsb = new QDoubleSpinBox();

    formLayout->setWidget(10, QFormLayout::FieldRole, alphamax_dsb);

    setLayout(formLayout);
}

void MirrorProp::reset()
{
    x_dsb->setValue(mirror_->pivot().x());
    y_dsb->setValue(mirror_->pivot().y());
    length_dsb->setValue(mirror_->length());
    xpad_dsb->setValue(mirror_->x_pad());
    alpha_dsb->setValue(mirror_->angle());
    xmin_dsb->setValue(mirror_->x_min());
    xmax_dsb->setValue(mirror_->x_max());
    ymin_dsb->setValue(mirror_->y_min());
    ymax_dsb->setValue(mirror_->y_max());
    alphamin_dsb->setValue(mirror_->alpha_min());
    alphamax_dsb->setValue(mirror_->alpha_max());
}

void MirrorProp::apply()
{
    mirror_->set_pivot(Point(x_dsb->value(), y_dsb->value()));
    //mirror_->set_angle();
}
