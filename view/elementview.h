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

    /**
     * Effectue une rotation d’un objet à l’aide d’un angle en radians.
     * @param r angle en radian dont il faut faire pivoter l’objet.
     */
    virtual void rotate(const double r);
    /**
     * Effectue une translation de l’objet sur l’axe des abscisses et des ordonnées.
     * @param x la translation sur l’axe des abscisses.
     * @param y la translation sur l’axe des ordonnées.
     */
    virtual void translate(const double x, const double y);

private:
    TypeView type_;
};

/* Fonctions inlines */

const ElementView::TypeView& ElementView::type_view() const
{
    return this->type_;
}






#endif // ELEMENTVIEW_H
