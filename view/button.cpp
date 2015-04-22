#include <QBrush>
#include <QFont>
#include <QGraphicsTextItem>

#include "view/button.h"


Button::Button(QString name, QGraphicsItem *parent)
{
    setRect(0,0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);

    this->name = new QGraphicsTextItem(name, this);
    int x = rect().width() / 2 - this->name->boundingRect().width() /2;
    int y = rect().height() / 2 - this->name->boundingRect().height() /2;
    this->name->setPos(x, y);
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}
