#include "MapReader.h"

MapReader::MapReader(std::string path)
{
    readFile(path);
    assignVectors();
}

void MapReader::readFile(std::string)
{

    std::fstream level("levels/level1.map", std::ios::in);

    if (level) {

        std::string line;
        while(getline(level, line))
        {


            switch (line.at(0))
            {
                //Source
                case 'S':
                    readSourceInfo(line);
                    break;
                    //Destination
                case 'D':
                    readDestinationInfo(line);
                    break;
                    //Crystal
                case 'C':
                    readCrystalInfo(line);
                    break;
                    //Lens
                case 'L':
                    readLensInfo(line);
                    break;
                    //Wall
                case 'W':
                    readWallInfo(line);
                    break;
                    //Nuke
                case 'N':
                    readNukeInfo(line);
                    break;
                    //Mirror
                case 'M':
                    readMirrorInfo(line);
                    break;
                default:
                    //First line, width + height
                    readSizesInfo(line);
                    break;
                }
        }
    }

}


void MapReader::readSizesInfo(std::string line)
{
    int width;
    int height;
    std::istringstream iss(line);

    iss >> width;
    iss >> height;
    level = new Level(width, height);
}

void MapReader::readCrystalInfo(std::string line)
{

    int x;
    int y;
    int rad;
    int mod;

    std::istringstream iss(line);

    iss >> x;
    iss >> y;
    iss >> rad;
    iss >> mod;


    crystals.push_back(Crystal(Point(x,y), rad, mod));



}

void MapReader::readDestinationInfo(std::string line)
{

    int x;
    int y;
    int edge;

    std::istringstream iss(line);

    iss >> x;
    iss >> y;
    iss >> edge;

    level->setDestination(Dest(Point(x, y), edge));

}

void MapReader::readLensInfo(std::string line)
{


    int x;
    int y;
    int width;
    int height;
    int wlmin;
    int wlmax;

    std::istringstream iss(line);

    iss >> x;
    iss >> y;
    iss >> width;
    iss >> height;
    iss >> wlmin;
    iss >> wlmax;

    lenses.push_back((Lens(Point(x,y), width, height, wlmin, wlmax)));


}

void MapReader::readMirrorInfo(std::string line)
{

    int x;
    int y;
    int length;
    int xpad;
    double alpha;
    int xmin;
    int ymin;
    int xmax;
    int ymax;
    double alphamin;
    double alphamax;

    std::istringstream iss(line);

    iss >> x;
    iss >> y;
    iss >> length;
    iss >> xpad;
    iss >> alpha;
    iss >> xmin;
    iss >> ymin;
    iss >> xmax;
    iss >> ymax;
    iss >> alphamin;
    iss >> alphamax;

    mirrors.push_back(Mirror(Point(x,y), length, xpad, alpha,
                             Point(xmin, ymin), Point(xmax, ymax),
                             alphamin, alphamax));

}

void MapReader::readNukeInfo(std::string line)
{

    int x;
    int y;
    int rad;

    std::istringstream iss(line);

    iss >> x;
    iss >> y;
    iss >> rad;

    nukes.push_back(Nuke(Point(x, y), rad));


}

void MapReader::readSourceInfo(std::string line)
{

    int x;
    int y;
    int edge;
    double alpha;
    int wavelength;

    std::istringstream iss(line);

    iss >> x;
    iss >> y;
    iss >> edge;
    iss >> alpha;
    iss >> wavelength;

    level->setSource(Source(Point(x,y), edge, alpha, wavelength));

}

void MapReader::readWallInfo(std::string line)
{

    int x1;
    int y1;
    int x2;
    int y2;

    std::istringstream iss(line);

    iss >> x1;
    iss >> y1;
    iss >> x2;
    iss >> y2;

    walls.push_back(Wall(Point(x1,y1), Point(x2, y2)));

}

void MapReader::assignVectors()
{
    level->setCrystals(crystals);
    level->setMirrors(mirrors);
    level->setLenses(lenses);
    level->setNukes(nukes);
    level->setWalls(walls);
}
