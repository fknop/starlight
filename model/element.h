#ifndef ELEMENT_H
#define ELEMENT_H

#include "obs/observable.h"

/**
 * Cette classe sert de super-classe
 * à tous les éléments avec lesquels
 * un rayon peut interagir.
 * Il s'agit plus d'une classe "TAG"
 * pour retrouver le type d'un élément.
 */
class Element : public Observable
{
public:

    /**
     * Énumération fortement typée représentant le type
     * d'un élément.
     */
    enum class Type
    {
        MIRROR,
        CRYSTAL,
        LENS,
        DEST,
        SOURCE,
        NUKE,
        WALL
    };

    Type type_;

    /**
     * Construit un élément avec un type
     * permettant de connaître le type
     * de l'élément à tout moment.
     */
    Element(Element::Type type)
    {
        type_ = type;
    }

    virtual ~Element() {}

    /**
     * Retourne le type de l'élément.
     * @return le type de l'élément.
     */
    inline const Type& type() const;
};

/* Fonctions inlines */

const Element::Type& Element::type() const
{
    return type_;
}

#endif // ELEMENT_H
