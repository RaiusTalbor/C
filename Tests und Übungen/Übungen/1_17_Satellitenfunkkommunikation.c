/*1_17_Satellitenfunk
Rouven 3IT24-2*/

#include <stdio.h>

#define LIGHTC 299792.458

int main(void)
{
    double T, t1, t2, L=8000, DR=10, h=12000;

    puts("1.17 Satellitenfunkkommunikation");

    /*Sendezeit*/
    t1 = L / DR;
    /*Ausbreitungszeit Bit / Bit*s */
    t2 = h / LIGHTC ;
    /*Gesamtzeit in s*/
    T = t1 + t2;

    printf("Die Sendezeit betraegt %lf s.", T);

    return 0;
}