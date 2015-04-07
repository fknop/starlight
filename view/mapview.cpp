#include <QGraphicsScene>

#include <QMediaPlayer>

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
    //setFixedSize(this->level_->width() + 30, this->level_->height() + 30);

    sound_ = new QMediaPlayer();

    SourceView *source = new SourceView(level_->source());
    DestinationView *dest = new DestinationView(level_->dest());

    scene_->addItem(source);
    scene_->addItem(dest);

    for (auto &i : this->level_->walls())
    {
        draw_wall(scene_, i);
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

    for (auto &i : this->level_->mirrors())
    {
        draw_mirror(scene_, i);
    }

}

MapView::~MapView()
{
    delete level_;
    level_ = nullptr;
    delete scene_;
    scene_ = nullptr;
    delete sound_;
    sound_ = nullptr;
}

void MapView::draw_ray(QGraphicsScene* s, const Ray &ray)
{
    RayView* rv = new RayView(ray);
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
            if (event->modifiers() & Qt::ShiftModifier)
                i->rotate(-5);
            else
                i->rotate(-1);
            break;
        }
        else if(event->key() == Qt::Key_Right)
        {
            if (event->modifiers() & Qt::ShiftModifier)
                i->rotate(5);
            else
                i->rotate(1);
            break;
        }
        else if(event->key() == Qt::Key_Z)
        {
            if (event->modifiers() & Qt::ShiftModifier)
                i->translate(0, -5);
            else
                i->translate(0, -1);
        }
        else if(event->key() == Qt::Key_S || event->key() == Qt::Key_U)
        {
            if (event->modifiers() & Qt::ShiftModifier)
                i->translate(0, 5);
            else
                i->translate(0, 1);
        }
        else if(event->key() == Qt::Key_Q || event->key() == Qt::Key_A)
        {
            if (event->modifiers() & Qt::ShiftModifier)
                i->translate(-5, 0);
            else
                i->translate(-1, 0);
        }
        else if(event->key() == Qt::Key_D || event->key() == Qt::Key_I)
        {
            if (event->modifiers() & Qt::ShiftModifier)
                i->translate(5, 0);
            else
                i->translate(1, 0);
        }
    }
}

void MapView::notify(Observable *sdo, std::string msg)
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


    if (msg == "GAME_LOST")
    {
        sound_->setMedia(QUrl("qrc:/sounds/nuke.mp3"));
        sound_->play();
        // http://soundbible.com/106-Car-Explosion.html  Uploaded: 05.03.09 | License: Attribution 3.0 | Recorded by Mike Koenig |
    }
    else if (msg == "GAME_WON")
    {
        sound_->setMedia(QUrl("qrc:/sounds/victory.mp3"));
        sound_->play();
        // http://soundbible.com/1003-Ta-Da.html Uploaded: 09.14.09 | License: Attribution 3.0 | Recorded by Mike Koenig
    }
    // TO REMOVE
    else
    {
        //QMediaPlayer * sound = new QMediaPlayer();
        sound_->setMedia(QUrl("qrc:/sounds/nuke.mp3"));
        sound_->play();
    }

}

