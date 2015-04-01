#include "MapReader.h"
#include <vector>

Level * MapReader::l = nullptr;

void MapReader::readFile(std::string path)
{
    std::fstream level(path, std::ios::in);

    if (level)
    {
        std::string line;

        while(getline(level, line))
        {
            switch (line.at(0))
            {
            case 'S': // Source
                readSourceInfo(line);
                break;

            case 'D': // Destination
                readDestinationInfo(line);
                break;

            case 'C': // Crystal
                readCrystalInfo(line);
                break;

            case 'L': // Lens
                readLensInfo(line);
                break;

            case 'W': // Wall
                readWallInfo(line);
                break;

            case 'N': // Nuke
                readNukeInfo(line);
                break;

            case 'M': // Mirror
                readMirrorInfo(line);
                break;

            default: // Width + Height
                readSizesInfo(line);
                break;
            }
        }
    }


}


void MapReader::readSizesInfo(std::string line)
{
    std::istringstream iss(line);
    double width  = (iss >> width, width);
    double height = (iss >> height, height);

    l = new Level(width, height);
}

void MapReader::readCrystalInfo(std::string line)
{

    std::istringstream iss(line);
    iss.ignore();
    double x    = (iss >> x, x);
    double y    = (iss >> y, y);
    double rad  = (iss >> rad, rad);
    int mod     = (iss >> mod, mod);

    l->add_crystal(Crystal(Point(x,y), rad, mod));
}

void MapReader::readDestinationInfo(std::string line)
{

    std::istringstream iss(line);
    iss.ignore();
    double x     = (iss >> x, x);
    double y     = (iss >> y, y);
    double edge  = (iss >> edge, edge);

    l->set_dest(Dest(Point(x, y), edge));
}

void MapReader::readLensInfo(std::string line)
{

    std::istringstream iss(line);
    iss.ignore();
    double x       = (iss >> x, x);
    double y       = (iss >> y, y);
    double width   = (iss >> width, width);
    double height  = (iss >> height, height);
    int wlmin      = (iss >> wlmin, wlmin);
    int wlmax      = (iss >> wlmax, wlmax);

    l->add_lens(Lens(Point(x,y), width, height, wlmin, wlmax));
}

void MapReader::readMirrorInfo(std::string line)
{
    std::istringstream iss(line);
    iss.ignore();
    double x        = (iss >> x, x);
    double y        = (iss >> y, y);
    double xPad     = (iss >> xPad, xPad);
    double length   = (iss >> length, length);
    double alpha    = (iss >> alpha, alpha);
    double xMin     = (iss >> xMin, xMin);
    double yMin     = (iss >> yMin, yMin);
    double xMax     = (iss >> xMax, xMax);
    double yMax     = (iss >> yMax, yMax);
    double alphaMin = (iss >> alphaMin, alphaMin);
    double alphaMax = (iss >> alphaMax, alphaMax);

    l->add_mirror(Mirror(Point(x,y), xPad, length, alpha,
                  Point(xMin, yMin), Point(xMax, yMax),
                  alphaMin, alphaMax));
}

void MapReader::readNukeInfo(std::string line)
{
    std::istringstream iss(line);
    iss.ignore();
    double x    = (iss >> x, x);
    double y    = (iss >> y, y);
    double rad  = (iss >> rad, rad);

    l->add_nuke(Nuke(Point(x, y), rad));
}

void MapReader::readSourceInfo(std::string line)
{

    std::istringstream iss(line);
    iss.ignore();
    double x     = (iss >> x, x);
    double y     = (iss >> y, y);
    double edge  = (iss >> edge, edge);
    double alpha = (iss >> alpha, alpha);
    int wl       = (iss >> wl, wl);

    l->set_source(Source(Point(x,y), edge, alpha, wl));
}

void MapReader::readWallInfo(std::string line)
{
    std::istringstream iss(line);
    iss.ignore();
    int x1 = (iss >> x1, x1);
    int y1 = (iss >> y1, y1);
    int x2 = (iss >> x2, x2);
    int y2 = (iss >> y2, y2);

    l->add_wall(Wall(Point(x1,y1), Point(x2, y2)));
}

Level * MapReader::getLevel(std::string path)
{

    if (l == nullptr)
        readFile(path);

    return l;
}

void MapReader::endLevel()
{
    delete l;
    l = nullptr;
}
