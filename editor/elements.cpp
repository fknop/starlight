#include "elements.h"

Elements::Elements(QWidget * parent) : QWidget(parent)
{
    setupUi();
    add_connections();

    add_crystal_pb->setEnabled(false);
    add_mirror_pb->setEnabled(false);
    add_nuke_pb->setEnabled(false);
    add_lens_pb->setEnabled(false);
    add_wall_pb->setEnabled(false);
}

void Elements::add_connections()
{
    connect(add_crystal_pb, SIGNAL(clicked()), this, SLOT(add_crystal()));
    connect(add_lens_pb, SIGNAL(clicked()), this, SLOT(add_lens()));
    connect(add_mirror_pb, SIGNAL(clicked()), this, SLOT(add_mirror()));
    connect(add_nuke_pb, SIGNAL(clicked()), this, SLOT(add_nuke()));
    connect(add_wall_pb, SIGNAL(clicked()), this, SLOT(add_wall()));

    connect(level_apply_pb, SIGNAL(clicked()), this, SLOT(create_level()));
    connect(level_reset_pb, SIGNAL(clicked()), this, SLOT(reset_level()));
}

void Elements::setupUi()
{
    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);

    groupBox = new QGroupBox();
    groupBox->setTitle("Level");

    QFormLayout * formLayout = new QFormLayout(groupBox);

    level_height_label = new QLabel(groupBox);
    level_height_label->setText("Height: ");

    formLayout->setWidget(0, QFormLayout::LabelRole, level_height_label);

    level_height_dsb = new QDoubleSpinBox(groupBox);
    level_height_dsb->setMinimum(400);
    level_height_dsb->setMaximum(1000);

    formLayout->setWidget(0, QFormLayout::FieldRole, level_height_dsb);

    level_width_label = new QLabel(groupBox);
    level_width_label->setText("Width: ");

    formLayout->setWidget(1, QFormLayout::LabelRole, level_width_label);

    level_width_dsb = new QDoubleSpinBox(groupBox);
    level_width_dsb->setMinimum(400);
    level_width_dsb->setMaximum(1000);

    formLayout->setWidget(1, QFormLayout::FieldRole, level_width_dsb);

    level_apply_pb = new QPushButton();
    level_apply_pb->setText("Apply");

    formLayout->setWidget(2, QFormLayout::LabelRole, level_apply_pb);

    level_reset_pb = new QPushButton();
    level_reset_pb->setText("Reset");
    level_reset_pb->setEnabled(false);

    formLayout->setWidget(2, QFormLayout::FieldRole, level_reset_pb);


    verticalLayout->addWidget(groupBox);

    add_crystal_pb = new QPushButton("Crystal");

    verticalLayout->addWidget(add_crystal_pb);

    add_lens_pb = new QPushButton("Lens");

    verticalLayout->addWidget(add_lens_pb);

    add_mirror_pb = new QPushButton("Mirror");

    verticalLayout->addWidget(add_mirror_pb);

    add_nuke_pb = new QPushButton("Nuke");

    verticalLayout->addWidget(add_nuke_pb);

    add_wall_pb = new QPushButton("Wall");

    verticalLayout->addWidget(add_wall_pb);

    QSizePolicy sp_elements(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_elements.setHorizontalStretch(1);
    setSizePolicy(sp_elements);

    setLayout(verticalLayout);
}

void Elements::create_level()
{
    level_ = new Level(level_width_dsb->value(), level_height_dsb->value());

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
    add_crystal_pb->setEnabled(b);
    add_mirror_pb->setEnabled(b);
    add_nuke_pb->setEnabled(b);
    add_lens_pb->setEnabled(b);
    add_wall_pb->setEnabled(b);

    level_apply_pb->setEnabled(!b);
    level_width_dsb->setEnabled(!b);
    level_height_dsb->setEnabled(!b);
    level_reset_pb->setEnabled(b);
}

Level * Elements::level()
{
    return level_;
}

void Elements::set_height(int h)
{
    level_height_dsb->setValue(h);
}

void Elements::set_width(int w)
{
    level_width_dsb->setValue(w);
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
