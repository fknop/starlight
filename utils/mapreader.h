#ifndef MAPREADER_H
#define MAPREADER_H

#include <string>

#include "model/level.h"

class MapReader
{

private:

    static Level * l_;

    /*
     * Les méthodes ci-dessous servent
     * à lire le fichier et à ajouter un
     * élement au jeu.
     */
    static void read_file(std::string line);
    static void read_source(std::string line);
    static void read_wall(std::string line);
    static void read_destination(std::string line);
    static void read_nuke(std::string line);
    static void read_crystal(std::string line);
    static void read_mirror(std::string line);
    static void read_lens(std::string line);
    static void read_size(std::string line);


public:
    /**
     * Retourne le niveau correspondant au fichier.
     * @param path le chemin et nom du fichier.
     * @return le niveau correspondant.
     */
    static Level* level(std::string path);

    /**
     * Supprime le niveau correspondant au fichier
     * lu précédemment.
     */
    static void end_level();
};

#endif // MAPREADER_H
