#include "editor/elements.h"

/**
 * Permet de créer un niveau et d’y ajouter des éléments (miroir, lensille, etc.).
 * @param parent le widget parent, la fenêtre principale de l’éditeur en l’occurrence.
 */
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

    QFormLayout * form_layout_ = new QFormLayout(groupBox);

    level_height_label = new QLabel(groupBox);
    level_height_label->setText("Height: ");

    form_layout_->setWidget(0, QFormLayout::LabelRole, level_height_label);

    level_height_dsb = new QDoubleSpinBox(groupBox);
    level_height_dsb->setMinimum(400);
    level_height_dsb->setMaximum(1000);

    form_layout_->setWidget(0, QFormLayout::FieldRole, level_height_dsb);

    level_width_label = new QLabel(groupBox);
    level_width_label->setText("Width: ");

    form_layout_->setWidget(1, QFormLayout::LabelRole, level_width_label);

    level_width_dsb = new QDoubleSpinBox(groupBox);
    level_width_dsb->setMinimum(400);
    level_width_dsb->setMaximum(1000);

    form_layout_->setWidget(1, QFormLayout::FieldRole, level_width_dsb);

    level_apply_pb = new QPushButton();
    level_apply_pb->setText("Apply");

    form_layout_->setWidget(2, QFormLayout::LabelRole, level_apply_pb);

    level_reset_pb = new QPushButton();
    level_reset_pb->setText("Reset");
    level_reset_pb->setEnabled(false);

    form_layout_->setWidget(2, QFormLayout::FieldRole, level_reset_pb);


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

/**
 * Crée un nouveau niveau avec les dimensions précisées.
 */
void Elements::create_level()
{
    level_ = new Level(level_width_dsb->value(), level_height_dsb->value());

    enable_pushbuttons(true);

    notify_all(std::string("LEVEL_CREATED"));
}

/**
 * Supprime le niveau actuel.
 */
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

/**
 * Retourne le niveau.
 * @return  le niveau.
 */
Level * Elements::level()
{
    return level_;
}

/**
 * Modifie la taille du niveau.
 * @param h la hauteur de la carte du niveau.
 */
void Elements::set_height(int h)
{
    level_height_dsb->setValue(h);
}

/**
 * Modifie la largeur du niveau.
 * @param w la largeur de la carte du niveau.
 */
void Elements::set_width(int w)
{
    level_width_dsb->setValue(w);
}

/**
 * Indique à tous les observateurs qu’un cristal a été ajouté.
 */
void Elements::add_crystal()
{
    notify_all(std::string("CRYSTAL_ADDED"));
}

/**
 * Indique à tous les observateurs qu’une lentille a été ajoutée.
 */
void Elements::add_lens()
{
    notify_all(std::string("LENS_ADDED"));
}

/**
 * Indique à tous les observateurs qu’un miroir a été ajouté.
 */
void Elements::add_mirror()
{
    notify_all(std::string("MIRROR_ADDED"));
}

/**
 * Indique à tous les observateurs qu’une bombe a été ajoutée.
 */
void Elements::add_nuke()
{
    notify_all(std::string("NUKE_ADDED"));
}

/**
 * Indique à tous les observateurs qu’un mur a été ajouté.
 */
void Elements::add_wall()
{
    notify_all(std::string("WALL_ADDED"));
}
