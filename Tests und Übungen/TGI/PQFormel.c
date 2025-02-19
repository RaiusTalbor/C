/*1_5_PQFormel*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double p,q, diskriminante, x1, x2;

    puts("PQFormel");

    puts("p: ");
    fflush(stdin);
    scanf("%lf", &p);
    
    puts("q: ");
    fflush(stdin);
    scanf("%lf", &q);

    printf("Sie haben folgenden Wert eingeg.: p: %lf, q: %lf \n", p, q);

    diskriminante = p/2 * (p/2)-q ;

    /*Wenn man will, noch für eine Lösung für eine Nullstelle*/
    if (diskriminante < 0.0)
    {
        puts("Kein reeler Wert fuer x!");
        return -1;
    }
    else
    {
        x1= (-p/2)+sqrt(diskriminante);
        x2= (-p/2)-sqrt(diskriminante);
        printf("Die Nullstellen lauten %lf und %lf.\n", x1, x2);

    }

}