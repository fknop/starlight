#include "geometry.h"
#include "rectangle.h"


Rectangle::Rectangle(const Point& upperLeft, double width, double height)
    : upperLeft_ {upperLeft}, width_{width}, height_{height}
{
    if (width <= 0 || height <= 0)
        throw std::string("Dimensions invalides");
}

int Rectangle::intersects(const Line& line, std::vector<Point> & points)
{
    /* On crée les 3 coins manquants du rectangle */
    Point bottomLeft(this->upperLeft_.x(),
                     this->upperLeft_.y() + this->height_);

    Point upperRight(this->upperLeft_.x() + this->width_,
                     this->upperLeft_.y());

    Point bottomRight(this->upperLeft_.x() + this->width_,
                      this->upperLeft_.y() + this->height_);

    /* On push les 4 cotés du rectangle dans un vecteur */
    std::vector<LineSegment> segments
    {
            LineSegment(this->upperLeft_, upperRight),
            LineSegment(bottomLeft, bottomRight),
            LineSegment(this->upperLeft_, bottomLeft),
            LineSegment(upperRight, bottomRight)
    };

    /* Pour chaque coté, si il existe une intersection
     * on le push dans le vecteur de points */
    Point * p = nullptr;

    for (auto &i : segments) {
        if (line.intersects(i, &p))
            points.push_back(Point(*p));

        delete p;
    }

    return points.size();
}

int Rectangle::intersects(const LineSegment& ls, std::vector<Point> & points)
{
    Point start = ls.start();
    Point end = ls.end();
    double rad = Geometry::angle(start, end);

    intersects(Line(start, rad), points);

    /* Pour chaque points, si il n'est pas sur le segment,
     * on l'enlève du vecteur */

    for (auto i = points.begin(); i != points.end(); )
    {
        if (!Geometry::is_in_bounding_box(*i, ls))
            i = points.erase(i);
        else
            i++;
    }

    return points.size();
}


Rectangle::~Rectangle()
{

}

