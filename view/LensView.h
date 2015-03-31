#ifndef LENSVIEW_H
#define LENSVIEW_H

#include <QGraphicsEllipseItem>

#include "model/lens.h"

class LensView : public QGraphicsEllipseItem
{
public:
    LensView(const Lens &lens);

private:
    Lens lens;
};

#endif // LENSVIEW_H
