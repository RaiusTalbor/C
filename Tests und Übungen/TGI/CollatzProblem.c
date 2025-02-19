/*Collatz-Problem*/

#include <stdio.h>

int main (void)
{
    int zaehler=0, x=0, i=0;

    for (i; i<100; i++)
    {   
        x=i;
        zaehler=0;
        printf("\nx: %i", x);
        while(x > 1)
        {
            zaehler += 1;
            if(x % 2 != 0)
            {
                x = 3 * x + 1;
            }
            else
            {
                x = x / 2;
            }
            
        }
        printf("\nDie Anzahl der Schritte betrug: %d.", zaehler);
    }

    return 0;
}