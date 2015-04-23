#include "utils/uview.h"

#include "view/mirrorview.h"


MirrorView::MirrorView(const Mirror & mirror, bool selectable) :
    ElementView(ElementView::TypeView::MIRRORVIEW),
    selectable_{selectable}
{
    mirror_ = &(const_cast<Mirror &>(mirror));
    mirror_->add_observer(this);
    zone_ = new QGraphicsRectItem(this);

    QPen pen_1(Qt::red);
    pen_1.setWidth(3);
    setPen(pen_1);

    QPen pen_2(Qt::blue);
    pen_2.setWidth(1);
    pen_2.setStyle(Qt::DashLine);
    zone_->setPen(pen_2);

    uview::display_line(this, mirror_->to_line_segment());

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void MirrorView::translate(double x, double y)
{
    mirror_->translate(x, y);
}

void MirrorView::rotate(double angle)
{
    mirror_->rotate(umath::deg_to_rad(angle));
}

void MirrorView::notify(Observable * o, const std::string& msg,
                        const std::vector<std::string>& args)
{
    uview::display_line(this, mirror_->to_line_segment());
}

void MirrorView::set_zone()
{
    const Point& min = mirror_->min_pivot();
    const Point& max = mirror_->max_pivot();

    double w = max.x() - min.x();
    double h = max.y() - min.y();

    uview::display_rectangle(zone_, Rectangle(Point(min.x(), min.y()), w, h));
}


void MirrorView::show_zone()
{
    set_zone();
    zone_->show();
}

void MirrorView::hide_zone()
{
    zone_->hide();
}

