#ifndef MAPREADER_H
#define MAPREADER_H

#include <fstream>
#include <string>
#include <sstream>

#include "model/level.h"


class MapReader
{

private:

    static Level *l;

    static void read_file(std::string);
    static void read_source(std::string);
    static void read_wall(std::string);
    static void read_destination(std::string);
    static void read_nuke(std::string);
    static void read_crystal(std::string);
    static void read_mirror(std::string);
    static void read_lens(std::string);
    static void read_size(std::string);


public:
    static Level * level(std::string);
    static void end_level();
};

#endif // MAPREADER_H
