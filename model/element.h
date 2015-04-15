#ifndef ELEMENT_H
#define ELEMENT_H

/**
 * Cette classe sert de super-classe
 * à tous les éléments avec lequel
 * un rayon peut interragir.
 * Il s'agit plus d'une classe "TAG"
 * pour retrouver le type d'un élément.
 */
class Element
{
public:
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
    Element(Element::Type);
    virtual ~Element();

    /**
     * Retourne le type de l'élément.
     * @return le type de l'élément.
     */
    inline const Type& type() const;



};

/* Fonctions inlines */

const Element::Type& Element::type() const
{
    return this->type_;
}

#endif // ELEMENT_H
