#include <sstream>

#include "editor/elements.h"


Elements::Elements(QWidget * parent) : QWidget(parent)
{
    setup_ui();
    add_connections();
    enable_pushbuttons(false);
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

    group_box_ = new QGroupBox("Level");

    QFormLayout * form_layout_ = new QFormLayout(group_box_);

    level_height_label_ = new QLabel("Height: ", group_box_);
    level_height_dsb_ = new QDoubleSpinBox(group_box_);
    level_height_dsb_->setMinimum(400);
    level_height_dsb_->setMaximum(1000);

    level_width_label_ = new QLabel("Width: ", group_box_);
    level_width_dsb_ = new QDoubleSpinBox(group_box_);
    level_width_dsb_->setMinimum(400);
    level_width_dsb_->setMaximum(1000);

    level_apply_pb_ = new QPushButton("Apply");
    level_reset_pb_ = new QPushButton("Reset");

    form_layout_->setWidget(0, QFormLayout::LabelRole, level_height_label_);
    form_layout_->setWidget(0, QFormLayout::FieldRole, level_height_dsb_);
    form_layout_->setWidget(1, QFormLayout::LabelRole, level_width_label_);
    form_layout_->setWidget(1, QFormLayout::FieldRole, level_width_dsb_);
    form_layout_->setWidget(2, QFormLayout::LabelRole, level_apply_pb_);
    form_layout_->setWidget(2, QFormLayout::FieldRole, level_reset_pb_);

    vertical_layout_->addWidget(group_box_);

    add_crystal_pb_ = new QPushButton("Crystal");
    add_lens_pb_ = new QPushButton("Lens");
    add_mirror_pb_ = new QPushButton("Mirror");
    add_nuke_pb_ = new QPushButton("Nuke");
    add_wall_pb_ = new QPushButton("Wall");

    vertical_layout_->addWidget(add_crystal_pb_);
    vertical_layout_->addWidget(add_lens_pb_);
    vertical_layout_->addWidget(add_mirror_pb_);
    vertical_layout_->addWidget(add_nuke_pb_);
    vertical_layout_->addWidget(add_wall_pb_);

    QSizePolicy sp_elements(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_elements.setHorizontalStretch(1);
    setSizePolicy(sp_elements);

    setLayout(vertical_layout_);
}

void Elements::create_level()
{
    enable_pushbuttons(true);
    std::ostringstream oss_w;
    std::ostringstream oss_h;
    oss_w << level_width_dsb_->value();
    oss_h << level_height_dsb_->value();
    std::vector<std::string> vec {oss_w.str(), oss_h.str()};
    notify_all(std::string("LEVEL_CREATED"), vec);
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
