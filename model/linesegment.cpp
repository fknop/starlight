#include "model/linesegment.h"

#include "utils/umath.h"


LineSegment::LineSegment(const Point& p1, const Point& p2)
{
    if (p1.x() < p2.x() ||
            (umath::equals(p1.x(), p2.x()) && p1.y() < p2.y()))
    {
        this->start_ = p1;
        this->end_ = p2;
    }
    else if (p1.x() > p2.x()
             || (umath::equals(p1.x(), p2.x()) && p1.y() > p2.y()))
    {
        this->start_ = p2;
        this->end_ = p1;
    }
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

void LineSegment::rotate(const Point& pivot, double angle)
{
    double pivotX = pivot.x();
    double pivotY = pivot.y();
    double xpad   = start_.distance(pivot);
    double len    = start_.distance(end_);
    double alpha  = umath::points_to_rad(start_, end_) + angle;

    this->translate(-pivotX, -pivotY);

    double new_start_x = 0 - (xpad * std::cos(alpha));
    double new_start_y = 0 + (xpad * std::sin(alpha));
    double new_end_x   = 0 + ((len - xpad) * std::cos(alpha));
    double new_end_y   = 0 - ((len - xpad) * std::sin(alpha));

    start_.set_position(new_start_x, new_start_y);
    end_.set_position(new_end_x, new_end_y);

    this->translate(pivotX, pivotY);
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
