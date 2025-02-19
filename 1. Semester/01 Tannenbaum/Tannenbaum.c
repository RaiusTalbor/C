/* Tannenbaum V1.0.0
Rouven J. Lacour, s3005525, 3IT24-2*/

/*zeichnet und schmückt einen Tannenbaum*/

/*Einfügen der Standardbibliotheken*/
#include <stdio.h>
#include <stdlib.h> /*rand()*/
#include <time.h> /*zum initialisieren des Zufallsgenerators*/

/*Deklarieren der Funktionen*/
void Stamm(int breite); /*zeichnet den Stamm*/
void Krone(int breite); /*zeichnet die Krone*/
void Stern(int breite); /*zeichnet den Stern*/

int main (void)
{
    int minhoehe = 4, maxhoehe = 18; /*definieren der zufälligen Höhe; Höhe+1, da Modulo
    nullbasiert (Bäume mit Höhe 2 waren möglich, mit 17 aber nicht)*/
    int breite; /*deklarieren der noch nicht definierten Breite*/
    
    /*Auswahl der zufälligen Höhe
    Modulo --> Rest, max. so groß wie Modulo+1 (deswegen +1)
    Minhöhe garantiert über letzten Summanden (mind. so hoch)
    Maxhöhe garantiert durch Abzug der Minhöhe vorher*/
    srand(time(NULL)); /*Initialisierung des Zufallsgenerators --> Zufallswerte basierend auf Zeit als ändernde Größe*/
    breite = rand() % (maxhoehe - minhoehe + 1) + minhoehe;

    /*Zeichne die jeweiligen Teile*/
    Stern(breite);
    Krone(breite);
    Stamm(breite);

    return 0;

}

/*Definieren der einzelnen Fkt.*/

void Stamm(int breite)
{
    int i=0; /*Zählvariable*/

    /*Um in die Mitte | als Stamm zu zeichnen, müssen bis zur Hälfte Breite (Achtung, gedoppelt durch Nadeln); -1 wegen Symmetrie 
    Leerzeichen stehen (for)*/
    for (i; i < (breite-1) ; i++)
    {
        printf(" ");
    }

    printf("||\n");
}

void Krone(int breite)
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

        printf("/"); /*Seite Baum*/

        /*zeichnet Nadeln und Schmuck*/
        for (i=0; i < 4*hoehe-4; i=i+2) /*Mal vier, da zwei auf jeder Höhe weg und Höhenabhängigkeit; -4, um in Höhe 1 die Spitze zu haben*/
        {
            /*Den Schmuck zufällig auswählen und statt x setzen - die Möglichkeit, über Var. Wahrscheinlichkeit einstellen*/
            schmuckzufall = (rand() % 100);

            if (schmuckzufall < 100 - 4*schmuckrate) /*rechts wird die Obergrenze (Maxwert der Zufallszahl) des Feldes definiert*/
            {
                printf("x");
            }
            else if (schmuckzufall < 100 - 3*schmuckrate)
            {
                printf("o");
            }
            else if (schmuckzufall < 100 - 2*schmuckrate)
            {
                printf("O");
            }
            else if (schmuckzufall < 100 - 1*schmuckrate)
            {
                printf("_");
            }
            else if (schmuckzufall < 100 - 0)
            {
                printf("*");
            }
            else
            {
                printf("x"); /*Falls wirklich gar nichts geht*/
            }
        }

        printf("\\"); /*Seite Baum*/

        /*rutscht in nächste Zeile, bevor neue Höhe beginnt*/
        printf("\n");
    }
}

void Stern(int breite)
{
    int i=0; /*Zählvariable*/
    int schmuckzufall; /*gibt die Zufallszahl für den Schmuck an*/

    /*Grundsätzliche Idee:
    Stern immer Höhe=3, deswegen für Übersicht ohne for, sondern alles nacheinander jede Höhe einzeln
    Schritt 1: zeichnet nötigen Leerzeichen (wie bei Stamm)
    Schritt 2: zeichnet den jeweiligen Sternteil, sucht dabei aus Vorlagen per Zufall aus
    Schritt 3: wechselt zur nächsten Höhe*/
    /*natürlich mehr Variationen implementierbar, ich habe mich auf die beschränkt*/

    /*ZEILE 3 - Sternkopf*/
    /*3 als erstes, wegen Zeilenwechsel*/
    /*zeichnet Leerzeichen, Abstand zum Rand, zeichnet wie bei Stamm in die Mitte*/
    for (i=0; i < (breite-2) ; i++)
    {
        printf(" ");
    }

    schmuckzufall = (rand() % 4);

    if (schmuckzufall == 0) /*Angabe immer der Obergrenze; Untergrenze jeweils 0 (ähnlich wie oben, nur mit festen Zahlen)*/
    {
        printf(" || ");
    }
    else if (schmuckzufall == 1)
    {
        printf(" xx ");
    }
    else if (schmuckzufall == 2)
    {
        printf("\\II/");
    }
    else if (schmuckzufall == 3)
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

    schmuckzufall = (rand() % 4);

    if (schmuckzufall == 0)
    {
        printf("-xx-");
    }
    else if (schmuckzufall == 1)
    {
        printf("xxxx");
    }
    else if (schmuckzufall == 2)
    {
        printf("<xx>");
    }
    else if (schmuckzufall == 3)
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

    schmuckzufall = (rand() % 4);

    if (schmuckzufall == 0)
    {
        printf(" || ");
    }
    else if (schmuckzufall == 1)
    {
        printf("/||\\");
    }
    else if (schmuckzufall == 2)
    {
        printf("/II\\");
    }
    else if (schmuckzufall == 3)
    {
        printf(" II ");
    }
    /*rutscht in nächste Zeile, bevor neue Höhe beginnt*/
    printf("\n");
}