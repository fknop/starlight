#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
public:
    Element();
    virtual ~Element();

    enum class Type
    {
        WALL,
        MIRROR,
        CRYSTAL,
        NUKE,
        LENS,
        DEST
    };

    Type getType();

private:

    bool isMirror();
    bool isCrystal();
    bool isLens();
    bool isDest();
    bool isNuke();
    bool isWall();

};

#endif // ELEMENT_H
