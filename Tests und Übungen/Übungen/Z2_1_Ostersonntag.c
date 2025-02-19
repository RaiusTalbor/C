/*Z2.1 Ostersonntag
Rouven 3IT24-2*/

/*GÜLTIGKEIT 1900-2099*/

#include <stdio.h>
#include <math.h>

int main (void)
{
    int jahr, a, b, n, m, q, w, p;

    puts("Z2.1 Ostersonntag berechnen");

    do
    {
        printf("Geben Sie eine Jahreszahl ein: ");
        fflush(stdin);
        scanf("%d", &jahr);
    } while (jahr < 1900 || jahr > 2099);

    n = jahr - 1900;
    a = n % 19;
    b = ((7*a + 1)/19);
    m = (11*a+4-b)%29;
    q = (n / 4);
    w = (n + q + 31 - m) % 7;
    p = 25 - m - w;

    if (p>0)
    {
        printf("Der Ostersonntag ist der %d. April %d.", p, jahr);
    }
    else
    {
        p = p + 31;
        printf("Der Ostersonntag ist der %d. Maerz %d.", p, jahr);
    }

    return 0;
}