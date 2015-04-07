#include "view/mirrorview.h"
#include "model/geometry.h"
#include "model/umath.h"

MirrorView::MirrorView(const Mirror& mirror) : rotation_{Geometry::rad_to_deg(mirror.angle())}
{
    mirror_ = &mirror;
    mirror_->add_observer(this);

    setFlags(flags() | QGraphicsItem::ItemIsSelectable);

    LineSegment seg = mirror_->to_line_segment();
    double gx = seg.start().x();
    double gy = seg.start().y();
    double dx = seg.end().x();
    double dy = seg.end().y();

    QPen myPen(Qt::red);
    myPen.setWidth(3);
    setPen(myPen);

    setLine(gx, gy, dx, dy);
}

void MirrorView::translate(int x, int y)
{
    mirror_->translate(x, y);
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
    notify(obs, "");
}

void MirrorView::notify(Observable* obs, std::string msg)
{
    LineSegment seg = mirror_->to_line_segment();
    double gx = seg.start().x();
    double gy = seg.start().y();
    double dx = seg.end().x();
    double dy = seg.end().y();
    setLine(gx, gy, dx, dy);
}
