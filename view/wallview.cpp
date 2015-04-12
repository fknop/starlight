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


Wall * WallView::wall()
{
    return wall_;
}
