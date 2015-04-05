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

    //setTransformOriginPoint(QPointF(mirror_->pivot().x(), mirror_->pivot().y()));

    QPen myPen(Qt::red);
    myPen.setWidth(3);
    setPen(myPen);
    setLine(gx, gy, dx, dy);

}

void MirrorView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    init_pos_ = event->pos();
    QGraphicsItem::mousePressEvent(event);
}

void MirrorView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   // std::cout << "event scenepos x : " << event->scenePos().x() << std::endl;
    //std::cout << "event scenepos y : " << event->scenePos().y() << std::endl;
    double x = event->pos().x() - init_pos_.x();
    double y = event->pos().y() - init_pos_.y();
    std::cout << x << "      " << y;
    mirror_->translate(0, 0);

    //std::cout << "(" << pos().x() << " , " << pos.y() << ")" << std::endl;
   // std::cout << "(" << this->pos().x() << " , " << this->pos().y() << ")" << std::endl;
    //mirror_.set_pivot(Point(event->pos().x() - init_pos_.x(), event->pos().y() - init_pos_.y()));

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
    LineSegment seg = mirror_->to_line_segment();
    double gx = seg.start().x();
    double gy = seg.start().y();
    double dx = seg.end().x();
    double dy = seg.end().y();
    setLine(gx, gy, dx, dy);

}
