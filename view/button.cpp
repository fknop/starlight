#include <QBrush>
#include <QFont>
#include <QGraphicsTextItem>

#include "view/button.h"


Button::Button(const QString& name, QGraphicsItem *parent)
{
    setRect(0,0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);

    name_ = new QGraphicsTextItem(name, this);
    int x = rect().width() / 2 - this->name_->boundingRect().width() /2;
    int y = rect().height() / 2 - this->name_->boundingRect().height() /2;
    name_->setPos(x, y);
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
