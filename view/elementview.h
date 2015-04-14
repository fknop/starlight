#ifndef ELEMENTVIEW_H
#define ELEMENTVIEW_H

#include <QGraphicsItem>
#include <QFrame>

#include <iostream>

class ElementView : public QFrame
{
public:
    enum class TypeView
    {
        CRYSTALVIEW,
        DESTVIEW,
        LENSVIEW,
        MIRRORVIEW,
        NUKEVIEW,
        SOURCEVIEW,
        WALLVIEW
    };

    /**
     * Construit un élément avec un type
     * permettant de connaître le type
     * de l'élément à tout moment.
     */
    ElementView(ElementView::TypeView);
    virtual ~ElementView();

    /**
     * Retourne le type de l'élément.
     * @return le type de l'élément.
     */
    inline const TypeView& type_view() const;

    inline virtual void rotate(int r);
    inline virtual void translate(int x, int y);


    TypeView type_;
};

/* Fonctions inlines */

const ElementView::TypeView& ElementView::type_view() const
{
    return this->type_;
}

void ElementView::rotate(int r)
{
    std::cout << "rotate" << std::endl;
}


void ElementView::translate(int x, int y)
{
    std::cout << "translate" << std::endl;
}




#endif // ELEMENTVIEW_H
