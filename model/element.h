#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
public:
    enum class Type
    {
        WALL,
        MIRROR,
        CRYSTAL,
        NUKE,
        LENS,
        DEST
    };

    Element(Element::Type);
    virtual ~Element();



    Type getType();

private:
    Type type;


};

#endif // ELEMENT_H
