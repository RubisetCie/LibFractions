/*  Fichier     : fraction.h
    Auteur      : Matthieu Carteron
    Description :
*/

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

typedef struct Fract
{
    int numerateur;
    int denominateur;
} Fract;

Fract fract_create(int num, int den);

Fract fract_add(Fract a, Fract b);
Fract fract_subtract(Fract a, Fract b);
Fract fract_multiply(Fract a, Fract b);
Fract fract_divide(Fract a, Fract b);

Fract fract_simplify(Fract fract);
float fract_approximate(Fract fract);

#endif // FRACTION_H_INCLUDED
