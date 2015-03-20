#include <iostream>
#include <model/point.h>
#include "model/Line.h"
#include "model/Geometry.h"

using namespace std;

int main()
{

    Point a(0, 0);
    Point b(4, 2);
    Line l(a, 2.57);

    Point c(0,2);
    Point d(1, 2);
    Line l2(c, d);

    Point* e = l.getIntersection(l2);

    cout << *e;

    if (e != nullptr && Geometry::isInBoundingBox(*e, LineSegment(c, d)))
        cout << *e;
    else
        cout << "quedal";

    delete e;

    /*
    cout << "Hello World!" << endl;

    int x1 = 1;
    int y1 = 2;

    int x2 = 4;
    int y2 = 6;


    int x3 = 2;
    int y3 = 7;

    int x4 = 5;
    int y4 = 2;


    float A1 = y2 - y1;
    float B1 = x1 - x2;
    float C1 = (A1 * x1) + (B1 * y1);

    float A2 = y4 - y3;
    float B2 = x3 - x4;
    float C2 = (A2 * x3) + (B2 * y3);

    float delta = (A1 * B2) - (A2 * B1);
    if(delta == 0)
        throw "Lines are parallel";

    float x = (B2*C1 - B1*C2) / delta;
    float y = (A1*C2 - A2*C1) / delta;

    cout << "(x = " << x << ", y = " << y << ")" << endl;
*/
    return 0;
}

