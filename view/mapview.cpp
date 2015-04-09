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
    sound_ = new QMediaPlayer(nullptr);

    setScene(scene_);
    setRenderHints(QPainter::Antialiasing);
    //setFixedSize(this->level_->width() + 30, this->level_->height() + 30);


    repaint();
}

void MapView::repaint()
{
    draw_source();
    draw_dest();
    draw_walls();
    draw_nukes();
    draw_lenses();
    draw_crystals();
    draw_mirrors();
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

void MapView::draw_walls()
{
    if (wall_views_.size() > 0)
    {
        for (auto &i : wall_views_)
            scene_->removeItem(i);

        wall_views_.clear();
    }

    for (auto &i : level_->walls())
        draw_wall(i);
}

void MapView::draw_mirrors()
{
    if (mirror_views_.size() > 0)
    {
        for (auto &i : mirror_views_)
            scene_->removeItem(i);

        mirror_views_.clear();
    }

    for (auto &i : level_->mirrors())
        draw_mirror(i);
}

void MapView::draw_nukes()
{
    if (nuke_views_.size() > 0)
    {
        for (auto &i : nuke_views_)
            scene_->removeItem(i);

        nuke_views_.clear();
    }
    for (auto &i : level_->nukes())
        draw_nuke(i);
}

void MapView::draw_lenses()
{
    if (lens_views_.size() > 0)
    {
        for (auto &i : lens_views_)
            scene_->removeItem(i);

        lens_views_.clear();
    }

    for (auto &i : level_->lenses())
        draw_lens(i);
}

void MapView::draw_crystals()
{
    if (crystal_views_.size() > 0)
    {
        for (auto &i : crystal_views_)
            scene_->removeItem(i);

        crystal_views_.clear();
    }

    for (auto &i : level_->crystals())
        draw_crystal(i);
}

void MapView::draw_rays()
{
    if (ray_views_.size() > 0)
    {
        for (auto &i : ray_views_)
        {
            scene_->removeItem(i);
            delete i;
        }
        ray_views_.clear();
    }

    for (auto &i : level_->rays())
        draw_ray(i);
}

void MapView::draw_source()
{
    if (source_view_ != nullptr)
         scene_->removeItem(source_view_);

    source_view_ = new SourceView(level_->source());
    scene_->addItem(source_view_);
}

void MapView::draw_dest()
{
    if (dest_view_ != nullptr)
        scene_->removeItem(dest_view_);

    dest_view_ = new DestinationView(level_->dest());
    scene_->addItem(dest_view_);
}

void MapView::draw_ray(const Ray &ray)
{
    RayView* rv = new RayView(ray);
    ray_views_.push_back(rv);
    scene_->addItem(rv);
}

void MapView::draw_wall(const Wall& wall)
{
    WallView* wv = new WallView(wall);
    wall_views_.push_back(wv);
    scene_->addItem(wv);
}


void MapView::draw_mirror(const Mirror& mirror)
{
    MirrorView* mv = new MirrorView(mirror);
    mirror_views_.push_back(mv);
    scene_->addItem(mv);
}


void MapView::draw_nuke(const Nuke& nuke)
{
    NukeView* nv = new NukeView(nuke);
    nuke_views_.push_back(nv);
    scene_->addItem(nv);
}

void MapView::draw_lens(const Lens& lens)
{
    LensView* lv = new LensView(lens);
    lens_views_.push_back(lv);
    scene_->addItem(lv);
}

void MapView::draw_crystal(const Crystal& crystal)
{
    CrystalView* cv = new CrystalView(crystal);
    crystal_views_.push_back(cv);
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
    draw_rays();

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

