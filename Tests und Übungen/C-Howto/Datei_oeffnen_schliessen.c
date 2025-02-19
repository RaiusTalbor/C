/*Datei_oeffnen_schliessen C-howto.de
Rouven 3IT24-2*/

#include <stdio.h>

int main (void)
{
    FILE *fp;

    fp = fopen("abc.txt", "r");

    if(fp == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden.");
    }
    else
    {
        printf("Erfolg!!");
        fclose(fp);
    }

    return 0;
}