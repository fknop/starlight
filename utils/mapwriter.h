#ifndef MAPWRITER_H
#define MAPWRITER_H

#include <string>

#include "model/level.h"

/**
 * Classe permettant d'écrire un niveau dans un fichier .lvl.
 */
class MapWriter
{
public:

    /**
     * Crée / écrit dans un fichier toutes les
     * caractéristiques d'un niveau.
     * @param level le niveau.
     * @param path le chemin et nom du fichier à écrire.
     */
    static void write(const Level * level, std::string path);
};

#endif // MAPWRITER_H
