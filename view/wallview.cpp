#include "utils/uview.h"

#include "view/wallview.h"

WallView::WallView(const Wall& wall, bool selectable)  :
    ElementView(ElementView::TypeView::WALLVIEW), selectable_{selectable}
{
    wall_ = &(const_cast<Wall&>(wall));
    wall_->add_observer(this);

    QPen myPen(Qt::black);
    myPen.setWidth(3);
    setPen(myPen);
    uview::display_line(this, wall_->to_line_segment());
    setFlag(QGraphicsItem::ItemIsSelectable, selectable_);
}

void WallView::translate(const double x, const double y)
{
    wall_->translate(x, y);
}

void WallView::rotate(const double angle)
{
    wall_->rotate(umath::deg_to_rad(angle));
}

void WallView::notify(Observable * o,
                      const std::string& msg,
                      const std::vector<std::string>& args)
{
    if (msg.compare("ROTATE_WALL") == 0 || msg.compare("TRANSLATE_WALL") == 0)
        uview::display_line(this, wall_->to_line_segment());
}
