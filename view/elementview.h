#ifndef ELEMENTVIEW_H
#define ELEMENTVIEW_H

#include <QFrame>
#include <QGraphicsItem>


/**
 * Cette classe sert de super-classe
 * à tous les éléments visuels avec lesquels
 * un rayon peut interagir.
 * Il s'agit plus d'une classe "TAG"
 * pour retrouver le type d'un élément visuel.
 * @see model/element.h pour son équivalent modèle.
 */
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

    virtual void rotate(double r);
    virtual void translate(double x, double y);

private:
    TypeView type_;
};

/* Fonctions inlines */

const ElementView::TypeView& ElementView::type_view() const
{
    return this->type_;
}






#endif // ELEMENTVIEW_H
