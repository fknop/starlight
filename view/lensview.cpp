#include "lensview.h"


LensView::LensView(const Lens & lens) : lens_{lens}
{
    setRect(lens.position().x(), lens.position().y(), lens.width(), lens.height());
}
