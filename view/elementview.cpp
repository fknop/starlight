#include "view/elementview.h"

ElementView::ElementView(ElementView::TypeView type)
{
    this->type_ = type;
}

ElementView::~ElementView(){}

void ElementView::translate(double x, double y) {}

void ElementView::rotate(double angle) {}
