#include "visualization.h"


/////////////////////////////////////////////////////////
// void printPolynomial(polynomial* pol)
// prints the passed polynomial to stdout
// 
// parameter: polynomial* pol - pointer to the polynomial to be printed
// return: void
/////////////////////////////////////////////////////////
void printPolynomial(polynomial *pol)
{

    for (int i = pol->length - 1; i >= 0; i--)
    {
        if (i != (pol->length - 1))
        {
            printf(" + ");
        }
        if (i != 0 && i != 1)
        {
            printf("%lf * x^(%d)", pol->coefficients[i], i);
        } else if (i == 1)
        {
            printf("%lf * x", pol->coefficients[i]);
        } else
        {
            printf("%lf", pol->coefficients[i]);
        }
    }

    printf("\n");
}
