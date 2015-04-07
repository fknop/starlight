#ifndef LENSVIEW_H
#define LENSVIEW_H

#include <QGraphicsEllipseItem>

#include "model/lens.h"

class LensView : public QGraphicsEllipseItem
{
public:
    LensView(const Lens& lens);

private:
    const Lens* lens_;
};

#endif // LENSVIEW_H
