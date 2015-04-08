#ifndef MAPWRITER_H
#define MAPWRITER_H


#include "model/level.h"
#include <string>

class MapWriter
{
public:
    MapWriter();
    ~MapWriter();

    static void write(const Level* level, std::string filename);
};

#endif // MAPWRITER_H
