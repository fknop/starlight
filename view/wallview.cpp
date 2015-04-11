#include "view/wallview.h"


WallView::WallView(const Wall& wall)  :
    ElementView(ElementView::TypeView::WALLVIEW)
{
    QPen myPen(Qt::black);
    myPen.setWidth(2);

    setPen(myPen);
    setLine(wall.start().x(), wall.start().y(),
            wall.end().x(), wall.end().y());

    this->wall_ = &(const_cast<Wall&>(wall));
}


Wall * WallView::wall()
{
    return wall_;
}
