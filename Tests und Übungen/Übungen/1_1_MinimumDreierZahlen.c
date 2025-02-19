/*1_1_MinimumDreierZahlen
Rouven J. Lacour, 3IT24, s3005525*/

#include <stdio.h>

int main (void)
{
    float a,b,c,kleiner, gleichheit;

    /*Gleichheit: 0=Nein, 1=ab, 2=bc, 3=ac, 4=abc*/

    puts("1_1_Minimum dreier Zahlen\n");

    printf("Geben Sie die erste Zahl ein: ");
    fflush(stdin);
    scanf("%f", &a);

    printf("Geben Sie die zweite Zahl ein: ");
    fflush(stdin);
    scanf("%f", &b);

    printf("Geben Sie die dritte Zahl ein: ");
    fflush(stdin);
    scanf("%f", &c);

    /*Prüfen auf Gleichheit*/

    if (a==b)
    {
        gleichheit = 1;
    }
    if (b==c)
    {
        gleichheit = 2;
    }
    if (a==c)
    {
        gleichheit = 3;
    }
    if (a==b && a==c)
    {
        gleichheit = 4;
    }

    if (gleichheit != 4)
    {
        if (a<=b)
        {
            kleiner = a;
        }
        else
        {
            kleiner = b;
        }
        if (c<=kleiner)
        {
            kleiner = c;
        }

        printf("Die kleinste Zahl ist %f.", kleiner);
        

    }
    else
    {
        puts("Jede Zahl ist gleich groß. Es gibt kein Minimum.");
    }

    return 0;
}