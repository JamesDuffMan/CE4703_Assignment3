#include "creation.h"
	
/*create polynomial takes in coeffiecients and lengths. it returns a polynomial pol. */
polynomial* createPolynomial(double* coefficients, int length)
{
    polynomial* pol;
    pol = malloc(sizeof(polynomial));
    double* coefficients2 = malloc(sizeof(double) * length);
	
    for(int i = 0; i < length; i++)
    {
        coefficients2[i] = coefficients[i];
    }
    /*First line stores coeffiecient length. 2nd line store a pointer to the coeffiecients.*/
    pol->length = length;
    pol->coefficients = coefficients2;

    return pol;
}
/*deletePolynomial takes in a polynomial and frees the memory it is associated with.*/
void deletePolynomial(polynomial* pol)
{
    free(pol->coefficients);
    free(pol);
}
