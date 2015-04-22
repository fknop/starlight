#include "view/elementview.h"

ElementView::ElementView(ElementView::TypeView type)
{
    this->type_ = type;
}

ElementView::~ElementView(){}

void ElementView::translate(const double x, const double y) {}

void ElementView::rotate(const double angle) {}
