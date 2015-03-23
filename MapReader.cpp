#include "MapReader.h"
#include <vector>

//MapReader::MapReader(std::string path)
//{
//    readFile(path);
//    assignVectors();
//}

void MapReader::readFile(std::string path, Level *l)
{
    std::cout << "readFile0" << std::endl;
    std::fstream level(path, std::ios::in);
    std::cout << "readFile1" << std::endl;

    if (level)
    {
        std::cout << "readFile2" << std::endl;
        std::string line;

        while(getline(level, line))
        {
            std::cout << "readFileWhile" << std::endl;

            switch (line.at(0))
            {
            // Source
            case 'S':
                std::cout << "source0" << std::endl;
                std::cout << l->getHeight() << std::endl;
                std::cout << "source1" << std::endl;
                readSourceInfo(line, l);
                break;
                // Destination
            case 'D':
                readDestinationInfo(line, l);
                break;
                // Crystal
            case 'C':
                readCrystalInfo(line, l);
                break;
                // Lens
            case 'L':
                readLensInfo(line, l);
                break;
                // Wall
            case 'W':
                readWallInfo(line, l);
                break;
                // Nuke
            case 'N':
                readNukeInfo(line, l);
                break;
                // Mirror
            case 'M':
                readMirrorInfo(line, l);
                break;
                // First line, width + height
            default:
                readSizesInfo(line, l);
                std::cout << "default " << l->getHeight() << std::endl;
                break;
            }
        }
    }
}


void MapReader::readSizesInfo(std::string line, Level *l)
{
    int width;
    int height;

    std::istringstream iss(line);

    iss >> width;
    iss >> height;

    l = new Level(width, height);
    std::cout << l->getHeight() << std::endl;
}

void MapReader::readCrystalInfo(std::string line, Level *l)
{
    int x;
    int y;
    int rad;
    int mod;

    std::istringstream iss(line);

    iss.ignore();

    iss >> x;
    iss >> y;
    iss >> rad;
    iss >> mod;

    //crystals.push_back(Crystal(Point(x,y), rad, mod));
    l->addCrystal(Crystal(Point(x,y), rad, mod));
}

void MapReader::readDestinationInfo(std::string line, Level *l)
{
    int x;
    int y;
    int edge;

    std::istringstream iss(line);

    iss.ignore();

    iss >> x;
    iss >> y;
    iss >> edge;

    //level->setDestination(Dest(Point(x, y), edge));
    l->setDestination(Dest(Point(x, y), edge));
}

void MapReader::readLensInfo(std::string line, Level *l)
{
    int x;
    int y;
    int width;
    int height;
    int wlmin;
    int wlmax;

    std::istringstream iss(line);

    iss.ignore();

    iss >> x;
    iss >> y;
    iss >> width;
    iss >> height;
    iss >> wlmin;
    iss >> wlmax;

    //lenses.push_back((Lens(Point(x,y), width, height, wlmin, wlmax)));
    l->addLens(Lens(Point(x,y), width, height, wlmin, wlmax));
}

void MapReader::readMirrorInfo(std::string line, Level *l)
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

    iss.ignore();

    iss >> x;
    iss >> y;
    iss >> xpad;
    iss >> length;
    iss >> alpha;
    iss >> xmin;
    iss >> ymin;
    iss >> xmax;
    iss >> ymax;
    iss >> alphamin;
    iss >> alphamax;

//    mirrors.push_back(Mirror(Point(x,y), length, xpad, alpha,
//                             Point(xmin, ymin), Point(xmax, ymax),
//                             alphamin, alphamax));
    l->addMirror(Mirror(Point(x,y), length, xpad, alpha,
                  Point(xmin, ymin), Point(xmax, ymax),
                  alphamin, alphamax));
}

void MapReader::readNukeInfo(std::string line, Level *l)
{
    int x;
    int y;
    int rad;

    std::istringstream iss(line);

    iss.ignore();

    iss >> x;
    iss >> y;
    iss >> rad;

    // nukes.push_back(Nuke(Point(x, y), rad));
    l->addNuke(Nuke(Point(x, y), rad));
}

void MapReader::readSourceInfo(std::string line, Level *l)
{
    int x;
    int y;
    int edge;
    double alpha;
    int wavelength;

    std::istringstream iss(line);

    iss.ignore();

    iss >> x;
    iss >> y;
    iss >> edge;
    iss >> alpha;
    iss >> wavelength;

    //level->setSource(Source(Point(x,y), edge, alpha, wavelength));
    l->setSource(Source(Point(x,y), edge, alpha, wavelength));
}

void MapReader::readWallInfo(std::string line, Level *l)
{
    int x1;
    int y1;
    int x2;
    int y2;

    std::istringstream iss(line);

    iss.ignore();

    iss >> x1;
    iss >> y1;
    iss >> x2;
    iss >> y2;

    //walls.push_back(Wall(Point(x1,y1), Point(x2, y2)));
    l->addWall(Wall(Point(x1,y1), Point(x2, y2)));
}

//void MapReader::assignVectors(Level *l)
//{
//    l->setCrystals(crystals);
//    l->setMirrors(mirrors);
//    l->setLenses(lenses);
//    l->setNukes(nukes);
//    l->setWalls(walls);
//}

Level * MapReader::getLevel(std::string path)
{
    Level *l = nullptr;

    readFile(path, l);

    return l;
}
