#include "view/mirrorview.h"
#include "model/geometry.h"
#include "model/umath.h"

MirrorView::MirrorView(const Mirror& mirror) : rotation_{Geometry::rad_to_deg(mirror.angle())}
{
    mirror_ = &mirror;
    mirror_->add_observer(this);

    setFlags(flags() | QGraphicsItem::ItemIsSelectable);

    //LineSegment seg = mirror_->to_line_segment();
    double pivotX = mirror_->pivot().x();
    double pivotY = mirror_->pivot().y();
    double len = mirror_->length();
    double xpad = mirror_->x_pad();
    double gx = pivotX - (xpad * cos(0));
    double dx = pivotX + ((len-xpad) * cos(0));


    QPen myPen(Qt::red);
    myPen.setWidth(3);
    setPen(myPen);

    setLine(gx, pivotY, dx, pivotY);
    setTransformOriginPoint(QPointF(mirror_->pivot().x(), mirror_->pivot().y()));
    QGraphicsLineItem::setRotation(rotation_);


}

void MirrorView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    init_pos_ = QPointF(mirror_->pivot().x(), mirror_->pivot().y());
    //QGraphicsItem::mousePressEvent(event);
}

void MirrorView::translate(int x, int y)
{
    mirror_->translate(x, y);
}

void MirrorView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    double x = event->pos().x()- init_pos_.x();
//    double y = event->pos().y()- init_pos_.y();

   // init_pos_ = QPointF(mirror_->pivot().x(), mirror_->pivot().y());

    std::cout << "pos " << pos().x() << " " << pos().y() << std::endl;

    if      (event->pos().x() < init_pos_.x() && event->pos().y() < init_pos_.y())
    {
        mirror_->translate(-1, -1);
     //   setPos(pos().x() - 1, pos().y() - 1);
    }
    else if (event->pos().x() > init_pos_.x() && event->pos().y() > init_pos_.y())
    {
        mirror_->translate(1, 1);
       // setPos(pos().x() + 1, pos().y() + 1);
    }
    else if (event->pos().x() < init_pos_.x() && event->pos().y() > init_pos_.y())
    {
        mirror_->translate(-1, 1);
        //setPos(pos().x() - 1, pos().y() + 1);
    }
    else if (event->pos().x() > init_pos_.x() && event->pos().y() < init_pos_.y())
    {
        mirror_->translate(1,-1);
        //setPos(pos().x() + 1, pos().y() - 1);
    }
}

int MirrorView::rotation()
{
    return rotation_;
}

void MirrorView::set_rotation(qreal angle)
{
    rotation_ += angle;
    mirror_->rotate(Geometry::deg_to_rad(angle));
}

void MirrorView::notify(Observable *obs)
{
    double x = mirror_->pivot().x() - init_pos_.x();
    double y = mirror_->pivot().y() - init_pos_.y();
    init_pos_.setX(mirror_->pivot().x());
    init_pos_.setY(mirror_->pivot().y());
    moveBy(x,y);
    QGraphicsLineItem::setRotation(Geometry::rad_to_deg(mirror_->angle()));
}

void MirrorView::notify(Observable* obs, std::string msg)
{
    double x = mirror_->pivot().x() - init_pos_.x();
    double y = mirror_->pivot().y() - init_pos_.y();
    init_pos_.setX(mirror_->pivot().x());
    init_pos_.setY(mirror_->pivot().y());
    moveBy(x,y);
    QGraphicsLineItem::setRotation(Geometry::rad_to_deg(mirror_->angle()));
}
