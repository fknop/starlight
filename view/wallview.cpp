#include "view/wallview.h"


WallView::WallView(const Wall& wall, bool selectable)  :
    ElementView(ElementView::TypeView::WALLVIEW), selectable_{selectable}
{
    QPen myPen(Qt::black);
    myPen.setWidth(2);

    setPen(myPen);
    setLine(wall.start().x(), wall.start().y(),
            wall.end().x(), wall.end().y());

    this->wall_ = &(const_cast<Wall&>(wall));

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void WallView::translate(double x, double y)
{

}

void WallView::rotate(double angle)
{

}

void WallView::notify(Observable* obs, std::string msg, const std::vector<std::string> &args)
{
    LineSegment seg = wall_->to_line_segment();
    setLine(seg.start().x(), seg.start().y(),
            seg.end().x(), seg.end().y());
}
