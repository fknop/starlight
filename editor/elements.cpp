#include "editor/elements.h"

Elements::Elements(QWidget * parent) : QWidget(parent)
{
    setup_ui();
    add_connections();

    add_crystal_pb_->setEnabled(false);
    add_mirror_pb_->setEnabled(false);
    add_nuke_pb_->setEnabled(false);
    add_lens_pb_->setEnabled(false);
    add_wall_pb_->setEnabled(false);
}

void Elements::add_connections()
{
    connect(add_crystal_pb_, SIGNAL(clicked()), this, SLOT(add_crystal()));
    connect(add_lens_pb_, SIGNAL(clicked()), this, SLOT(add_lens()));
    connect(add_mirror_pb_, SIGNAL(clicked()), this, SLOT(add_mirror()));
    connect(add_nuke_pb_, SIGNAL(clicked()), this, SLOT(add_nuke()));
    connect(add_wall_pb_, SIGNAL(clicked()), this, SLOT(add_wall()));

    connect(level_apply_pb_, SIGNAL(clicked()), this, SLOT(create_level()));
    connect(level_reset_pb_, SIGNAL(clicked()), this, SLOT(reset_level()));
}

void Elements::setup_ui()
{
    vertical_layout_ = new QVBoxLayout();
    vertical_layout_->setSpacing(6);
    vertical_layout_->setContentsMargins(11, 11, 11, 11);

    group_box_ = new QGroupBox();
    group_box_->setTitle("Level");

    QFormLayout * form_layout_ = new QFormLayout(group_box_);

    level_height_label_ = new QLabel(group_box_);
    level_height_label_->setText("Height: ");

    form_layout_->setWidget(0, QFormLayout::LabelRole, level_height_label_);

    level_height_dsb_ = new QDoubleSpinBox(group_box_);
    level_height_dsb_->setMinimum(400);
    level_height_dsb_->setMaximum(1000);

    form_layout_->setWidget(0, QFormLayout::FieldRole, level_height_dsb_);

    level_width_label_ = new QLabel(group_box_);
    level_width_label_->setText("Width: ");

    form_layout_->setWidget(1, QFormLayout::LabelRole, level_width_label_);

    level_width_dsb_ = new QDoubleSpinBox(group_box_);
    level_width_dsb_->setMinimum(400);
    level_width_dsb_->setMaximum(1000);

    form_layout_->setWidget(1, QFormLayout::FieldRole, level_width_dsb_);

    level_apply_pb_ = new QPushButton();
    level_apply_pb_->setText("Apply");

    form_layout_->setWidget(2, QFormLayout::LabelRole, level_apply_pb_);

    level_reset_pb_ = new QPushButton();
    level_reset_pb_->setText("Reset");
    level_reset_pb_->setEnabled(false);

    form_layout_->setWidget(2, QFormLayout::FieldRole, level_reset_pb_);


    vertical_layout_->addWidget(group_box_);

    add_crystal_pb_ = new QPushButton("Crystal");

    vertical_layout_->addWidget(add_crystal_pb_);

    add_lens_pb_ = new QPushButton("Lens");

    vertical_layout_->addWidget(add_lens_pb_);

    add_mirror_pb_ = new QPushButton("Mirror");

    vertical_layout_->addWidget(add_mirror_pb_);

    add_nuke_pb_ = new QPushButton("Nuke");

    vertical_layout_->addWidget(add_nuke_pb_);

    add_wall_pb_ = new QPushButton("Wall");

    vertical_layout_->addWidget(add_wall_pb_);

    QSizePolicy sp_elements(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_elements.setHorizontalStretch(1);
    setSizePolicy(sp_elements);

    setLayout(vertical_layout_);
}

void Elements::create_level()
{
    level_ = new Level(level_width_dsb_->value(), level_height_dsb_->value());

    enable_pushbuttons(true);

    notify_all(std::string("LEVEL_CREATED"));
}

void Elements::reset_level()
{
    enable_pushbuttons(false);

    notify_all(std::string("LEVEL_RESET"));
}

void Elements::enable_pushbuttons(bool b)
{
    add_crystal_pb_->setEnabled(b);
    add_mirror_pb_->setEnabled(b);
    add_nuke_pb_->setEnabled(b);
    add_lens_pb_->setEnabled(b);
    add_wall_pb_->setEnabled(b);

    level_apply_pb_->setEnabled(!b);
    level_width_dsb_->setEnabled(!b);
    level_height_dsb_->setEnabled(!b);
    level_reset_pb_->setEnabled(b);
}

Level * Elements::level()
{
    return level_;
}

void Elements::set_height(int h)
{
    level_height_dsb_->setValue(h);
}

void Elements::set_width(int w)
{
    level_width_dsb_->setValue(w);
}

void Elements::add_crystal()
{
    notify_all(std::string("CRYSTAL_ADDED"));
}

void Elements::add_lens()
{
    notify_all(std::string("LENS_ADDED"));
}

void Elements::add_mirror()
{
    notify_all(std::string("MIRROR_ADDED"));
}

void Elements::add_nuke()
{
    notify_all(std::string("NUKE_ADDED"));
}

void Elements::add_wall()
{
    notify_all(std::string("WALL_ADDED"));
}
