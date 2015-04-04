#include "model/source.h"
#include "sourceview.h"


SourceView::SourceView(const Source& source) : source_{source}, active{false}
{
    QRectF rect(source.position().x(), source.position().y(), source.edge(), source.edge());

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

    //source_.set_on(active);
}

void SourceView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}
