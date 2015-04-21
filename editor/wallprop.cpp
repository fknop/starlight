#include "wallprop.h"

/**
 * Modifie le mur sélectionné dans l’éditeur.
 * @param wall le mur sélectionné.
 * @param parent le widget parent.
 */
WallProp::WallProp(Wall * wall, QWidget * parent) : wall_{wall}
{
    setupUi();

    wall_->add_observer(this);

    reset();
}

WallProp::~WallProp()
{
    wall_->remove_observer(this);
}

void WallProp::setupUi()
{
    form_layout_ = new QFormLayout();

    x1_label_ = new QLabel();
    x1_label_->setText("X1");
    x1_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(0, QFormLayout::LabelRole, x1_label_);

    x1_dsb_ = new QDoubleSpinBox();
    x1_dsb_->setMaximum(999.);
    x1_dsb_->setMinimum(-999.);


    form_layout_->setWidget(0, QFormLayout::FieldRole, x1_dsb_);

    y1_label_ = new QLabel();
    y1_label_->setText("Y1");
    y1_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(1, QFormLayout::LabelRole, y1_label_);

    y1_dsb_ = new QDoubleSpinBox();
    y1_dsb_->setMaximum(999.);
    y1_dsb_->setMinimum(-999.);

    form_layout_->setWidget(1, QFormLayout::FieldRole, y1_dsb_);

    x2_label_ = new QLabel();
    x2_label_->setText("X2");
    x2_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(5, QFormLayout::LabelRole, x2_label_);

    x2_dsb_ = new QDoubleSpinBox();
    x2_dsb_->setMaximum(999.);
    x2_dsb_->setMinimum(-999.);

    form_layout_->setWidget(5, QFormLayout::FieldRole, x2_dsb_);

    y2_label_ = new QLabel();
    y2_label_->setText("Y2");
    y2_label_->setMinimumSize(QSize(100, 20));

    form_layout_->setWidget(6, QFormLayout::LabelRole, y2_label_);

    y2_dsb_ = new QDoubleSpinBox();
    y2_dsb_->setMaximum(999.);
    y2_dsb_->setMinimum(-999.);

    form_layout_->setWidget(6, QFormLayout::FieldRole, y2_dsb_);

    setLayout(form_layout_);
}

/**
 * Applique les changements effectués à l’objet wall qu’il contient.
 */
void WallProp::apply()
{
    wall_->set_start(Point(x1_dsb_->value(), y1_dsb_->value()));
    wall_->set_end(Point(x2_dsb_->value(), y2_dsb_->value()));
}

/**
 * Modifie les spinbox pour qu’elles prennent les valeurs du mur.
 */
void WallProp::reset()
{
    x1_dsb_->setValue(wall_->start().x());
    y1_dsb_->setValue(wall_->start().y());
    x2_dsb_->setValue(wall_->end().x());
    y2_dsb_->setValue(wall_->end().y());
}
