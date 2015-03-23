#ifndef MAPREADER_H
#define MAPREADER_H

#include "model/level.h"
#include <string>
#include <sstream>
#include <fstream>


class MapReader
{

private:
    static Level *readFile(std::string, Level *l);
    static void readSourceInfo(std::string, Level *l);
    static void readWallInfo(std::string, Level *l);
    static void readDestinationInfo(std::string, Level *l);
    static void readNukeInfo(std::string, Level *l);
    static void readCrystalInfo(std::string, Level *l);
    static void readMirrorInfo(std::string, Level *l);
    static void readLensInfo(std::string, Level *l);
    static Level *readSizesInfo(std::string);


public:
    static Level * getLevel(std::string);

};

#endif // MAPREADER_H
