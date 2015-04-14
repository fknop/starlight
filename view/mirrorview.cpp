#include "view/mirrorview.h"
#include "model/geometry.h"
#include "model/umath.h"

MirrorView::MirrorView(const Mirror &mirror, bool selectable) :
    ElementView(ElementView::TypeView::MIRRORVIEW),
    selectable_{selectable}
{
    mirror_ = &(const_cast<Mirror&>(mirror));
    mirror_->add_observer(this);

    QPen myPen(Qt::red);
    myPen.setWidth(3);
    setPen(myPen);

    LineSegment seg = mirror_->to_line_segment();
    setLine(seg.start().x(), seg.start().y(),
            seg.end().x(), seg.end().y());

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void MirrorView::translate(double x, double y)
{
    mirror_->translate(x, y);
}

void MirrorView::rotate(double angle)
{
    mirror_->rotate(Geometry::deg_to_rad(angle));
}

void MirrorView::notify(Observable* obs, std::string msg, const std::vector<std::string> &args)
{
    LineSegment seg = mirror_->to_line_segment();
    setLine(seg.start().x(), seg.start().y(),
            seg.end().x(), seg.end().y());
}


