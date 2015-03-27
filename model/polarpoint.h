#ifndef POLARPOINT_H
#define POLARPOINT_H

#include "point.h"

class PolarPoint
{

private:
    double distance;
    double angle;
public:
    PolarPoint(const Point &);
    PolarPoint(double distance, double angle);
    ~PolarPoint();

    void setAngle(double a);
    void setDistance(double d);
    double getAngle() const;
    double getDistance() const;
    const Point& toPoint() const;


};

#endif // POLARPOINT_H
