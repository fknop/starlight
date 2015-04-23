#include <QBrush>
#include <QFont>
#include <QGraphicsTextItem>

#include "view/button.h"


Button::Button(const QString& name, QGraphicsItem *parent)
{
    setRect(0,0, 200, 50);
    name_ = new QGraphicsTextItem(name, this);

    set_yellow_brush();

    int x = rect().width() / 2 - name_->boundingRect().width() /2;
    int y = rect().height() / 2 - name_->boundingRect().height() /2;
    name_->setPos(x, y);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    set_green_brush();
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    set_yellow_brush();
}

void Button::set_yellow_brush()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}

void Button::set_green_brush()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}
