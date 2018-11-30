#include "testMain.h"

// declaration of helper functions
int equal(double a, double b, double threshhold);

int main(int argc, char **argv)
{
    //run all tests and print results to stdout
    if (testCreation() == 1)
        printf("createPolynomial tested: OK\n");
    else
        printf("createPolynomial tested: ERROR\n");

    if (testAddition() == 1)
        printf("addPolynomials tested: OK\n");
    else
        printf("addPolynomials tested: ERROR\n");

    if (testSubtraction() == 1)
        printf("subtractPolynomials tested: OK\n");
    else
        printf("subtractPolynomials tested: ERROR\n");

    if (testMultiplication() == 1)
        printf("multiplyPolynomial tested: OK\n");
    else
        printf("multiplyPolynomial tested: ERROR\n");

    if (testDivision() == 1)
        printf("dividePolynomial tested: OK\n");
    else
        printf("dividePolynomial tested: ERROR\n");

    if (testNormalization() == 1)
        printf("normalizePolynomial tested: OK\n");
    else
        printf("normalizePolynomial tested: ERROR\n");

    if (testGetOrder() == 1)
        printf("getPolynomialOrder tested: OK\n");
    else
        printf("getPolynomialOrder tested: ERROR\n");
}

/////////////////////////////////////////////////////////
// int equal(double a, double b, double threshhold)
// checks if the passed values are equal within the passed threshhold
// 
// parameter: double a - first value to compare
// parameter: double b - second value to compare
// parameter: double threshhold - threshhold in which the difference between a and b is allowed to lie
// return: int - 1 if a and b are equal within the threshhold, 0 otherwise
/////////////////////////////////////////////////////////
int equal(double a, double b, double threshhold)
{
    double c = a - b;
    if (c < threshhold && c > -1 * threshhold)
        return 1;
    else
        return 0;
}

/////////////////////////////////////////////////////////
// int testCreation()
// tests if the createPolynomial function is working properly
// 
// return: int - 1 if working properly, 0 if not
/////////////////////////////////////////////////////////
int testCreation()
{
    // declare needed variables
    double threshhold = 0.001;
    double *coefficients;
    double *expected_coefficients;
    polynomial *pol1;
    // return 1 means all ok
    int ret = 1;

    // initialize input
    printf("\ncreatePolynomial: test 1\n");
    coefficients = malloc(sizeof(double) * 5);
    coefficients[0] = 1;
    coefficients[1] = 1;
    coefficients[2] = 1;
    coefficients[3] = 2;
    coefficients[4] = 0;

    // save function output in variable
    pol1 = createPolynomial(coefficients, 5);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 1;
    expected_coefficients[1] = 1;
    expected_coefficients[2] = 1;
    expected_coefficients[3] = 2;
    expected_coefficients[4] = 0;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        printf("%d : %lf  -  %lf\n", i, coefficients[i], expected_coefficients[i]);
        if (!equal(coefficients[i], expected_coefficients[i], threshhold))
            // return 0 means there was an error
            ret = 0;
    }

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients);
    deletePolynomial(pol1);

    // initialize input
    printf("\ncreatePolynomial: test 2\n");
    coefficients = malloc(sizeof(double) * 5);
    coefficients[0] = 7.1234;
    coefficients[1] = 0;
    coefficients[2] = 25;
    coefficients[3] = 2;
    coefficients[4] = 33.999;
    // save function output in variable
    pol1 = createPolynomial(coefficients, 5);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 7.1234;
    expected_coefficients[1] = 0;
    expected_coefficients[2] = 25;
    expected_coefficients[3] = 2;
    expected_coefficients[4] = 33.999;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        printf("%d : %lf  -  %lf\n", i, coefficients[i], expected_coefficients[i]);
        if (!equal(coefficients[i], expected_coefficients[i], threshhold))
            // return 0 means there was an error
            ret = 0;
    }

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients);
    deletePolynomial(pol1);

    return ret;
}

/////////////////////////////////////////////////////////
// int testAddition()
// tests if the addPolynomials function is working properly
//
// return: int - 1 if working properly, 0 if not
/////////////////////////////////////////////////////////
int testAddition()
{
    // declare needed variables
    double threshhold = 0.001;
    double *coefficients1;
    double *coefficients2;
    double *expected_coefficients;
    polynomial *pol1;
    polynomial *pol2;
    polynomial *result;
    // return 1 means all ok
    int ret = 1;

    // initialize input
    printf("\naddPolynomials: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);

    coefficients2 = malloc(sizeof(double) * 5);
    coefficients2[0] = 5.44;
    coefficients2[1] = 123;
    coefficients2[2] = 5.5;
    coefficients2[3] = 0.22;
    coefficients2[4] = 0;
    pol2 = createPolynomial(coefficients2, 5);

    // save function output in variable
    result = addPolynomials(pol1, pol2);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 8.04;
    expected_coefficients[1] = 124;
    expected_coefficients[2] = 11.27;
    expected_coefficients[3] = 2.75;
    expected_coefficients[4] = 12;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (!equal(result->coefficients[i], expected_coefficients[i],
                   threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n", result->coefficients[i], expected_coefficients[i]);
        }

    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("+\n");
    printPolynomial(pol2);
    printf("=\n");
    printPolynomial(result);

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients1);
    free(coefficients2);
    deletePolynomial(pol1);
    deletePolynomial(pol2);
    deletePolynomial(result);

    // initialize input
    printf("\naddPolynomials: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = -0.33;
    coefficients1[1] = 2;
    coefficients1[2] = -0;
    coefficients1[3] = -2.2;
    coefficients1[4] = 1;
    pol1 = createPolynomial(coefficients1, 5);

    coefficients2 = malloc(sizeof(double) * 5);
    coefficients2[0] = -5.3;
    coefficients2[1] = -1;
    coefficients2[2] = 2;
    coefficients2[3] = 0;
    coefficients2[4] = -5;
    pol2 = createPolynomial(coefficients2, 5);

    // save function output in variable
    result = addPolynomials(pol1, pol2);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -5.63;
    expected_coefficients[1] = 1;
    expected_coefficients[2] = 2;
    expected_coefficients[3] = -2.2;
    expected_coefficients[4] = -4;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (!equal(result->coefficients[i], expected_coefficients[i],
                   threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n", result->coefficients[i], expected_coefficients[i]);
        }

    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("+\n");
    printPolynomial(pol2);
    printf("=\n");
    printPolynomial(result);

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients1);
    free(coefficients2);
    deletePolynomial(pol1);
    deletePolynomial(pol2);
    deletePolynomial(result);

    return ret;
}

/////////////////////////////////////////////////////////
// int testSubtraction()
// tests if the subtractPolynomials() function is working properly
//
// return: int - 1 if working properly, 0 if not
/////////////////////////////////////////////////////////
int testSubtraction()
{
    // declare needed variables
    double threshhold = 0.001;
    double *coefficients1;
    double *coefficients2;
    double *expected_coefficients;
    polynomial *pol1;
    polynomial *pol2;
    polynomial *result;
    // return 1 means all ok
    int ret = 1;

    // initialize input
    printf("\nsubtractPolynomials: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);

    coefficients2 = malloc(sizeof(double) * 5);
    coefficients2[0] = -5.44;
    coefficients2[1] = -123;
    coefficients2[2] = -5.5;
    coefficients2[3] = -0.22;
    coefficients2[4] = -0;
    pol2 = createPolynomial(coefficients2, 5);

    // save function output in variable
    result = subtractPolynomials(pol1, pol2);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 8.04;
    expected_coefficients[1] = 124;
    expected_coefficients[2] = 11.27;
    expected_coefficients[3] = 2.75;
    expected_coefficients[4] = 12;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (!equal(result->coefficients[i], expected_coefficients[i],
                   threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n", result->coefficients[i], expected_coefficients[i]);
        }

    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("-\n");
    printPolynomial(pol2);
    printf("=\n");
    printPolynomial(result);

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients1);
    free(coefficients2);
    deletePolynomial(pol1);
    deletePolynomial(pol2);
    deletePolynomial(result);

    // initialize input
    printf("\nsubtractPolynomials: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = -0.33;
    coefficients1[1] = 2;
    coefficients1[2] = -0;
    coefficients1[3] = -2.2;
    coefficients1[4] = 1;
    pol1 = createPolynomial(coefficients1, 5);

    coefficients2 = malloc(sizeof(double) * 5);
    coefficients2[0] = 5.3;
    coefficients2[1] = 1;
    coefficients2[2] = -2;
    coefficients2[3] = -0;
    coefficients2[4] = 5;
    pol2 = createPolynomial(coefficients2, 5);

    // save function output in variable
    result = subtractPolynomials(pol1, pol2);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -5.63;
    expected_coefficients[1] = 1;
    expected_coefficients[2] = 2;
    expected_coefficients[3] = -2.2;
    expected_coefficients[4] = -4;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (!equal(result->coefficients[i], expected_coefficients[i],
                   threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n", result->coefficients[i], expected_coefficients[i]);
        }

    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("-\n");
    printPolynomial(pol2);
    printf("=\n");
    printPolynomial(result);

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients1);
    free(coefficients2);
    deletePolynomial(pol1);
    deletePolynomial(pol2);
    deletePolynomial(result);

    return ret;
}

/////////////////////////////////////////////////////////
// int testMultiplication()
// tests if the multiplyPolynomial function is working properly
//
// return: int - 1 if working properly, 0 if not
/////////////////////////////////////////////////////////
int testMultiplication()
{
    // declare needed variables
    double threshhold = 0.001;
    double factor;
    double *coefficients1;
    double *expected_coefficients;
    polynomial *pol1;
    polynomial *result;
    // return 1 means all ok
    int ret = 1;

    // initialize input
    printf("\nmultiplyPolynomial: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);

    factor = -2.1;

    // save function output in variable
    result = multiplyPolynomial(pol1, factor);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -5.46;
    expected_coefficients[1] = -2.1;
    expected_coefficients[2] = -12.117;
    expected_coefficients[3] = -5.313;
    expected_coefficients[4] = -25.2;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (!equal(result->coefficients[i], expected_coefficients[i],
                   threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n", result->coefficients[i], expected_coefficients[i]);
        }
    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("*\n");
    printf("%lf\n", factor);
    printf("=\n");
    printPolynomial(result);

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients1);
    deletePolynomial(result);
    deletePolynomial(pol1);

    // initialize input
    printf("\nmultiplyPolynomial: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);

    factor = -0;

    // save function output in variable
    result = multiplyPolynomial(pol1, factor);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 0;
    expected_coefficients[1] = 0;
    expected_coefficients[2] = 0;
    expected_coefficients[3] = 0;
    expected_coefficients[4] = 0;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (!equal(result->coefficients[i], expected_coefficients[i],
                   threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n", result->coefficients[i], expected_coefficients[i]);
        }
    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("*\n");
    printf("%lf\n", factor);
    printf("=\n");
    printPolynomial(result);

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients1);
    deletePolynomial(result);
    deletePolynomial(pol1);

    return ret;
}

/////////////////////////////////////////////////////////
// int testDivision()
// tests if the dividePolynomial function is working properly
//
// return: int - 1 if working properly, 0 if not
/////////////////////////////////////////////////////////
int testDivision()
{
    // declare needed variables
    double threshhold = 0.001;
    double factor;
    double *coefficients1;
    double *expected_coefficients;
    polynomial *pol1;
    polynomial *result;
    // return 1 means all ok
    int ret = 1;

    // initialize input
    printf("\ndividePolynomial: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = -5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);

    factor = 10;

    // save function output in variable
    result = dividePolynomial(pol1, factor);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 0.26;
    expected_coefficients[1] = 0.1;
    expected_coefficients[2] = -0.577;
    expected_coefficients[3] = 0.253;
    expected_coefficients[4] = 1.2;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (!equal(result->coefficients[i], expected_coefficients[i],
                   threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n", result->coefficients[i], expected_coefficients[i]);
        }
    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("/\n");
    printf("%lf\n", factor);
    printf("=\n");
    printPolynomial(result);

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients1);
    deletePolynomial(result);
    deletePolynomial(pol1);

    // initialize input
    printf("\ndividePolynomial: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);

    factor = -0.05;

    // save function output in variable
    result = dividePolynomial(pol1, factor);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -52;
    expected_coefficients[1] = -20;
    expected_coefficients[2] = -115.4;
    expected_coefficients[3] = -50.6;
    expected_coefficients[4] = -240;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (!equal(result->coefficients[i], expected_coefficients[i],
                   threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n", result->coefficients[i], expected_coefficients[i]);
        }
    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("/\n");
    printf("%lf\n", factor);
    printf("=\n");
    printPolynomial(result);

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients1);
    deletePolynomial(result);
    deletePolynomial(pol1);

    return ret;
}

/////////////////////////////////////////////////////////
// int testNormalization()
// tests if the normalizePolynomial() function is working properly
//
// return: int - 1 if working properly, 0 if not
/////////////////////////////////////////////////////////
int testNormalization()
{
    // declare needed variables
    double threshhold = 0.001;
    double *coefficients1;
    double *expected_coefficients;
    polynomial *pol1;
    polynomial *result;
    // return 1 means all ok
    int ret = 1;

    // initialize input
    printf("\nnormalizePolynomial: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 1;
    coefficients1[1] = 2;
    coefficients1[2] = -3;
    coefficients1[3] = -4;
    coefficients1[4] = -5;
    pol1 = createPolynomial(coefficients1, 5);


    // save function output in variable
    result = normalizePolynomial(pol1);

    // initialize expected output
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -0.2;
    expected_coefficients[1] = -0.4;
    expected_coefficients[2] = 0.6;
    expected_coefficients[3] = 0.8;
    expected_coefficients[4] = 1;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (!equal(result->coefficients[i], expected_coefficients[i],
                   threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n", result->coefficients[i], expected_coefficients[i]);
        }
    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("->\n");
    printPolynomial(result);

    // free memory from previous test
    free(expected_coefficients);
    free(coefficients1);
    deletePolynomial(result);
    deletePolynomial(pol1);

    return ret;
}

/////////////////////////////////////////////////////////
// int testGetOrder()
// tests if the getPolynomialOrder() function is working properly
//
// return: int - 1 if working properly, 0 if not
/////////////////////////////////////////////////////////
int testGetOrder()
{
    // declare needed variables
    double *coefficients1;
    int expected_order;
    polynomial *pol1;
    int order;
    // return 1 means all ok
    int ret = 1;

    // initialize input
    printf("\nnormalizePolynomial: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 1;
    coefficients1[1] = 2;
    coefficients1[2] = -3;
    coefficients1[3] = -4;
    coefficients1[4] = 0;
    pol1 = createPolynomial(coefficients1, 5);

    // save function output in variable
    order = getPolynomialOrder(pol1);

    // initialize expected output
    expected_order = 3;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (order != expected_order)
        { // return 0 means there was an error
            ret = 0;
            printf("%d != %d\n", order, expected_order);
        }
    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("->\n");
    printf("order: %d\n", order);

    // free memory from previous test
    free(coefficients1);
    deletePolynomial(pol1);

    // initialize input
    printf("\nnormalizePolynomial: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 0;
    coefficients1[1] = 0;
    coefficients1[2] = 0;
    coefficients1[3] = 0;
    coefficients1[4] = 0;
    pol1 = createPolynomial(coefficients1, 5);

    // save function output in variable
    order = getPolynomialOrder(pol1);

    // initialize expected output
    expected_order = 0;

    // compare output to expected output while also printing both if not equal
    for (int i = 0; i < 5; i++)
    {
        if (order != expected_order)
        { // return 0 means there was an error
            ret = 0;
            printf("%d != %d\n", order, expected_order);
        }
    }

    // print the performed test to stdout
    printPolynomial(pol1);
    printf("->\n");
    printf("order: %d\n", order);

    // free memory from previous test
    free(coefficients1);
    deletePolynomial(pol1);

    return ret;
}
