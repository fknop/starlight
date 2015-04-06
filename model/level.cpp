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

    rays_.clear();
//    add_mirror(Mirror(Point(30, 500), 29, 58, (M_PI*2 - M_PI_4)));
//    add_mirror(Mirror(Point(60,500), 0, 58, M_PI_4));
//    add_mirror(Mirror(Point(40, 400), 0, 58, M_PI_4));
//    add_mirror(Mirror(Point(90, 380), 0, 58, M_PI_2 + 0.5));

    if (source_.on())
    {
        Point pSource = this->source_.position();
        double radians = this->source_.angle();
        Line ray(pSource, radians);

        State state = compute_ray(ray, this->source_.wavelength());
        if (state == State::WIN)
            std::cout << "TODO";
        else if (state == State::LOSE)
            std::cout << "TODO";
    }

    notify_all("UPDATE_RAYS");

}

Level::State Level::compute_ray(Line& line, int wl)
{
    State state;
    double angle = line.angle();

    Intersection* intersection = get_intersection(line);
    Element::Type type = intersection->element()->type();



    Nuke* nuke = nullptr;
    Mirror* mirror = nullptr;
    Lens* lens = nullptr;
    Crystal* crystal = nullptr;

    switch (type)
    {

        case Element::Type::CRYSTAL:
        {
            crystal = dynamic_cast<Crystal*> (intersection->element());
            wl += crystal->modifier();
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
            lens = dynamic_cast<Lens*> (intersection->element());
            if (wl >= lens->wl_min() && wl <= lens->wl_max())
                state = State::CONTINUE;
            else
                state = State::STOP;
            break;
        }
        case Element::Type::MIRROR:
        {
            mirror = dynamic_cast<Mirror*> (intersection->element());
            angle = get_reflexion_angle(angle, mirror->angle());
            //std::cout << "Angle réfléchi : " << Geometry::rad_to_deg(c) << std::endl;
            state = State::CONTINUE;
            break;
        }
        case Element::Type::NUKE:
        {

            nuke = dynamic_cast<Nuke*> (intersection->element());
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

    this->rays_.push_back(Ray(line.origin(), *intersection->point(), wl));

    if (state == State::CONTINUE)
    {
        Line newLine(Point(*intersection->point()), angle);
        compute_ray(newLine, wl);
    }

    delete intersection;
    return state;
}

Intersection* Level::get_intersection(const Line& line)
{
    std::vector<Intersection> intersections;
    std::vector<Point> points;
    Point* p = nullptr;

    // Ajout des intersections au vecteur d'intersections
    dest_intersections(line, intersections, points);
    walls_intersections(line, intersections, &p);
    lenses_intersections(line, intersections, points);
    mirrors_intersections(line, intersections, &p);
    nukes_intersections(line, intersections, points);
    crystals_intersections(line, intersections, points);

    // Suppression des intersections du mauvais côté.
    erase_wrongs_intersections(line, intersections);
    // Trie les intersections selon leur distance par rapport
    // à l'origine du rayon
    sort_intersections(line, intersections);

    // Retour de l'intersection la plus proche
    return new Intersection(intersections.at(0));
}


////////////////////////////// TODO ////////////////////////////////////
double Level::get_reflexion_angle(double startAngle, double mirrorAngle)
{
    double mAlpha =
            mirrorAngle < 0 ? (2*M_PI) + mirrorAngle : mirrorAngle;


    double a = std::fmod(startAngle, M_PI);
    double b = std::abs(a - mAlpha);
    double c;

    // Perpendiculaire au miroir.
    double d = (M_PI_2 + mirrorAngle);
    if (d < 0)
        d = (2*M_PI) - d;

    if (b > M_PI)
        c = a + std::abs(2 * (M_PI_2 - b));
    else
        c = a - std::abs(2 * (M_PI_2 - b));


    if (c < 0)
        c += (2*M_PI);

    if (c > (2*M_PI))
        c -= (2*M_PI);

    return c;
}

void Level::dest_intersections(const Line &line,
                               std::vector<Intersection>& intersections,
                               std::vector<Point>& points)
{
    if (this->dest_.to_rectangle().intersects(line, points) > 0)
    {
        for (auto &i : points)
            intersections.push_back(Intersection(&i, &this->dest_));
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
        if (i.to_ellipse().intersects(line, points) > 0)
        {
            for (auto &j : points)
                intersections.push_back(Intersection(&j, &i));
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
        int distanceA = std::rint(a.point()->distance(line.origin()));
        int distanceB = std::rint(b.point()->distance(line.origin()));
        return (distanceA < distanceB) ||
                (distanceA == distanceB &&
                 a.element()->type() < b.element()->type());
    });
}

void Level::notify(Observable* obs)
{
    compute_rays();
}

void Level::notify(Observable* obs, std::string msg)
{
    compute_rays();
}

