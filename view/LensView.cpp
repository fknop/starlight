#include "LensView.h"

LensView::LensView(const Lens& lens) : lens{lens}
{
    setRect(lens.getPosition().getX(), lens.getPosition().getY(), lens.getWidth(), lens.getHeight());
}
