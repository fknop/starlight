#include "maineditor.h"

#include <QHBoxLayout>

#include <QPushButton>

#include <QMenuBar>
#include <QFormLayout>

#include "view/mapview.h"
#include "properties.h"

#include "view/sourceview.h"
#include "view/destinationview.h"

#include "elements.h"

MainEditor::MainEditor(QWidget *parent) : QMainWindow(parent), level_{new Level(750,580)}
{
    setupUi();
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
    std::cout << "MAIN ADD WALL" << std::endl;
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


    centralWidget = new QWidget();

    horizontalLayout = new QHBoxLayout(centralWidget);
    horizontalLayout->setSpacing(6);
    horizontalLayout->setContentsMargins(11, 11, 11, 11);

    elements = new Elements();
    elements->add_observer(this);
    horizontalLayout->addWidget(elements);


    horizontalLayout->addWidget(elements);

    mapview_ = new QWidget(); //new MapView();
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

void MainEditor::notify(Observable * sdo, std::string msg="UPDATE_RAYS", const std::vector<std::string> &args)
{
    std::cout << msg << std::endl;
    if (msg == "LEVEL_CREATED")
    {
        std::cout << "level added!" << std::endl;
        create_level();
    }
    else if (msg == "LEVEL_RESET")
    {
        std::cout << "level reset" << std::endl;
        mapview_->clear();
    }
    else if (msg == "MIRROR_ADDED")
    {
        std::cout << "[MainEditor - notify] - mirror added!" << std::endl;
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

        std::cout << "ELEMENT_DELETED" << std::endl;

        mapview_->repaint();
        std::cout << "scene repainted" << std::endl;
    }
    else if (msg == "ELEMENT_CHANGED")
    {
        mapview_->repaint();
    }
}
