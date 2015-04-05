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


MapView::MapView(Level* level) : level_{level}
{
    scene_ = new QGraphicsScene(0, 0, this->level_->width(), this->level_->height());

    setScene(scene_);
    setRenderHints(QPainter::Antialiasing);
    setFixedSize(this->level_->width() + 30, this->level_->height() + 30);

    SourceView *source = new SourceView(level_->source());
    DestinationView *dest = new DestinationView(level_->dest());

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
}

void MapView::draw_ray(QGraphicsScene* s, const Ray &ray)
{
    RayView *rv = new RayView(ray);
    rays_.push_back(rv);
    s->addItem(rv);
}

void MapView::draw_wall(QGraphicsScene *s, const Wall& wall)
{
    WallView *wv = new WallView(wall);

    s->addItem(wv);
}


void MapView::draw_mirror(QGraphicsScene *s, const Mirror& mirror)
{
    MirrorView *mv = new MirrorView(mirror);

    s->addItem(mv);
}


void MapView::draw_nuke(QGraphicsScene *s, const Nuke& nuke)
{
    NukeView *nv = new NukeView(nuke);

    s->addItem(nv);
}

void MapView::draw_lens(QGraphicsScene *s, const Lens& lens)
{
    LensView *lv = new LensView(lens);

    s->addItem(lv);
}

void MapView::draw_crystal(QGraphicsScene *s, const Crystal& crystal)
{
    CrystalView *cv = new CrystalView(crystal);

    s->addItem(cv);
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

void MapView::notify(Observable *sdo)
{
    for (auto i : rays_)
    {
        scene_->removeItem(i);
        delete i;
    }



    rays_.clear();

    for (auto &i : this->level_->rays())
    {
        draw_ray(scene_, i);
    }
}


