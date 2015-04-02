#include <QGraphicsScene>
#include <iostream>

#include "view/CrystalView.h"
#include "view/DestinationView.h"
#include "view/LensView.h"
#include "view/MapView.h"
#include "view/MirrorView.h"
#include "view/NukeView.h"
#include "view/SourceView.h"
#include "view/WallView.h"



MapView::MapView(Level *level) : level{level}
{
    scene = new QGraphicsScene(0,0,this->level->width(), this->level->height());

    setScene(scene);

    setRenderHints(QPainter::Antialiasing);

    setFixedSize(this->level->width() + 30, this->level->height() + 30);

    Source s = level->source();
    Dest d = level->dest();

    SourceView *source = new SourceView(s.getPosition().x(), s.getPosition().y(), s.getEdge(), s.getEdge());
    DestinationView *dest = new DestinationView(d.getPosition().x(), d.getPosition().y(), d.getEdge(), d.getEdge());

    scene->addItem(source);
    scene->addItem(dest);


    for (auto &i : this->level->walls())
    {
        drawWall(scene, i);
    }

    for (auto &i : this->level->mirrors())
    {
        drawMirror(scene, i);
    }

    for (auto &i : this->level->nukes())
    {
        drawNuke(scene, i);
    }

    for (auto &i : this->level->lenses())
    {
        drawLens(scene, i);
    }

    for (auto &i : this->level->crystals())
    {
        drawCrystal(scene, i);
    }

}

void MapView::drawWall(QGraphicsScene *s, const Wall& wall)
{
    WallView *item1 = new WallView(wall);

    s->addItem(item1);
}


void MapView::drawMirror(QGraphicsScene *s, const Mirror& mirror)
{
    MirrorView *item1 = new MirrorView(mirror);

    s->addItem(item1);
}


void MapView::drawNuke(QGraphicsScene *s, const Nuke& nuke)
{
    NukeView *item1 = new NukeView(nuke);

    s->addItem(item1);
}

void MapView::drawLens(QGraphicsScene *s, const Lens& lens)
{
    LensView *item1 = new LensView(lens);

    s->addItem(item1);
}

void MapView::drawCrystal(QGraphicsScene *s, const Crystal& crystal)
{
    CrystalView *item1 = new CrystalView(crystal);

    s->addItem(item1);
}


void MapView::keyPressEvent(QKeyEvent *event)
{
    for (MirrorView * i : scene->selectedItems())
    {
        if (event->key() == Qt::Key_Left)
        {
            i->setRotation(i->getRotation() - 1);
            break;
        }
        else if(event->key() == Qt::Key_Right)
        {
            i->setRotation(i->getRotation() + 1);
            break;
        }
    }
}
