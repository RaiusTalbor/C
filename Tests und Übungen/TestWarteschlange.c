/*Test*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
    int f, i, h = 2;

    typedef struct
    {
        int warteschlange[5];
    } Ort;
    Ort O[1];

    /*Initialisierung*/
    for (i = 0; i < 5; i++)
    {
        O[0].warteschlange[i] = 0;
        printf("%d\t", O[0].warteschlange[i]);
    }

    /*Zuweisung*/
    O[0].warteschlange[h] = 3;

    printf("\nh: %d\n", O[0].warteschlange[h]);

    /*Herausfinden*/
    for (f = 0; f < 5; f++)
    {
        printf("\nf: %d\n", f);

        if (O[0].warteschlange[f] != 0)
        {
            printf("%d\n", f);
            break;
        }
    }

    printf("f: %d\t angebliche Zahl: %d\t tatsaechliche Zahl: %d", f, O[0].warteschlange[f], O[0].warteschlange[h]);

    return 0;
}