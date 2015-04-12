#include "view/mirrorview.h"
#include "model/geometry.h"
#include "model/umath.h"

//MirrorView::MirrorView(const Mirror& mirror) : MirrorView(mirror, true) {}

MirrorView::MirrorView(const Mirror &mirror, bool selectable) :
    ElementView(ElementView::TypeView::MIRRORVIEW),
    selectable_{selectable}
{
    mirror_ = &(const_cast<Mirror&>(mirror));
    mirror_->add_observer(this);

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
    QPen myPen(Qt::red);
    myPen.setWidth(3);
    setPen(myPen);

    LineSegment seg = mirror_->to_line_segment();
    setLine(seg.start().x(), seg.start().y(),
            seg.end().x(), seg.end().y());
}

void MirrorView::translate(int x, int y)
{
    mirror_->translate(x, y);
}

void MirrorView::rotate(qreal angle)
{
    mirror_->rotate(Geometry::deg_to_rad(angle));
}

void MirrorView::notify(Observable* obs, std::string msg, const std::vector<std::string> &args)
{
    LineSegment seg = mirror_->to_line_segment();
    setLine(seg.start().x(), seg.start().y(),
            seg.end().x(), seg.end().y());
}

Mirror * MirrorView::mirror()
{
    return mirror_;
}
