/*AckermannFunktion*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int m = 0, n = 0;

int a(m,n);

int main (void)
{
    for (m = 0; m < 5; m++)
    {
        for (n = 0; n < 5; n++)
        {
            printf("%d\t", a(m , n));
        }
        printf("\n");
    }
    
    return 0;
}

int a(m,n)
{
    if (m==0)
    {
        return n+1;
    }
    else if (n==0)
    {
        return a(m-1, 1);
    }    
    else
    {
        return a(m-1, a(m, n-1));
    }   
}