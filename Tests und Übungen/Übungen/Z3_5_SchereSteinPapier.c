/*Schere-Stein-Papier*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main (void)
{
    char Spieler1[100];
    char Spieler2[100];
    int wahl, score1, score2;
    char *zeichen[] = {"Stein", "Schere", "Papier", NULL };
    char wahl1[10], wahl2[10];

    printf("Name des ersten Spielers eingeben: ");
    fflush(stdin);
    scanf("%s", Spieler1);  /*kein &, weil Feld schon Adresse*/

    printf("Name des zweiten Spielers eingeben: ");
    fflush(stdin);
    scanf("%s", Spieler2);

    srand(time(NULL));

    /*Werfen für 1*/
    wahl = rand() % 2;  /*Stein 0, Schere 1, Papier 2*/
    strcpy(wahl1, zeichen[wahl]); 

    /*Werfen für 2*/
    wahl = rand() % 2;  /*Stein 0, Schere 1, Papier 2*/
    strcpy(wahl2, zeichen[wahl]);

    printf("%20s, %10s | %20s, %10s\n", Spieler1, wahl1, Spieler2, wahl2);

    if (wahl1 == wahl2) puts("Unentschieden!");
    else if ((wahl1=="Stein") && (wahl2=="Schere") ||
            wahl1 == "Schere" && (wahl2 == "Papier") ||
            wahl1 == "Papier" && (wahl2 == "Stein"))
            {
                score1 ++;
                puts("Spieler 1 gewinnt!");
            }
    else
    {
        score2 ++;
        puts("Spieler 2 gewinnt!");
    }

    return 0;
}