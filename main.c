#include <stdlib.h>
#include <stdio.h>

#include <fraction.h>

int main()
{
    Fract fraction1 = fract_create(4, 0);

    fraction1 = fract_simplify(fraction1);

    printf("Fraction 1 : %d / %d\n", fraction1.numerateur, fraction1.denominateur);
    printf("Fraction 1 = %f\n", fract_approximate(fraction1));

    return 0;
}
