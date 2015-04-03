#include <QGraphicsScene>
#include <iostream>

#include "view/crystalview.h"
#include "view/destinationview.h"
#include "view/lensview.h"
#include "view/mapview.h"
#include "view/mirrorview.h"
#include "view/nukeview.h"
#include "view/sourceview.h"
#include "view/wallview.h"
#include "view/rayview.h"


MapView::MapView(Level ** level) : level_{*level}
{
    scene_ = new QGraphicsScene(0, 0, this->level_->width(), this->level_->height());

    setScene(scene_);
    setRenderHints(QPainter::Antialiasing);
    setFixedSize(this->level_->width() + 30, this->level_->height() + 30);


    level_->compute_rays();
    Source s = level_->source();
    Dest d = level_->dest();

    SourceView *source = new SourceView(s.position().x(), s.position().y(), s.edge(), s.edge());
    DestinationView *dest = new DestinationView(d.position().x(), d.position().y(), d.edge(), d.edge());

    scene_->addItem(source);
    scene_->addItem(dest);




    for (auto &i : this->level_->walls())
    {
        draw_wall(scene_, i);
    }

    for (auto &i : this->level_->mirrors())
    {
        draw_mirror(scene_, i);
    }

    for (auto &i : this->level_->nukes())
    {
        draw_nuke(scene_, i);
    }

    for (auto &i : this->level_->lenses())
    {
        draw_lens(scene_, i);
    }

    for (auto &i : this->level_->crystals())
    {
        draw_crystal(scene_, i);
    }

    for (auto &i : this->level_->rays())
    {
        draw_ray(scene_, i);
    }

}

void MapView::draw_ray(QGraphicsScene* s, const Ray &ray)
{
    RayView *item = new RayView(ray);

    s->addItem(item);
}

void MapView::draw_wall(QGraphicsScene *s, const Wall& wall)
{
    WallView *item1 = new WallView(wall);

    s->addItem(item1);
}


void MapView::draw_mirror(QGraphicsScene *s, const Mirror& mirror)
{
    MirrorView *item1 = new MirrorView(mirror);

    s->addItem(item1);
}


void MapView::draw_nuke(QGraphicsScene *s, const Nuke& nuke)
{
    NukeView *item1 = new NukeView(nuke);

    s->addItem(item1);
}

void MapView::draw_lens(QGraphicsScene *s, const Lens& lens)
{
    LensView *item1 = new LensView(lens);

    s->addItem(item1);
}

void MapView::draw_crystal(QGraphicsScene *s, const Crystal& crystal)
{
    CrystalView *item1 = new CrystalView(crystal);

    s->addItem(item1);
}


void MapView::keyPressEvent(QKeyEvent *event)
{
    for (MirrorView * i : scene_->selectedItems())
    {
        if (event->key() == Qt::Key_Left)
        {
            i->set_rotation(i->rotation() - 1);
            break;
        }
        else if(event->key() == Qt::Key_Right)
        {
            i->set_rotation(i->rotation() + 1);
            break;
        }
    }
}
