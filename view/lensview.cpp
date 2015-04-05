#include "lensview.h"


LensView::LensView(const Lens & lens) : lens_{lens}
{
    setRect(lens_.position().x(), lens_.position().y(),
            lens_.width(), lens_.height());
}
