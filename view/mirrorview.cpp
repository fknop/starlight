#include "view/mirrorview.h"


MirrorView::MirrorView(const Mirror& mirror) : rotation_{0}
{
    mirror_ = &mirror;
    mirror_->add_observer(this);
    setFlags(flags() | QGraphicsItem::ItemIsSelectable);

    LineSegment seg = mirror_->to_line_segment();
    double gx = seg.start().x();
    double gy = seg.start().y();
    double dx = seg.end().x();
    double dy = seg.end().y();

    setTransformOriginPoint(QPointF(mirror_->pivot().x(), mirror_->pivot().y()));

    QPen myPen(Qt::red);
    myPen.setWidth(3);
    setPen(myPen);
    setLine(gx, gy, dx, dy);

}

void MirrorView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    init_pos_ = QPointF(mirror_->pivot().x(), mirror_->pivot().y());
    //QGraphicsItem::mousePressEvent(event);
}

void MirrorView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    double x = event->pos().x()- init_pos_.x();
//    double y = event->pos().y()- init_pos_.y();

    init_pos_ = QPointF(mirror_->pivot().x(), mirror_->pivot().y());

    std::cout << "pos " << pos().x() << " " << pos().y() << std::endl;

    if      (event->pos().x() < init_pos_.x() && event->pos().y() < init_pos_.y())
    {
        mirror_->translate(-1, -1);
        setPos(pos().x() - 1, pos().y() - 1);
    }
    else if (event->pos().x() > init_pos_.x() && event->pos().y() > init_pos_.y())
    {
        mirror_->translate(1, 1);
        setPos(pos().x() + 1, pos().y() + 1);
    }
    else if (event->pos().x() < init_pos_.x() && event->pos().y() > init_pos_.y())
    {
        mirror_->translate(-1, 1);
        setPos(pos().x() - 1, pos().y() + 1);
    }
    else if (event->pos().x() > init_pos_.x() && event->pos().y() < init_pos_.y())
    {
        mirror_->translate(1,-1);
        setPos(pos().x() + 1, pos().y() - 1);
    }
}

int MirrorView::rotation()
{
    return rotation_;
}

void MirrorView::set_rotation(qreal angle)
{
    rotation_ = angle;
    QGraphicsLineItem::setRotation(angle);
    mirror_->set_angle(angle);
}

void MirrorView::notify(Observable *obs)
{

    double x = mirror_->pivot().x() - init_pos_.x();
    double y = mirror_->pivot().y() - init_pos_.y();
    init_pos_.setX(mirror_->pivot().x());
    init_pos_.setY(mirror_->pivot().y());
    moveBy(x,y);


}
