#include <string>
#include <vector>
#include <algorithm>

#include "geometry.h"
#include "level.h"
#include "constants.h"

Level::Level(double w, double h) : width_ {w}, height_ {h},
    walls_ { {{.0, .0}, {.0, h}}, {{.0, h}, {w, h}},
{{w, h}, {w, .0}}, {{w, .0}, {.0, .0}} }
{
    if (w <= 0 || h <= 0)
        throw std::string("La taille et la longueur "
                          "du plateau doivent etre strictement positives");
}

void Level::compute_rays()
{
    this->rays_.clear();

    if (source_.on())
    {
        Point pSource = this->source_.position();
        double radians = this->source_.angle();
        Line ray(pSource, radians);

        State state = compute_ray(ray, this->source_.wavelength());
        switch (state)
        {
        case State::WIN:
            notify_all("GAME_WON");
        case State::LOSE:
            notify_all("GAME_LOST");
        case State::CONTINUE: case State::STOP:
            notify_all("CONTINUE");
        }
    }
    else
    {
        notify_all("CLEAR_RAYS");
    }




}

Level::State Level::compute_ray(Line& line, int wl)
{

    Nuke* nuke = nullptr;
    Mirror* mirror = nullptr;
    Lens* lens = nullptr;
    Crystal* crystal = nullptr;
    State state;

    double angle = line.angle();
    double new_wl = wl;

    get_intersections(line);

    Element::Type type = this->intersections_.at(0).element()->type();
    Point* new_line_origin = this->intersections_.at(0).point();

    switch (type)
    {

        case Element::Type::CRYSTAL:
        {
            crystal = dynamic_cast<Crystal*> (this->intersections_.at(0).element());
            new_wl += crystal->modifier();

            if (this->intersections_.at(1).element() == crystal)
                new_line_origin = this->intersections_.at(1).point();

            state = State::CONTINUE;
            break;
        }

        case Element::Type::DEST:
        {
            this->dest_.set_lighted_up(true);
            state = State::WIN;
            break;
        }

        case Element::Type::LENS:
        {
            lens = dynamic_cast<Lens*> (this->intersections_.at(0).element());
            if (wl >= lens->wl_min() && wl <= lens->wl_max())
            {
                if (this->intersections_.at(1).element() == lens)
                    new_line_origin = this->intersections_.at(1).point();
                state = State::CONTINUE;
            }
            else
            {
                state = State::STOP;
            }

            break;
        }

        case Element::Type::MIRROR:
        {
            mirror = dynamic_cast<Mirror*> (this->intersections_.at(0).element());
            angle = get_reflection_angle(angle, mirror->angle());
            state =  State::CONTINUE;
            break;
        }

        case Element::Type::NUKE:
        {
            nuke = dynamic_cast<Nuke*> (this->intersections_.at(0).element());
            nuke->set_lighted_up(true);
            state = State::LOSE;
            break;

        }

        case Element::Type::WALL:
        {
            state = State::STOP;
            break;
        }

    }

    this->rays_.push_back(Ray(line.origin(),
                          *(this->intersections_.at(0).point()),
                          wl));

    if (state == State::CONTINUE)
    {
        Line newLine(Point(*new_line_origin), angle);
        return compute_ray(newLine, new_wl);
    }
    else
    {
        return state;
    }


}

void Level::get_intersections(const Line& line)
{
    this->intersections_.clear();
    std::vector<Point> points;
    Point* p = nullptr;

    // Ajout des intersections au vecteur d'intersections
    mirrors_intersections(line, this->intersections_, &p);
    lenses_intersections(line, this->intersections_, points);
    walls_intersections(line, this->intersections_, &p);
    dest_intersections(line, this->intersections_, points);
    nukes_intersections(line, this->intersections_, points);
    crystals_intersections(line, this->intersections_, points);

    // Suppression des intersections du mauvais côté.
    erase_wrongs_intersections(line, this->intersections_);
    // Trie les intersections selon leur distance par rapport
    // à l'origine du rayon
    sort_intersections(line, this->intersections_);
}


///// SI BUG -- RESTAURER L'ANCIENNE VERSION /////
double Level::get_reflection_angle(double angle, double alpha)
{
    double p = std::fmod((M_PI_2 + alpha), (2 * M_PI));
    double angleRayMirror = std::abs(p - (std::fmod(angle, M_PI)));

    if (std::fmod(angle, M_PI) == std::fmod(alpha, M_PI))
        return std::fmod((angle + M_PI), (2*M_PI)); // angle de l'inclinaison

    else if (std::fmod(angle, M_PI) == std::fmod(p, M_PI))
        return std::fmod((p + M_PI), (2 * M_PI)); // perpendiculaire

    else if ((angle > (p + M_PI)))
        return std::fmod((angle - (2 * angleRayMirror) + M_PI), (2 * M_PI));

    else
        return std::fmod((angle + (2 * angleRayMirror) + M_PI), (2 * M_PI));


}

void Level::dest_intersections(const Line &line,
                               std::vector<Intersection>& intersections,
                               std::vector<Point>& points)
{
    if (this->dest_.to_rectangle().intersects(line, points) > 0)
    {
        for (auto &i : points)
            intersections.push_back(Intersection(new Point(i), &this->dest_));
    }
}

void Level::walls_intersections(const Line &line,
                                std::vector<Intersection>& intersections,
                                Point** p)
{
    for (auto &i : this->walls_)
    {
        if (line.intersects(i.to_line_segment(), p))
            intersections.push_back(Intersection(new Point(**p), &i));

        delete *p;
    }
}

void Level::lenses_intersections(const Line &line,
                                 std::vector<Intersection>& intersections,
                                 std::vector<Point>& points)
{
    for (auto &i : this->lenses_)
    {
        points.clear();
        if (i.to_ellipse().intersects(line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(new Point(j), &i));
        }
    }
}

void Level::mirrors_intersections(const Line &line,
                                  std::vector<Intersection>& intersections,
                                  Point** p)
{
    for (auto &i : this->mirrors_)
    {
        if (line.intersects( i.to_line_segment(), p))
            intersections.push_back(Intersection(new Point(**p), &i));

        delete *p;
    }
}

void Level::nukes_intersections(const Line& line,
                                std::vector<Intersection>& intersections,
                                std::vector<Point>& points)
{
    for (auto &i : this->nukes_)
    {
        points.clear();
        if (i.to_ellipse().intersects(line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(new Point(j), &i));
        }
    }
}

void Level::crystals_intersections(const Line &line,
                                   std::vector<Intersection>& intersections,
                                   std::vector<Point>& points)
{
    for (auto &i : this->crystals_)
    {
        points.clear();
        if (i.to_ellipse().intersects(line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(new Point(j), &i));
        }
    }
}

void Level::erase_wrongs_intersections(const Line& line,
                                       std::vector<Intersection>& intersections)
{
    for (auto i = intersections.begin(); i != intersections.end(); )
    {
        if (!Geometry::is_on_good_side(line, *(*i).point()))
            i = intersections.erase(i);
        else
            ++i;
    }
}

///////////////////// TO CHECK ///////////////
void Level::sort_intersections(const Line &line,
                               std::vector<Intersection>& intersections)
{
    std::sort(intersections.begin(), intersections.end(),
              [line](const Intersection& a, const Intersection& b) -> bool
    {
        int distance_a = std::rint(a.point()->distance(line.origin()));
        int distance_b = std::rint(b.point()->distance(line.origin()));
        return (distance_a < distance_b);
    });
}

void Level::notify(Observable* obs, std::string msg)
{
    compute_rays();
}

