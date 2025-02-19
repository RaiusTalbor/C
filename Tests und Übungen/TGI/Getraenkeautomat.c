/*Getränkeautomat*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define WARTEZEIT 5000

int zustand  = 1;
int getraenk;
float geld, eingabe;

void status();

int main (void)
{
    while (zustand != 0)
    {
        switch (zustand)
        {
        case 1: /*Start*/
            status();
            printf("\n---------------------------");
            printf("\n2 - Geldeinwurf");
            printf("\n3 - Getraenkeauswahl");
            printf("\n4 - Getraenkeausgabe");
            printf("\n5 - Guthabenanzeige");
            printf("\n6 - Geld zurueck");
            printf("\n7 - Getraenkewahl zuruecksetzen");
            printf("\n0 - EXIT");
            printf("\n---------------------------");
            printf("\nIhre Eingabe: ");            
            fflush(stdin);
            scanf("%d", &zustand);           
            break;
        
        case 2:
            status();
            printf("\nBitte Geld einwerfen: ");
            fflush(stdin);
            scanf("%f", &eingabe);

            geld += eingabe;

            zustand = 1;

            break;

        case 3:
            status();
            printf("\nBitte Getraenk auswaehlen (0-2): ");
            fflush(stdin);
            scanf("%d", &getraenk);

            if ((getraenk < 0) && (getraenk > 2))
            {
                printf("\nUngültige Eingabe!");
            }
            zustand = 1;

            break;

        case 4: /*Getränkeausgabe*/
            status();
            switch (getraenk)
            {
            case 0:
                if (geld >= 0.50)
                {
                    printf("\nBitteschönN!");
                    geld = geld - 0.50;
                }
                else
                {
                    printf("\nBitte Geld eingeben!");
                }
                break;
            case 1:
                if (geld >= 1.00)
                {
                    printf("\nBitteschönN!");
                    geld = geld - 1.00;
                }
                else
                {
                    printf("\nBitte Geld eingeben!");
                }
                break;
            case 2:
                if (geld >= 1.50)
                {
                    printf("\nBitteschönN!");
                    geld = geld - 1.50;
                }
                else
                {
                    printf("\nBitte Geld oder Getraenk eingeben!");
                }
                break;
            
            default:
                break;
            Sleep(WARTEZEIT);
            zustand = 1;
            /*Break, finde ich aber hier nicht verkehrt ^^"*/
            }
        case 5:
        {
            printf("\nIhr aktuelles Guthaben: %.2f EUR", geld);
            Sleep(WARTEZEIT);
            zustand = 1;
            break;
        }
        case 6:
        {
            geld = 0;
            printf("\nGeld ausgegeben! Ihr aktuelles Guthaben: %.2f EUR", geld);
            Sleep(WARTEZEIT);
            zustand = 1;
            break;
        }
        case 7:
        {
            getraenk = 0;
            printf("\nAuswahl zurueckgesetzt! Ihr aktuelles Guthaben: %.2f EUR", geld);
            Sleep(WARTEZEIT);
            zustand = 1;
            break;
        }

        default:
            printf("\nAutomat wird beendet.");
            zustand = 0;
            break;
        }

    }
    printf("\nAutomat wird beendet.");
    return 0;
}

void status()
{
    system("cls");
    printf("-------------------------");
    printf("\nGetraenkeautomat");
    printf("\nGetraenkeauswahl: %d", getraenk);
    printf("\nGuthaben: %.2f EUR", geld);
    printf("\n---------------------------");
}