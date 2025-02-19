/*1.9 Summe der geometrischen Folge
Rouven Lacour 3IT24-2*/

#include <stdio.h>
#include <math.h>

int main (void)
{
    float basis, i, a, n, q, summe=0;
    int potenz;

    puts("1.9 Summe der geometrischen Folge");

    printf("Geben Sie a an: ");
    fflush(stdin);
    scanf("%f", &a);

    printf("Geben Sie q an: ");
    fflush(stdin);
    scanf("%f", &q);

    printf("Geben Sie n an: ");
    fflush(stdin);
    scanf("%f", &n);

    summe = a;

    for (i=1; i <= n; i++)
    {
        summe=summe+a*pow(q, n);
    }
    printf("\nDie Summe aller geometrischen Zahlen betraegt %f.", summe);
    
}