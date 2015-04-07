#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>


#ifndef EPSILON
    #define EPSILON 0.0001
#endif

#ifndef INF
    #define INF 1. / 0
#endif

#ifndef M_PI
    #define M_PI 3.141592653589793238463
#endif

#ifndef M_PI_2
    #define M_PI_2 M_PI / 2
#endif

#ifndef M_PI_4
    #define M_PI_4 M_PI / 4
#endif

#ifndef M_PI_2_3
    #define M_PI_2_3 (3 * M_PI_2)
#endif

const std::string STARLIGHT_RULES = "<p>Starlight is a 2D puzzle where you have to make the light go from the source to the destination without touching a nuke or… BOOM!, you lose.</p>"
        "<p>Mirrors can be moved and rotated with your keyboard."
        "<p>Movements are achieved with the following keys:</p>"
        "<ul>"
            "<li>Z: Move the mirror up.</li>"
            "<li>S: Move the mirror down.</li>"
            "<li>Q: Move the mirror left.</li>"
            "<li>D: Move the mirror right.</li>"
        "</ul>"
        "<p>while mirror rotation are done through:"
        "<ul>"
            "<li>left arrow key: +1 in counterclockwise direction</li>"
            "<li>right arrow key: -1 in counterclockwise direction</li>"
        "</ul>"
        "<p style='font-weight: bold;'>Enjoy your game!</p>";



#endif // CONSTANTS_H

