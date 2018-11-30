#include <stdio.h>
#include <stdlib.h>

struct polyNode
{
    double coeff;
    double power;
};

int main(int argc, char **argv)
{
    printf("enter length of polynomial: ");
    int length;
    scanf("%d", &length);

    struct polyNode *polynomial;
    polynomial = (struct polyNode *) malloc(sizeof(struct polyNode) * length);

    for (int i = 0; i < length; ++i)
    {
        struct polyNode pn;
        polynomial[i] = pn;
        printf("Please insert a co-efficent: ");
        scanf("%lf", &polynomial[i].coeff);
        printf("Please issert a power: ");
        scanf("%lf", &polynomial[i].power);
    }


    for (int i = 0; i < length; ++i)
    {
        printf("coeff = %lf, power = %lf\n", polynomial[i].coeff, polynomial[i].power);
    }
}
