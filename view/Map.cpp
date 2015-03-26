#include <QGraphicsScene>
#include "view/Map.hpp"
#include "view/Mirror.hpp"

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

        drawSegment(scene, x1, y1, x2, y2);
    }

}

void GraphicsView::drawSegment(QGraphicsScene *s, int x1, int y1, int x2, int y2)
{
    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
    GraphicsLineItem *item1 = new GraphicsLineItem();
    item1->setLine(x1, y1, x2, y2);
    s->addItem(item1);
}





