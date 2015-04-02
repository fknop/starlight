#include <vector>
#include <fstream>
#include <sstream>

#include "mapreader.h"


Level * MapReader::l_ = nullptr;

void MapReader::read_file(std::string path)
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
                read_source(line);
                break;

            case 'D': // Destination
                read_destination(line);
                break;

            case 'C': // Crystal
                read_crystal(line);
                break;

            case 'L': // Lens
                read_lens(line);
                break;

            case 'W': // Wall
                read_wall(line);
                break;

            case 'N': // Nuke
                read_nuke(line);
                break;

            case 'M': // Mirror
                read_mirror(line);
                break;

            default: // Width + Height
                read_size(line);
                break;
            }
        }
    }
}


void MapReader::read_size(std::string line)
{
    std::istringstream iss(line);

    double width  = (iss >> width, width);
    double height = (iss >> height, height);

    l_ = new Level(width, height);
}

void MapReader::read_crystal(std::string line)
{

    std::istringstream iss(line);
    iss.ignore();

    double x    = (iss >> x, x);
    double y    = (iss >> y, y);
    double rad  = (iss >> rad, rad);
    int mod     = (iss >> mod, mod);

    l_->add_crystal(Crystal(Point(x,y), rad, mod));
}

void MapReader::read_destination(std::string line)
{

    std::istringstream iss(line);
    iss.ignore();

    double x     = (iss >> x, x);
    double y     = (iss >> y, y);
    double edge  = (iss >> edge, edge);

    l_->set_dest(Dest(Point(x, y), edge));
}

void MapReader::read_lens(std::string line)
{

    std::istringstream iss(line);
    iss.ignore();

    double x       = (iss >> x, x);
    double y       = (iss >> y, y);
    double width   = (iss >> width, width);
    double height  = (iss >> height, height);
    int wlmin      = (iss >> wlmin, wlmin);
    int wlmax      = (iss >> wlmax, wlmax);

    l_->add_lens(Lens(Point(x, y), width, height, wlmin, wlmax));
}

void MapReader::read_mirror(std::string line)
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

    l_->add_mirror(Mirror(Point(x, y), xPad, length, alpha,
                  Point(xMin, yMin), Point(xMax, yMax),
                  alphaMin, alphaMax));
}

void MapReader::read_nuke(std::string line)
{
    std::istringstream iss(line);
    iss.ignore();

    double x    = (iss >> x, x);
    double y    = (iss >> y, y);
    double rad  = (iss >> rad, rad);

    l_->add_nuke(Nuke(Point(x, y), rad));
}

void MapReader::read_source(std::string line)
{

    std::istringstream iss(line);
    iss.ignore();

    double x     = (iss >> x, x);
    double y     = (iss >> y, y);
    double edge  = (iss >> edge, edge);
    double alpha = (iss >> alpha, alpha);
    int wl       = (iss >> wl, wl);

    l_->set_source(Source(Point(x ,y), edge, alpha, wl));
}

void MapReader::read_wall(std::string line)
{
    std::istringstream iss(line);
    iss.ignore();

    int x1 = (iss >> x1, x1);
    int y1 = (iss >> y1, y1);
    int x2 = (iss >> x2, x2);
    int y2 = (iss >> y2, y2);

    l_->add_wall(Wall(Point(x1, y1), Point(x2, y2)));
}

Level * MapReader::level(std::string path)
{
    if (l_ == nullptr)
        read_file(path);

    return l_;
}

void MapReader::end_level()
{
    delete l_;
    l_ = nullptr;
}
