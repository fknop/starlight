#include "model/umath.h"

#include "view/wallview.h"

WallView::WallView(const Wall& wall, bool selectable)  :
    ElementView(ElementView::TypeView::WALLVIEW), selectable_{selectable}
{
    this->wall_ = &(const_cast<Wall&>(wall));
    this->wall_->add_observer(this);

    QPen myPen(Qt::black);
    myPen.setWidth(2);
    setPen(myPen);
    set_line();
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void WallView::translate(double x, double y)
{
    this->wall_->translate(x, y);
}

void WallView::rotate(double angle)
{
    this->wall_->rotate(umath::deg_to_rad(angle));
}

void WallView::notify(Observable * obs, std::string msg, const std::vector<std::string>& args)
{
    if (msg.compare("ROTATE_WALL") == 0 || msg.compare("TRANSLATE_WALL") == 0)
        set_line();
}

void WallView::set_line()
{
    LineSegment seg = wall_->to_line_segment();
    setLine(seg.start().x(), seg.start().y(),
            seg.end().x(), seg.end().y());
}
