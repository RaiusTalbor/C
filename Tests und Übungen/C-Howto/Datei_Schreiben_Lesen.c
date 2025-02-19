/*Schreiben und lesen*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
    FILE *fp;
    int i, temp;

    fp = fopen("abc.txt", "w");

    if (fp ==NULL)
    {
        printf("Datei konnte nicht gelsen werden!");
    }
    else
    {
        for (i=0; i<26; i++)
        {
            fputc(i+65, fp); /*file put char*/
        }
        fputc(10, fp); /*Zeilenumbruch*/
        fclose(fp);
        
    }

    fp = fopen("abc.txt", "r");

    if (fp == 0)
    {
        printf("Datei konnte nicht geoeffnet werden!");
    }
    else
    {
        while( (temp=fgetc(fp)) != EOF) /*Solange das ausgelesene Zeichen kein End of File ist, tue das:*/
        {
            printf("%c", temp);
        }
        fclose();
    }
        

    return 0;
}