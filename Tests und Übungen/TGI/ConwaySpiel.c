/*Conway-Spiel*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ZEILEN 20
#define SPALTEN 20

char feld[ZEILEN][SPALTEN];
char feldU[ZEILEN][SPALTEN];

void nachbar();
void druckefeld();

int main (void)
{
    int i, j;
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

    /*Startpositionen
     - kann man beliebig irgendwas machen*/
    feld[10][10] = 'X' ;
    feld[10][11] = 'X' ;
    feld[10][12] = 'X' ;

    do
    {
        /*prüfen der nächsten Gen.*/
        druckefeld();

        nachbar();

        printf("\nWeiter spielen? [j/n]");
        fflush(stdin);
        scanf("%c", &weiter);
    } while (weiter == 'j');
        

    return 0;
}

void nachbar()
{
    int i, j, anznachbar = 0;

    for (i = 0; i < ZEILEN; i++)
    {
        for (j = 0; j < SPALTEN; j++)
        {
            /*prüft jedes Feld auf seine Nachbarn und zählt diese*/
            anznachbar = 0;
            feldU [i][j] = feld[i][j];
            
                if(feld[i][j-1] == 'X')
                {
                    anznachbar += 1;
                }
                if(feld[i][j+1] == 'X')
                {
                    anznachbar += 1;
                }
                if(feld[i-1][j] == 'X')
                {
                    anznachbar += 1;
                }
                if(feld[i+1][j] == 'X')
                {
                    anznachbar += 1;
                }
                if(feld[i-1][j-1] == 'X')
                {
                    anznachbar += 1;
                }
                if(feld[i+1][j-1] == 'X')
                {
                    anznachbar += 1;
                }
                if(feld[i-1][j+1] == 'X')
                {
                    anznachbar += 1;
                }
                if(feld[i+1][j+1] == 'X')
                {
                    anznachbar += 1;
                }

        /*printf("%d", anznachbar);*/

        /*prueft die Lebensregeln*/   
        if (anznachbar < 2)
        {
            feldU[i][j] = '.';
        }
        else if (anznachbar > 3)
        {
            feldU[i][j] = '.';
        }
        else if (anznachbar == 2)
        {
            if(feld[i][j]=='X')feldU[i][j] = 'X'; /*ohne Prüfung sieht toller aus :c*/
        }
        else if (anznachbar == 3)
        {
            feldU[i][j] = 'X';
        }
        }
        /*printf("\n");*/
        
    }
    for (i = 0; i < ZEILEN; i++)
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