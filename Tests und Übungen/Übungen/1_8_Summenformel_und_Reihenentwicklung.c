/*1.8 Summenformel und Reihenentwicklung
Rouven Lacour 3IT24-2*/

#include <stdio.h>
#define AUSGABE 0 /*Möglichkeit, steuern zu lassen, ob Ausgabe gemacht werden soll oder nicht; nicht implementiert*/
#define WS 0 /*Welche Summenregel angewendet werden soll; kann eig. weg.*/

int main (void)
{
    int i, n, summe=0;

    puts("1.8 Summenformel und Reihenentwicklung");

    printf("Geben Sie n an: ");
    fflush(stdin);
    scanf("%i", &n);

    printf("%i", n);

    /*Jede wird addiert*/
    if (n==0)
    {
        summe=0;
        printf("\nDie Summe aller Zahlen betraegt %i.", summe);
    }
    if (WS==0)
    {
        for (i=1; i <= n; i++)
        {
            summe=summe+1/i;
        }
        printf("\nDie Summe aller Zahlen betraegt %i.", summe);
    }
    /*Jede ungerade wird addiert*/
    if (WS==0)
    {
        for (i=1; i <= n; i++)
        {
            if ((i%2) != 0)
            {
                summe=summe+1/i;
            }
        }
        printf("\nDie Summe aller Zahlen (ungerade) betraegt %i.", summe);
    }
    /*Jede ungerade wird -, alle gerade +*/
    if (WS==0)
    {
        for (i=1; i <= n; i++)
        {
            if ((i%2) != 0)
            {
                summe=summe-1/i;
            }
            else
            {
                summe=summe+1/i;
            }
        }
        printf("\nDie Summe aller Zahlen (+/-) betraegt %i.", summe);
    }

    /*printf("\nDie Summe aller Zahlen betraegt %i.", summe); Für WS Unterscheidung*/

}