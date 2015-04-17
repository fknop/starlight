#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>


const double INF {1./0.};

constexpr double EPSILON {0.00001};

constexpr double PI {3.141592653589793238463};

constexpr double PI_2 {PI / 2};

constexpr double PI_4 {PI / 4};

constexpr double PI_2_3 {3 * PI_2};

const std::string STARLIGHT_RULES = "<p>Starlight is a 2D puzzle where you have "
        "to make the light go from the source to the destination without touching "
        "a nuke or… BOOM!, you lose.</p>"
        "<p>Mirrors can be moved and rotated with your keyboard."
        "<p>Movements are achieved with the following keys:</p>"
        "<ul>"
            "<li>Z: Move the mirror up.</li>"
            "<li>S: Move the mirror down.</li>"
            "<li>Q: Move the mirror left.</li>"
            "<li>D: Move the mirror right.</li>"
        "</ul>"
        "<p>while mirror rotations are done through:"
        "<ul>"
            "<li>left arrow key: +1 in counterclockwise direction</li>"
            "<li>right arrow key: -1 in counterclockwise direction</li>"
        "</ul>"
        "<p>You can boost your move by pressing the 'Shift' key.</p>"
        "<p style='font-weight: bold;'>Enjoy your game!</p>";

#endif // CONSTANTS_H

