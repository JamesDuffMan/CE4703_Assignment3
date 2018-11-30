#include "mainProgram.h"

double *getPolynomialData(int *length_ret);

int main(int argc, char **argv)
{
    polynomial *pol1;
    int length;
    double *coefficients = getPolynomialData(&length);
    pol1 = createPolynomial(coefficients, length);
    printPolynomial(pol1);
    deletePolynomial(pol1);
}

double *getPolynomialData(int *length_ret)
{
    printf("enter length of polynomial: ");
    int length;
    scanf("%d", &length);

    double *coefficients;
    coefficients = malloc(sizeof(double) * length);

    for (int i = 0; i < length; i++)
    {
        double userCoEff;//co-eff
        printf("Please insert a co-efficent at power %d: ", i);
        scanf("%lf", &userCoEff);
        coefficients[i] = userCoEff;
    }

    *length_ret = length;
    return coefficients;
}
