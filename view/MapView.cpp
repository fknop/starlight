#include <QGraphicsScene>
#include "view/MapView.h"
#include "view/MirrorView.h"
#include "view/WallView.h"

#include <iostream>

GraphicsView::GraphicsView(Level *level) : level{level}
{
    QGraphicsScene *scene = new QGraphicsScene(0,0,this->level->getWidth(), this->level->getHeight());
    setScene(scene);
    setFixedSize(this->level->getWidth(), this->level->getHeight());

    for (auto &i : this->level->getWalls())
    {
        int x1, x2, y1, y2;
        x1 = i.getStart().getX();
        x2 = i.getEnd().getX();
        y1 = i.getStart().getY();
        y2 = i.getEnd().getY();

        drawWall(scene, x1, y1, x2, y2);
    }

    for (auto &i : this->level->getMirrors())
    {
        double angle = i.getAngle();
        int xpad = i.getXPad();
        int pivotX = i.getPivot().getX();
        int pivotY = i.getPivot().getY();
        int len = i.getLength();

        drawMirror(scene, pivotX, pivotY, xpad, len, angle);
    }

}

void GraphicsView::drawWall(QGraphicsScene *s, int x1, int y1, int x2, int y2)
{
    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
    WallView *item1 = new WallView(x1, y1, x2, y2);

    s->addItem(item1);
}


void GraphicsView::drawMirror(QGraphicsScene *s, int pivotX, int pivotY, int xpad, int len, double angle)
{
    //std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
    MirrorView *item1 = new MirrorView(pivotX, pivotY, xpad, len, angle);

    s->addItem(item1);
}




