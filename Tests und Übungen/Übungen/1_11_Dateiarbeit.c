/*1_11 Dateiarbeit
Rouven L. 3IT24-2*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    FILE *fp;
    float x=0, y=0;

    fp = fopen("log.file", "w");

    if (fp == NULL)
    {
        printf("Die Datei konnte nicht geoeffnet werden!");
    }
    else
    {
        for (x; x<17; x++)
        {
            y = x * sin(x);
            printf("x: %.3f y: %.3f\n", x, y);
            fprintf(fp, "x: %.3f y: %.3f\n", x, y);
        }
        fclose(fp);
    }
    
    return 0;
}