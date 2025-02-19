/*1_23 Schaltjahre
Rouven Lacour, 3IT24-2*/

#include <stdio.h>

int schaltjahr(int jahr); /*0 falsch, 1 richtig*/

int schaltjahr(int jahr)
{
    int div4, jahrhundert, div400;

    div4 = jahr % 4 == 0;
    jahrhundert = jahr % 100 != 0;
    div400 = jahr % 400 == 0;

    if (jahr < 0)
    {
        perror("Jahr kann nicht negativ!!");
    }

    return (div4 && (jahrhundert || div400));
}

int main (void)
{
    int jahr;

    puts("1.23 Schaltjahr berechnen");

    do
    {   

    printf("Jahr eingeben | 0 - Exit: ");
    fflush(stdin);
    scanf("%d", &jahr);

    if (!jahr)
        return -1;

    if (schaltjahr(jahr)   )
        printf("Jahr %d ist ein Schaltjahr!\n", jahr);
    else
        printf("Jahr %d ist kein Schaltjahr!\n", jahr);

    } while (100);

    return 0;
}