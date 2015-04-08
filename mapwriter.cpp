#include "mapwriter.h"
#include <iostream>
#include <fstream>


MapWriter::MapWriter()
{

}

MapWriter::~MapWriter()
{

}

void MapWriter::write(const Level* level, std::string filename)
{
    std::ofstream level_writer(filename);

    level_writer << level->width() << " "
                 << level->height()
                 << std::endl;

    level_writer << "S "
                 << level->source().position().x() << " "
                 << level->source().position().y() << " "
                 << level->source().edge()         << " "
                 << level->source().angle()        << " "
                 << level->source().wavelength()
                 << std::endl;

    level_writer << "D "
                 << level->dest().position().x() << " "
                 << level->dest().position().y() << " "
                 << level->dest().edge()
                 << std::endl;

    for (auto &i : level->walls())
    {
        if (!(i.start() == Point(0,0) ||
              i.start() == Point(0, level->height()) ||
              i.start() == Point(level->width(),  0) ||
              i.start() == Point(level->width(), level->height())))
        {
            level_writer << "W "
                         << i.start().x() << " "
                         << i.start().y() << " "
                         << i.end().x()   << " "
                         << i.end().y()
                         << std::endl;
        }
    }

    for (auto &i : level->mirrors())
    {
        level_writer << "M "
                     << i.pivot().x()     << " "
                     << i.pivot().y()     << " "
                     << i.x_pad()         << " "
                     << i.length()        << " "
                     << i.angle()         << " "
                     << i.min_pivot().x() << " "
                     << i.min_pivot().y() << " "
                     << i.max_pivot().x() << " "
                     << i.max_pivot().y() << " "
                     << i.min_angle()     << " "
                     << i.max_angle()
                     << std::endl;
    }

    for (auto &i : level->crystals())
    {
        level_writer << "C "
                     << i.center().x() << " "
                     << i.center().y() << " "
                     << i.radius()     << " "
                     << i.modifier()
                     << std::endl;
    }

    for (auto &i : level->lenses())
    {
        level_writer << "L "
                     << i.position().x() << " "
                     << i.position().y() << " "
                     << i.width()        << " "
                     << i.height()       << " "
                     << i.wl_min()       << " "
                     << i.wl_max()
                     << std::endl;
    }

    for (auto &i : level->nukes())
    {
        level_writer << "N "
                     << i.position().x() << " "
                     << i.position().y() << " "
                     << i.radius()
                     << std::endl;
    }

    level_writer.close();
}
