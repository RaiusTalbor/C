/*1_11 Dateiarbeit
Rouven L. 3IT24-2*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    FILE *fp;
    float x=0;
    float erg[2];

    fp = fopen("lok.file", "w");

    if (fp == NULL)
    {
        printf("Die Datei konnte nicht geoeffnet werden!");
    }
    else
    {
        for (x; x<17; x++)
        {
            erg[0] = x * sin(x);
            erg[1] = x;
            printf("(%.3f, %.3f)\n", erg[1], erg[0]);
            fprintf(fp, "(%.3f, %.3f)\n", erg[1], erg[0]);
        }
        fclose(fp);
    }
    
    return 0;
}