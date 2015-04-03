#ifndef UMATH
#define UMATH

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
    bool double_equals(double a, double b, double epsilon=0.0001);

} // namespace umath


#endif // UMATH

