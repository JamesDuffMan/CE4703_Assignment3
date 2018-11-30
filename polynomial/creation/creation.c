#include "creation.h"
	
/////////////////////////////////////////////////////////
// polynomial* createPolynomial(double* coefficients, int length)
// creates a new polynomial from the coefficient values and length that are passed
// and returns a pointer to that created polynomial.
// the passed coefficient array is hard-copied for better function usability.
// 
// parameter: double* coefficients - pointer to an array of coefficient values with value 0 at position 0 etc.
// parameter: int length - the length of the passed coefficients array
// return: polynomial* - pointer to the created polynomial struct
/////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////
// void deletePolynomial(polynomial* pol)
// frees all memory associated with the passed polynomial
// 
// parameter: polynomial* pol - pointer to the polynomial to be deleted
// return: void
/////////////////////////////////////////////////////////
void deletePolynomial(polynomial* pol)
{
    free(pol->coefficients);
    free(pol);
}
