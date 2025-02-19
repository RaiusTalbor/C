/*Datei_schreiben_lesen in cool*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
r, read
w, write
a, append
b, binary
t, textmodus
*/

int main (void)
{
    FILE *fp;
    int i, temp;

    fp = fopen("zahlen.txt", "w");

    if (fp == NULL)
    {
        printf("Fehler!! :O");
    }
    else
    {
        /*schreibe zahlen*/
        for(i=0; i<10; i++)
        {
            fprintf(fp, "%d\n", i);
        }
        printf("Zahlen wurden geschrieben.\n");
        fclose(fp);
    }

    fp = fopen("zahlen.txt", "r");

    if (fp == NULL)
    {
        printf("Fehler...");
    }
    else
    {
        for (i=0; i < 10; i++)
        {
            fscanf(fp, "%d", &temp);
            printf("gelesen: %d\n", temp);
        }
        fclose(fp);
        
    }

    return 0;
}