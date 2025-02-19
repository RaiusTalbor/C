/*1_11 Dateiarbeit
Rouven L. 3IT24-2*/

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int i;
    float x=0;
    int temp[3];

    fp = fopen("loc.file", "w");

    if (fp == NULL)
    {
        printf("Die Datei konnte nicht geoeffnet werden!");
    }
    else
    {
        fprintf(fp, "Finn");

        fclose(fp);

        fp = fopen("loc.file", "r");
        for (i = 0; i < 4; i++)
        {
            fscanf(fp, "%d", &temp[i]);
            printf("%c", temp[i]);
        }

        fclose(fp);
    }
    
    return 0;
}