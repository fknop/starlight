#ifndef LENSVIEW_H
#define LENSVIEW_H

#include <QGraphicsEllipseItem>

#include "model/lens.h"
#include "view/elementview.h"

class LensView : public QGraphicsEllipseItem, public ElementView
{
public:
    LensView(const Lens& lens);
    Lens * lens();

private:
    const Lens* lens_;
};

#endif // LENSVIEW_H
