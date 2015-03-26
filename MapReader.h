#ifndef MAPREADER_H
#define MAPREADER_H

#include "model/level.h"
#include <string>
#include <sstream>
#include <fstream>


class MapReader
{

private:

    static Level *l;


    static void readFile(std::string);
    static void readSourceInfo(std::string);
    static void readWallInfo(std::string);
    static void readDestinationInfo(std::string);
    static void readNukeInfo(std::string);
    static void readCrystalInfo(std::string);
    static void readMirrorInfo(std::string);
    static void readLensInfo(std::string);
    static void readSizesInfo(std::string);



public:
    static Level * getLevel(std::string);
    static void endLevel();


};

#endif // MAPREADER_H
