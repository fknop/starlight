#include "sourceview.h"


SourceView::SourceView(int posX, int posY, int width, int height) : active{false}
{
    QRectF rect(posX, posY, width, height);

    setRect(rect);
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //QRectF rect(posX, posY, width, height);
    if (!active)
    {
        setBrush(QBrush(Qt::yellow));
        setPen(QPen(Qt::yellow));
        active = true;
    }
    else
    {
        setBrush(QBrush(Qt::white));
        setPen(QPen(Qt::black));
        active = false;
    }
}

void SourceView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}