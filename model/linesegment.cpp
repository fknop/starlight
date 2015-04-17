#include "model/linesegment.h"

#include "utils/umath.h"


LineSegment::LineSegment(const Point& p1, const Point& p2)
{
    set_positions(p1, p2);
}

bool LineSegment::contains(const Point& p) const
{
    // On vérifie que le point se situe dans le rectangle
    // que constitue le segment.
    return ((std::min(start_.x(), end_.x()) < p.x() ||
             umath::equals(std::min(start_.x(), end_.x()), p.x())) &&
            (std::max(start_.x(), end_.x()) > p.x() ||
             umath::equals(std::max(start_.x(), end_.x()), p.x())) &&
            (std::min(start_.y(), end_.y()) < p.y() ||
             umath::equals(std::min(start_.y(), end_.y()), p.y())) &&
            (std::max(start_.y(), end_.y()) > p.y() ||
             umath::equals(std::max(start_.y(), end_.y()), p.y())));
}

void LineSegment::translate(const double x, const double y)
{
    start_.set_position(start_.x() + x, start_.y() + y);
    end_.set_position(end_.x() + x, end_.y() + y);
}

void LineSegment::rotate(const Point& pivot, double rotation)
{
    // On a un point x et y avec un angle q et une distance r.
    // x = r * cos(q)
    // y = r * sin(q)
    // On ajoute un angle f :
    // x' = r * cos(q+f) = r * cos(q) * cos(f) - r*sin(q) * sin(f)
    // y' = r * sin(q+f) = r * sin(q) * cos(f) - r*cos(q) * sin(f)
    // x' = x * cos(f) - y * sin(f)
    // y' = x * sin(f) + y * cos(f);

    translate(-pivot.x(), -pivot.y());
    double x1 = ((start_.x() * std::cos(rotation)) -
                 (start_.y() *std::sin(rotation)));

    double y1 = (start_.x() * std::sin(rotation)) +
                (start_.y() * std::cos(rotation));

    double x2 = ((end_.x() * std::cos(rotation)) -
                (end_.y() *std::sin(rotation)));

    double y2 = (end_.x() * std::sin(rotation)) +
                (end_.y() * std::cos(rotation));

    set_positions(Point(x1, y1), Point(x2, y2));
    translate(pivot.x(), pivot.y());
}

bool LineSegment::operator==(const LineSegment& ls) const
{
    return (this->start_ == ls.start_ && this->end_ == ls.end_)
            || (this->start_ == ls.end_ && this->end_ == ls.start_);
}

Line LineSegment::to_line() const
{
    return Line(start_, end_);
}

void LineSegment::set_positions(const Point& p1, const Point& p2)
{
    if (p1.x() < p2.x() ||
            (umath::equals(p1.x(), p2.x()) && p1.y() < p2.y()))
    {
        start_ = p1;
        end_ = p2;
    }
    else if (p1.x() > p2.x() ||
            (umath::equals(p1.x(), p2.x()) && p1.y() > p2.y()))
    {
        start_ = p2;
        end_ = p1;
    }
}
