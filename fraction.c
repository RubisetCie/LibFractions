/*  Fichier     : fraction.c
    Auteur      : Matthieu Carteron
    Description :
*/

#ifdef DEBUG
#include <assert.h>     // L'utilisation de la fonction "assert" permettant de verifier l'exactitude d'une condition sous peine d'arret immediat
#endif // NDEBUG

#include "fraction.h"

// Retourne le plus grand diviseur commun avec a et b :
static int gcd(int a, int b)
{
    int t;
    do
    {
        if (a < b)
        {
			t = a;
            a = b;
            b = t;
        }

        a -= b;
    } while (a);

    return b;
}

// Retourne une fraction a partir du numerateur et du denominateur :
Fract fract_create(int num, int den)
{
    #ifdef DEBUG
    assert(den != 0);
    #endif // DEBUG

    Fract result =
    {
        num,
        den
    };

    return result;
}

// Retourne la somme des fractions a et b :
Fract fract_add(Fract a, Fract b)
{
    Fract result =
    {
        (a.numerateur * b.denominateur) + (b.numerateur * a.denominateur),
        b.denominateur * b.denominateur
    };

    return result;
}

// Retourne la difference des fractions a et b :
Fract fract_subtract(Fract a, Fract b)
{
    Fract result =
    {
        (a.numerateur * b.denominateur) - (b.numerateur * a.denominateur),
        b.denominateur * b.denominateur
    };

    return result;
}

// Retourne le produit des fractions a et b :
Fract fract_multiply(Fract a, Fract b)
{
    Fract result =
    {
        a.numerateur * b.numerateur,
        b.denominateur * b.denominateur
    };

    return result;
}

// Retourne le quotient des fractions a et b :
Fract fract_divide(Fract a, Fract b)
{
    Fract result =
    {
        a.numerateur / b.numerateur,
        b.denominateur / b.denominateur
    };

    return result;
}

// Retourne la forme simplifiee de la fraction fract :
Fract fract_simplify(Fract fract)
{
    int diviseur = gcd(fract.numerateur, fract.denominateur);

    Fract result =
    {
        fract.numerateur / diviseur,
        fract.denominateur / diviseur
    };

    return result;
}

// Retourne le resultat approxime de la fraction fract :
float fract_approximate(Fract fract)
{
    float result = (float)fract.numerateur / fract.denominateur;

    return result;
}
