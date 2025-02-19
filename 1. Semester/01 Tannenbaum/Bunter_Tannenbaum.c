/* Tannenbaum V0.0.1
Rouven J. Lacour, s3005525, 3IT24-2*/

/*zeichnet und schmückt einen Tannenbaum*/

/*Einfügen der Standardbibliotheken*/
#include <stdio.h>
#include <stdlib.h> /*rand()*/
#include <time.h> /*zum initialisieren des Zufallsgenerators*/

/*Deklarieren der Funktionen*/
int Stamm(int breite); /*zeichnet den Stamm*/
int Krone(int breite); /*zeichnet die Krone*/
int Stern(int breite); /*zeichnet den Stern*/

int main (void)
{
    int minhoehe = 3, maxhoehe = 17; /*definieren der zufäliigen Höhe*/
    int breite; /*deklarieren der noch nicht definierten Breite*/
    int fkt; /*Aufruf der Funktionen*/
    
    /*Auswahl der zufälligen Höhe
    Modulo --> Rest, max. so groß wie Modulo+1 (deswegen +1)
    Minhöhe garantiert über letzten Summanden (mind. so hoch)
    Maxhöhe garantiert durch Abzug der Minhöhe vorher*/
    srand(time(NULL)); /*Initialisierung des Zufallsgenerators --> Zufallswerte basierend auf Zeit als ändernde Größe*/
    breite = rand() % (maxhoehe - minhoehe + 1) + minhoehe;

    /*Zeichne die jeweiligen Teile*/
    fkt = Stern(breite);
    fkt = Krone(breite);
    fkt = Stamm(breite);

    return 0;

}

/*Definieren der einzelnen Fkt.*/

int Stamm(int breite)
{
    int i=0; /*Zählvariable*/

    /*Um in die Mitte | als Stamm zu zeichnen, müssen bis zur Hälfte Breite (Achtung, gedoppelt durch Nadeln); -1 wegen Symmetrie 
    Leerzeichen stehen (for)*/
    for (i; i < (breite-1) ; i++)
    {
        printf(" ");
    }

    printf("||\n    \033[0m");

    return 0;
}

int Krone(int breite)
{
    int i=0; /*Zählvariable*/
    int hoehe=1; /*Zählvariable, Äquivalent zur aktuellen Höhe*/
    int schmuckzufall; /*gibt die Zufallszahl für den Schmuck an*/
    int schmuckrate = 7; /*gibt an, wie wahrscheinlich der Schmuck ist 0-25; je größer, desto wahrscheinlicher*/
    /*Idee der Wahrscheinlichkeit: Zahlen bis 100 für Wahrscheinlichkeit; die Obergrenze wird unten festgelegt. (und beträgt entsprechend
    nicht mehr als 25%, weil sonst keine Nadeln) 
    Liegt Zahl in Bereich, dann dieses Zeichen gedruckt*/

    for (hoehe; hoehe < breite; hoehe++) /*für jede Zeile, bis Du die aktuelle Höhe (letzte Breite) erreichst, tue das:*/
    {
        /*zeichnet Leerzeichen, Abstand zum Rand*/
        for (i=0; i < breite-hoehe; i++)
        {
            printf(" ");
        }

        printf("\033[32m/"); /*Seite Baum*/

        /*zeichnet Nadeln und Schmuck*/
        for (i=0; i < 4*hoehe-4; i=i+2) /*Mal vier, da zwei auf jeder Höhe weg und Höhenabhängigkeit; -4, um in Höhe 1 die Spitze zu haben*/
        {
            /*Den Schmuck zufällig auswählen und statt x setzen - die Möglichkeit, über Var. Wahrscheinlichkeit einstellen*/
            schmuckzufall = (rand() % 100);

            if (schmuckzufall < 100 - 4*schmuckrate)
            {
                printf("\033[32mx");
            }
            else if (schmuckzufall < 100 - 3*schmuckrate)
            {
                printf("\033[31mo");
            }
            else if (schmuckzufall < 100 - 2*schmuckrate)
            {
                printf("\033[34mO");
            }
            else if (schmuckzufall < 100 - 1*schmuckrate)
            {
                printf("\033[35m_");
            }
            else if (schmuckzufall < 100 - 0)
            {
                printf("\033[33m*");
            }
            else
            {
                printf("\033[32mx"); /*Falls wirklich gar nichts geht*/
            }
        }

        printf("\033[32m\\"); /*Seite Baum*/

        /*rutscht in nächste Zeile, bevor neue Höhe beginnt*/
        printf("\n");
    }

    return 0;
}

int Stern(int breite)
{
    int i=0; /*Zählvariable*/
    int schmuckzufall; /*gibt die Zufallszahl für den Schmuck an*/

    /*Grundsätzliche Idee
    Stern immer Höhe=3, deswegen für Übersicht hart codiert ohne for
    Schritt 1: zeichnet nötigen Leerzeichen (wie bei Stamm)
    Schritt 2: zeichnet den jeweiligen Sternteil, sucht dabei aus Vorlagen per Zufall aus
    Schritt 3: wechselt zur nächsten Höhe*/
    /*natürlich mehr Variationen möglich*/

    /*ZEILE 3 - Sternkopf*/
    /*3 als erstes, wegen Zeilenwechsel*/
    /*zeichnet Leerzeichen, Abstand zum Rand, zeichnet wie bei Stamm in die Mitte*/
    for (i=0; i < (breite-2) ; i++)
    {
        printf("\033[33m ");
    }

    schmuckzufall = (rand() % 100);

    if (schmuckzufall < 25) /*Angabe immer der Obergrenze - Untergrenze jeweils 0*/
    {
        printf(" || ");
    }
    else if (schmuckzufall < 50)
    {
        printf(" xx ");
    }
    else if (schmuckzufall < 75)
    {
        printf("\\II/");
    }
    else if (schmuckzufall < 100)
    {
        printf("\\  /");
    }
    /*rutscht in nächste Zeile, bevor neue Höhe beginnt*/
    printf("\n");

    /*ZEILE 2 - Sternmitte*/
    for (i=0; i < (breite-2) ; i++)
    {
        printf(" ");
    }

    schmuckzufall = (rand() % 100);

    if (schmuckzufall < 25)
    {
        printf("-xx-");
    }
    else if (schmuckzufall < 50)
    {
        printf("xxxx");
    }
    else if (schmuckzufall < 75)
    {
        printf("<xx>");
    }
    else if (schmuckzufall < 100)
    {
        printf("x--x");
    }
    /*rutscht in nächste Zeile, bevor neue Höhe beginnt*/
    printf("\n");

    /*ZEILE 1 - Sternboden*/
    for (i=0; i < (breite-2) ; i++)
    {
        printf(" ");
    }

    schmuckzufall = (rand() % 100);

    if (schmuckzufall < 25)
    {
        printf(" || ");
    }
    else if (schmuckzufall < 50)
    {
        printf("/||\\");
    }
    else if (schmuckzufall < 75)
    {
        printf("/II\\");
    }
    else if (schmuckzufall < 100)
    {
        printf(" II ");
    }
    /*rutscht in nächste Zeile, bevor neue Höhe beginnt*/
    printf("\n");

    return 0;
}