#include "LensView.h"

LensView::LensView(const Lens& lens) : lens{lens}
{
    setRect(lens.getPosition().x(), lens.getPosition().y(), lens.getWidth(), lens.getHeight());
}
