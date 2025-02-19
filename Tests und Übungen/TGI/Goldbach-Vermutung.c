/*Goldbach-Vermutung
Rouven 3IT24-2*/

#include <stdio.h>

int Primzahl(int prim);

int main(void)
{
    int i=0, zahl, zahl2, prim, zaehler=0;

    //zahl - prim = andere zahl--> prim; wenn ja, dann :D ; nein, mach weiter

    do
    {
        printf("\nZahl: ");
        fflush(stdin);
        scanf("%d", &zahl);
    } while (zahl % 2 != 0);

    for (i=1; i < zahl/2; i++) /*Durch zwei für nur Hälfte der Erg.*/
    {
        if(Primzahl(i) == 0)
        {
            zahl2 = zahl - i;
            if (Primzahl(zahl2) == 0)
            {
                zaehler += 1;
                printf("\nZerlegung: %d + %d", i, zahl2);
            }
        }
    }

    printf("\n\nAnzahl der Ergebnisse: %d\n", zaehler);
    
    return 0;
}

int Primzahl(int prim)
{
    int i, stop=0;

    for (i = 2; i < prim; i++)
    {
       if (prim % i == 0) /*Prüfung, ob teilbar*/
       {
        return 1; /*Teilbar*/
        stop=1;
       }
    }
    if (stop != 1) /*Wenn nie geteilt wurde*/
    {
        return 0; /*Ist Prim*/
    }
}