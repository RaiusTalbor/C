/*Fleissiger Bieber*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main (void)
{
    int i;  /*Zählvariable*/
    int z = 1;  /*Zustände*/
    int a;  /*aktuelle Position*/
    int band[30];   /*das "endlose" Band*/
    int zaehler = 0;    /*Zähler*/

    a = 10; /*Startposition*/

    for (i = 0; i < 30; i++)
    {
        band[i] = 0;
    }

    do
    {
        zaehler += 1;

        switch (z)
        {
        case 0:
            break;
        case 1:
            if (band[a] == 0)
            {
                band[a] = 1;
                a += 1;
                z = 2;
            }
            else
            {
                band[a] = 1;
                a -= 1;
                z = 3;
            }
            
            break;
        case 2:
            if (band[a] == 0)
            {
                band[a] = 1;
                a -= 1;
                z = 1;
            }
            else
            {
                band[a] = 1;
                a += 1;
                z = 2;
            }
            break;
        case 3:
            if (band[a] == 0)
            {
                band[a] = 1;
                a -= 1;
                z = 2;
            }
            else
            {
                band[a] = 1;
                a -= 1;
                z = 0;
            }
            break;

        default:
            break;
        }

    printf("\nZaehler: %d\tZustand: %d\n", zaehler, z);

    for (i = 0; i < 30; i++)
    {
        printf("| %d ", band[i]);
    }

    printf("|");

    } while (z != 0);
    
    return 0;
}