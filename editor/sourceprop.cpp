#include "sourceprop.h"

SourceProp::SourceProp(Source *source, QWidget *parent) : source_{source}
{
    setupUi();
    reset();
}

void SourceProp::setupUi()
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

    edge_label = new QLabel();
    edge_label->setText("Edge");
    edge_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(2, QFormLayout::LabelRole, edge_label);

    edge_dsb = new QDoubleSpinBox();

    formLayout->setWidget(2, QFormLayout::FieldRole, edge_dsb);

    wavelength_label = new QLabel();
    wavelength_label->setText("Wavelength");
    wavelength_label->setMinimumSize(QSize(100, 20));

    formLayout->setWidget(3, QFormLayout::LabelRole, wavelength_label);

    wavelength_dsb = new QDoubleSpinBox();

    formLayout->setWidget(3, QFormLayout::FieldRole, wavelength_dsb);

    setLayout(formLayout);
}

void SourceProp::reset()
{
//    x_dsb->setValue(mirror_->pivot().x());
//    y_dsb->setValue(mirror_->pivot().y());
//    edge_dsb->setValue(mirror_->edge());
//    wavelength_dsb->setValue(mirror_->x_pad());
//    alpha_dsb->setValue(mirror_->angle());
//    xmin_dsb->setValue(mirror_->min_pivot().x());
//    xmax_dsb->setValue(mirror_->max_pivot().x());
//    ymin_dsb->setValue(mirror_->min_pivot().y());
//    ymax_dsb->setValue(mirror_->max_pivot().y());
//    alphamin_dsb->setValue(mirror_->min_angle());
//    alphamax_dsb->setValue(mirror_->max_angle());
}

void SourceProp::apply()
{
//    mirror_->set_pivot(Point(x_dsb->value(), y_dsb->value()));
    //mirror_->set_angle();
}
