/*GewichtAufPlaneten*/

#include <stdio.h>
#include <stdlib.h>

#define G_ERDE 9.81 /*N/kg*/
#define G_MOND (G_ERDE * 0.17)  
#define G_MARS 3.96

int main (void)
{
    float masse = 1;
    float schritt = 5;
    float grenze = 500;
    float Gewicht_E, Gewicht_M, Gewicht_Ma;

    puts("Aufgabe 1.19 - Erde-, Mond- und Marsschwerkraft");

    for (masse=1; masse<grenze; masse = masse + schritt)
    {
        Gewicht_E = G_ERDE * masse;
        Gewicht_M = G_MOND * masse;
        Gewicht_Ma = G_MARS * masse;

        printf("%.2f | %.2f | %.2f | %.2f \n", masse, Gewicht_E, Gewicht_M, Gewicht_Ma);
    }   

        return 0;
}