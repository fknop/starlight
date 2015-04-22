#ifndef UMATH
#define UMATH

#include <cmath>
#include <vector>

class Point;
class Line;
class LineSegment;
class Ellipse;
class Rectangle;


namespace umath
{
/**
     * Renvoie le plus grand diviseur commun entre
     * deux nombres réels.
     * @param a le premier nombre.
     * @param b le deuxième nombre.
     * @return le plus grand diviseur commun.
     */
    double dgcd(double a, double b);

    /**
     * Renvoie le plus petit commun multiple entre
     * deux nombres réels.
     * @param a le premier nombre.
     * @param b le deuxième nombre.
     * @return le plus petit commun multiple.
     */
    double dlcm(double a, double b);

    /**
     * Renvoie rho : (b² - 4ac).
     * @param a la variable a.
     * @param b la variable b.
     * @param c la variable c.
     * @return rho.
     */
    double rho(double a, double b, double c);

    /**
     * Renvoie vrai si les 2 doubles sont égaux.
     * @param a premier double à comparer.
     * @param b second double à comparer.
     * @param epsilon différence tolérée.
     * @return vrai si les 2 doubles sont égaux module l’epsilon, faux sinon.
     */
    bool equals(double a, double b);

    /**
     * Renvoie vrai si la valeur vaut l'infini.
     * @param a la valeur.
     * @return vrai si a est infini, faux sinon.
     */
    bool equals_inf(double a);

    /**
     * Retourne vrai si deux angles dans l'intervalle
     * [0, 2PI] sont égaux.
     * @param a le premier angle.
     * @param b le deuxième angle.
     * @return vrai si les deux angles sont égaux, faux sinon.
     */
    bool angle_equals(double a, double b);

    /**
     * Retourne vrai si deux angles ramenés dans l'intervalle
     * [0, PI] sont égaux.
     * @param a le premier angle.
     * @param b le deuxième angle.
     * @return vrai si les deux angles sont égaux dans l'intervalle
     * [0, PI], faux sinon.
     */
    bool angle_equals_pi(double a, double b);

    /**
     * Transforme alpha en angle dans l'intervalle [0,2PI]
     * et le transforme en positif si négatif, puis le retourne.
     * @param alpha l'angle à transformer.
     * @return l'angle un angle positif dans l'intervalle [0,2PI].
     */
    double to_positive_angle(double alpha);

    /**
     * Retourne l'angle en degrés d'un angle
     * donné en radians.
     * @param rad l'angle en radians.
     * @return l'angle en degrés.
     */
    double rad_to_deg(double rad);

    /**
     * Retrouve la pente d'un segment entre deux points.
     * @param p1 le premier point.
     * @param p2 le deuxième point.
     * @return la pente du segment constitué des deux points donnés.
     */
    double points_to_slope(const Point& p1, const Point& p2);

    /**
     * Transforme un angle en radian en une pente.
     * @param rad l'angle en radian.
     * @return la pente d'un angle.
     */
    double rad_to_slope(double rad);

    /**
     * Retourne l'angle en radians de la pente du segment
     * qui rejoint deux points.
     * @param p1 le premier point.
     * @param p2 le dexième point.
     * @return l'angle en radians de la pente.
     */
    double points_to_rad(const Point& p1, const Point& p2);

    /**
     * Retourne l'angle en radians de la pente donnée.
     * @param slope la pente.
     * @return l'angle en radians de la pente donnée.
     */
    double slope_to_rad(double slope);

    /**
     * Retourne l'angle en radians d'un angle donné
     * en degrés.
     * @param degrees l'angle en degrés.
     * @return l'angle en radians.
     */
    double deg_to_rad(double degrees);

    /**
     * Retourne vrai si un point p se trouve sur la trajectoire de la droite l
     * selon l'angle de la droite à partir du point start.
     * @param l la droite.
     * @param start le point de référence sur la droite.
     * @param p le point à vérifier.
     * @return vrai si le point p se trouve du bon côté du point ref, faux sinon.
     */
    bool is_on_trajectory(const Line& l, const Point& start, const Point& p);

    /**
     * Retourne vrai si la droite possède une intersection
     * avec une autre droite et retourne également
     * le point d'intersection en paramètre et met
     * is_point à vrai si l'intersection est un point.
     * @param l1 la première droite.
     * @param l2 la deuxième droite.
     * @param point le point d'intersection.
     * @param is_point vrai si l'intersection est un point, faux sinon.
     * @return vrai si les droites possèdent une intersection.
     */
    bool intersects(const Line& l1, const Line& l2,
                    Point& point, bool& is_point);

    /**
     * Retourne vrai si la droite possède une intersection
     * avec un segment et retourne également
     * le point d'intersection en paramètre.
     * @param line la droite
     * @param ls le segment.
     * @param intersecion le point d'intersection.
     * @return vrai si la droite et le segment possède une intersection.
     */
    bool intersects(const Line& line, const LineSegment& ls,
                    Point& point, LineSegment& segment, bool& is_point);

   /**
    * Retourne vrai si deux segments possèdent une intersection.
    * Si l'intersection est un point, is_point est mi à vrai et
    * point vaut la valeur du point d'intersection, sinon
    * is_point est faux, result vaut le segment d'intersection entre
    * les deux segments et point possède une valeur indéterminée.
    * @param ls1 le premier segment.
    * @param ls2 le deuxième segment.
    * @param point le point d'intersection.
    * @param result le segment d'intersection
    * @param is_point vrai si l'intersection est un point, faux sinon.
    * @return vrai si les deux segments possèdent une intersection, faux sinon.
    */
    bool intersects(const LineSegment& ls1, const LineSegment& ls2,
                    Point& point, LineSegment& segment, bool& is_point);

   /**
    * Vérifie si une droite possède une ou des intersections
    * avec l'ellipse.
    * @param ellipse l'ellipse
    * @param l la droite.
    * @param points un vecteur de points d'intersections.
    * @return le nombre d'intersections entre l'ellipse et la droite.
    */
    int intersects(const Ellipse& ellipse, const Line& line,
                   std::vector<Point>& points);

   /**
    * Vérifie si un segment de droite possède une ou des
    * intersections avec l'ellipse.
    * @param ellipse l'ellipse.
    * @param l le segment de droite.
    * @param points un vecteur de points d'intersections.
    * @return le nombre d'intersections entre l'ellipse et la droite.
    */
    int intersects(const Ellipse& ellipse, const LineSegment& ls,
                   std::vector<Point>& points);

   /**
    * Vérifie si une droite coupe un rectangle.
    * @param rec le rectangle.
    * @param line la droite.
    * @param points le vecteur de points d'intersections trouvés.
    * @return le nombre d'intersections.
    */
    int intersects(const Rectangle& rec, const Line& line,
                   std::vector<Point>& points);

   /**
    * Vérifie si un segment de droite coupe un rectangle.
    * @param rec le rectangle.
    * @param ls le segment de droite.
    * @param points le vecteur de points d'intersections trouvés.
    * @return le nombre d'intersections.
    */
    int intersects(const Rectangle& rec, const LineSegment& ls,
                   std::vector<Point>& points);

} // namespace umath


#endif // UMATH

