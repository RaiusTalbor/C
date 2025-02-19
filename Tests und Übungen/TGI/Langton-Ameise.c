/*Langton-Ameise*/
/*Rouven L., s3005525, 3IT24-2*/

/*nicht geklärt, was passiert, wenn die Ameise das Feld verlässt*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ZEILEN 30
#define SPALTEN 120

int x = 10;
int y = 60;
int farbe = 0; /*0 schwarz, 1 weiß*/

char feld[ZEILEN][SPALTEN];
char feldU[ZEILEN][SPALTEN];

void gehe();
void druckefeld();

int main (void)
{
    int i, j;
    int anz = 1, anzg = 0;
    char weiter = 'j';

    /*Alles auf 0 setzen*/
    for (i = 0; i < ZEILEN; i++)
    {
        for (j = 0; j < SPALTEN; j++)
        {
            feld[i][j] = '.';
        }
        
    }
    for (i = 0; i < ZEILEN; i++)
    {
        for (j = 0; j < SPALTEN; j++)
        {
            feldU[i][j] = '.';
        }
        
    }

    /*Startposition der Ameise
     - kann man beliebig irgendwas machen*/
    feld[x][y] = '>' ;

    printf("\nWie viele Schritte soll die Ameise jeweils gehen? ");
    fflush(stdin);
    scanf("%d", &anz);

    do
    {
        for (i = 0; i < anz; i++)
        {
            gehe();
            anzg +=1;
        }

        druckefeld();

        printf("\nAnzahl der Schritte bisher: %d", anzg);

        printf("\nWeiter spielen? [j/n]");
        fflush(stdin);
        scanf("%c", &weiter);
    } while (weiter == 'j');
        

    return 0;
}

void gehe()
{
    int i, j;

    for (i = 0; i < ZEILEN; i++) /*speichert IST-Zustand*/
    {
        for (j = 0; j < SPALTEN; j++)
        {
            feldU [i][j] = feld[i][j];
        }
    }

    /*prüft das Feld, in dem Ameise drin ist für Richtung;
    prüft dann, was die Farbe des Feldes ist und färbt es nach verlassen richtig ein
    rückt dann eins weiter*/
    switch (feld[x][y]) /*Ameise rückt eins vor*/
    {
    case '>':
        if (farbe == 0) /*setzt die Farbe des zu verlassenden Feldes*/
        {
            feldU[x][y] = '.';
        }
        else
        {
            feldU[x][y] = 'X';
        }

        x += 1; /*rückt eins vor*/

        if (feldU[x][y]== '.') /*speichert Farbe des zu belegenden Feldes, mit Richtungsänderung*/
        {
            farbe = 0;
            feldU[x][y] = 'v';
        }
        else
        {
            farbe = 1;
            feldU[x][y] = '^';
        }
        
        break;
    case '^':
        if (farbe == 0)
        {
            feldU[x][y] = '.';
        }
        else
        {
            feldU[x][y] = 'X';
        }

        y += 1;

        if (feldU[x][y]== '.') /*speichert Farbe des zu belegenden Feldes*/
        {
            farbe = 0;
            feldU[x][y] = '>';
        }
        else
        {
            farbe = 1;
            feldU[x][y] = '<';
        }

        break;
    case '<':
        if (farbe == 0)
        {
            feldU[x][y] = '.';
        }
        else
        {
            feldU[x][y] = 'X';
        }

        x -= 1;

        if (feldU[x][y]== '.') /*speichert Farbe des zu belegenden Feldes*/
        {
            farbe = 0;
            feldU[x][y] = '^';
        }
        else
        {
            farbe = 1;
            feldU[x][y] = 'v';
        }

        break;
    case 'v':
        if (farbe == 0)
        {
            feldU[x][y] = '.';
        }
        else
        {
            feldU[x][y] = 'X';
        }

        y -= 1;

        if (feldU[x][y]== '.') /*speichert Farbe des zu belegenden Feldes*/
        {
            farbe = 0;
            feldU[x][y] = '<';
        }
        else
        {
            farbe = 1;
            feldU[x][y] = '>';
        }

        break;    
    default:
        break;
    }

    if (farbe==0) /*Färbe Feld um, wie in Regeln*/
    {
        farbe = 1;
    }
    else
    {
        farbe = 0;
    }

    for (i = 0; i < ZEILEN; i++) /*Ueberschreibt IST-Zustand it neuem Zustand*/
    {
        for (j = 0; j < SPALTEN; j++)
        {
            feld[i][j] = feldU[i][j];
            /*printf("%c", feldU[i][j]);*/
        }
        
    }
}

void druckefeld()
{
    int i, j;

    for (i = 0; i < ZEILEN; i++)
    {
        for (j = 0; j < SPALTEN; j++)
        {
            printf("%c", feld[i][j]);
        }
        printf("\n");
    }
}