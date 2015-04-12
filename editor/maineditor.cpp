#include "maineditor.h"

#include <QCoreApplication>
#include <QFileDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>

#include "elements.h"
#include "mapreader.h"
#include "mapwriter.h"
#include "properties.h"
#include "view/destinationview.h"
#include "view/mapview.h"
#include "view/sourceview.h"


MainEditor::MainEditor(QWidget *parent) : QMainWindow(parent), level_{new Level(750, 580)}
{
    setupUi();

    mapview_ = nullptr;
}

void MainEditor::add_crystal()
{
    Crystal crystal(Point(50, 50), 29, 40);
    level_->add_crystal(crystal);
    mapview_->draw_crystals();
}

void MainEditor::add_lens()
{
    Lens lens(Point(50, 50), 58, 116, 500, 600);
    level_->add_lens(lens);
    mapview_->draw_lenses();
}

void MainEditor::add_mirror()
{
    Mirror mirror(Point(50, 50), 58, 100, 1.57);
    level_->add_mirror(mirror);
    mapview_->draw_mirrors();
}

void MainEditor::add_nuke()
{
    Nuke nuke(Point(50, 50), 29);
    level_->add_nuke(nuke);
    mapview_->draw_nukes();
}

void MainEditor::add_wall()
{
    Wall wall(Point(20, 20), Point(60, 60));
    level_->add_wall(wall);
    mapview_->draw_walls();
}

ElementView * MainEditor::selected()
{
    return mapview_->selected();
}

void MainEditor::create_level()
{
    level_ = elements->level();

    Source source(Point(0,0), 29, 4.75, 400);
    Dest dest(Point(level_->width() - 29, level_->height() - 29), 29);

    level_->set_source(source);
    level_->set_dest(dest);

    verticalLayout_2->removeWidget(mapview_);
    mapview_ = new MapView(level_);
    level_->add_observer(mapview_);
    mapview_->add_observer(this);
    verticalLayout_2->addWidget(mapview_);
}

void MainEditor::setupUi()
{
    resize(975, 649);

    menu_bar_ = new QMenuBar(this);

    file_menu_ = menu_bar_->addMenu("&File");

    load_level_action_ = new QAction("&Load level", menu_bar_);
    load_level_action_->setShortcuts(QKeySequence::Open);
    load_level_action_->setStatusTip("Load a Starlight level");
    connect(load_level_action_, SIGNAL(triggered()), this, SLOT(load_level()));

    file_menu_->addAction(load_level_action_);


    save_level_action_ = new QAction("&Save level", menu_bar_);
    save_level_action_->setShortcuts(QKeySequence::Save);
    save_level_action_->setStatusTip("Save a Starlight level");
    connect(save_level_action_, SIGNAL(triggered()), this, SLOT(save_level()));

    file_menu_->addAction(save_level_action_);


    quit_action_ = new QAction("&Quit", menu_bar_);
    quit_action_->setShortcuts(QKeySequence::Quit);
    quit_action_->setStatusTip("Quit the editor");
    connect(quit_action_, &QAction::triggered, &QCoreApplication::quit);

    file_menu_->addAction(quit_action_);

    setMenuBar(menu_bar_);


    centralWidget = new QWidget();

    horizontalLayout = new QHBoxLayout(centralWidget);
    horizontalLayout->setSpacing(6);
    horizontalLayout->setContentsMargins(11, 11, 11, 11);

    elements = new Elements();
    elements->add_observer(this);
    horizontalLayout->addWidget(elements);


    horizontalLayout->addWidget(elements);

    mapview_ = new QWidget();
    verticalLayout_2 = new QVBoxLayout(mapview_);
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setContentsMargins(11, 11, 11, 11);


    QSizePolicy sp_mapview(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_mapview.setHorizontalStretch(4);
    mapview_->setSizePolicy(sp_mapview);

    horizontalLayout->addWidget(mapview_);

    properties = new Properties(centralWidget);
    properties->add_observer(this);



    QSizePolicy sp_properties(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_properties.setHorizontalStretch(1);
    properties->setSizePolicy(sp_properties);

    horizontalLayout->addWidget(properties);

    setCentralWidget(centralWidget);
}

void MainEditor::load_level()
{
    QString file_name = QFileDialog::getOpenFileName(
                this, tr("Load Starlight level"), "levels/", tr("Files .lvl (*.lvl)"));


        MapReader::end_level();
        level_ = MapReader::level(file_name.toStdString());


    verticalLayout_2->removeWidget(mapview_);

    mapview_ = new MapView(level_);
    level_->add_observer(mapview_);
    mapview_->add_observer(this);

    verticalLayout_2->addWidget(mapview_);

    elements->set_height(level_->height());
    elements->set_width(level_->width());
}

void MainEditor::save_level()
{
    QString file_name = QFileDialog::getSaveFileName(
                this, tr("Save Starlight level"), "levels/", tr("Files .lvl (*.lvl)"));

    if (file_name != nullptr && level_)
    {
        MapWriter::write(level_, file_name.toStdString());
    }
}

void MainEditor::notify(Observable * sdo, std::string msg="UPDATE_RAYS", const std::vector<std::string> &args)
{
    if (msg == "LEVEL_CREATED")
    {
        create_level();
    }
    else if (msg == "LEVEL_RESET")
    {
        mapview_->clear();
    }
    else if (msg == "MIRROR_ADDED")
    {
        add_mirror();
    }
    else if (msg == "CRYSTAL_ADDED")
    {
        add_crystal();
    }
    else if (msg == "LENS_ADDED")
    {
        add_lens();
    }
    else if (msg == "NUKE_ADDED")
    {
        add_nuke();
    }
    else if (msg == "WALL_ADDED")
    {
        add_wall();
    }
    else if (msg == "SELECTED")
    {
        properties->set_element_prop(selected());
    }
    else if (msg == "ELEMENT_DELETED")
    {
        if (mapview_->selected())
        {
            switch (mapview_->selected()->type_view())
            {
            case ElementView::TypeView::CRYSTALVIEW:
            {
                CrystalView * cv = dynamic_cast<CrystalView *> (selected());
                level_->remove_crystal(*cv->crystal());
                break;
            }
            case ElementView::TypeView::LENSVIEW:
            {
                LensView * lv = dynamic_cast<LensView *> (selected());
                level_->remove_lens(*lv->lens());
                break;
            }
            case ElementView::TypeView::MIRRORVIEW:
            {
                MirrorView * mv = dynamic_cast<MirrorView *> (selected());
                level_->remove_mirror(*mv->mirror());
                break;
            }
            case ElementView::TypeView::NUKEVIEW:
            {
                NukeView * nv = dynamic_cast<NukeView *> (selected());
                level_->remove_nuke(*nv->nuke());
                break;
            }
            case ElementView::TypeView::WALLVIEW:
            {
                WallView * wv = dynamic_cast<WallView *> (selected());
                level_->remove_wall(*wv->wall());
                break;
            }
            }
        }

        mapview_->repaint();
    }
    else if (msg == "ELEMENT_CHANGED")
    {
        mapview_->repaint();
    }
}
