#ifndef MAPREADER_H
#define MAPREADER_H

#include "metier_abs/level.h"
#include <string>
#include <sstream>
#include <fstream>


class MapReader
{


Level *level;
std::vector<Wall> walls;
std::vector<Mirror> mirrors;
std::vector<Crystal> crystals;
std::vector<Lens> lenses;
std::vector<Ray> rays;
std::vector<Nuke> nukes;


private:
    void readFile(std::string);
    void readSourceInfo(std::string);
    void readWallInfo(std::string);
    void readDestinationInfo(std::string);
    void readNukeInfo(std::string);
    void readCrystalInfo(std::string);
    void readMirrorInfo(std::string);
    void readLensInfo(std::string);
    void readSizesInfo(std::string);
    void assignVectors();


public:
    MapReader(std::string);



};

#endif // MAPREADER_H
