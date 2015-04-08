#include <QGraphicsScene>

#include <QMediaPlayer>
#include <QMessageBox>

#include <iostream>

#include "view/crystalview.h"
#include "view/destinationview.h"
#include "view/lensview.h"
#include "view/mapview.h"
#include "view/mirrorview.h"
#include "view/nukeview.h"
#include "view/rayview.h"
#include "view/sourceview.h"
#include "view/wallview.h"

MapView::MapView()
{
    scene_ = new QGraphicsScene(0, 0, 500, 500);

    setScene(scene_);
}

MapView::MapView(Level* level) : level_{level}
{
    scene_ = new QGraphicsScene(0, 0, this->level_->width(), this->level_->height());

    setScene(scene_);
    setRenderHints(QPainter::Antialiasing);
    //setFixedSize(this->level_->width() + 30, this->level_->height() + 30);

    sound_ = new QMediaPlayer(nullptr);

    draw_source(level->source());
    draw_dest(level->dest());

    for (auto &i : this->level_->walls())
    {
        draw_wall(i);
    }

    for (auto &i : this->level_->nukes())
    {
        draw_nuke(i);
    }

    for (auto &i : this->level_->lenses())
    {
        draw_lens(i);
    }

    for (auto &i : this->level_->crystals())
    {
        draw_crystal(i);
    }

    for (auto &i : this->level_->mirrors())
    {
        draw_mirror(i);
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

void MapView::draw_source(const Source &source)
{
    SourceView * sv = new SourceView(source);

    scene_->addItem(sv);
}

void MapView::draw_dest(const Dest &dest)
{
    DestinationView * dv = new DestinationView(dest);

    scene_->addItem(dv);
}

void MapView::draw_ray(const Ray &ray)
{
    RayView* rv = new RayView(ray);
    rays_.push_back(rv);
    scene_->addItem(rv);
}

void MapView::draw_wall(const Wall& wall)
{
    WallView *wv = new WallView(wall);

    scene_->addItem(wv);
}


void MapView::draw_mirror(const Mirror& mirror)
{
    MirrorView *mv = new MirrorView(mirror);

    scene_->addItem(mv);
}


void MapView::draw_nuke(const Nuke& nuke)
{
    NukeView *nv = new NukeView(nuke);

    scene_->addItem(nv);
}

void MapView::draw_lens(const Lens& lens)
{
    LensView *lv = new LensView(lens);

    scene_->addItem(lv);
}

void MapView::draw_crystal(const Crystal& crystal)
{
    CrystalView *cv = new CrystalView(crystal);

    scene_->addItem(cv);
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
        draw_ray(i);
    }

    std::cout << "mapview msg " << msg << std::endl;


    if (msg == "GAME_LOST")
    {
        if (sound_->state() == QMediaPlayer::PlayingState)
            sound_->stop();

        sound_->setMedia(QUrl("qrc:/sounds/nuke.mp3"));
        sound_->play();
        // http://soundbible.com/106-Car-Explosion.html  Uploaded: 05.03.09 | License: Attribution 3.0 | Recorded by Mike Koenig |

        QMessageBox::information(this, "You lose!", "Outch, looks like you exploded the whole map…");
    }
    else if (msg == "GAME_WON")
    {
        if (sound_->state() == QMediaPlayer::PlayingState)
            sound_->stop();

        sound_->setMedia(QUrl("qrc:/sounds/victory.mp3"));
        sound_->play();
        // http://soundbible.com/1003-Ta-Da.html Uploaded: 09.14.09 | License: Attribution 3.0 | Recorded by Mike Koenig

        QMessageBox::information(this, "WIN!", "Congrats! You made it!");
    }
}

