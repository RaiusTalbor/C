/*Summe aller Zahlen*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*wuerfeln()*/
int wuerfel(void)
{
    int wert;
    wert= 1+rand() % 6;
    return wert;
}

int main(void)
{
    int anzahl6, summe;
    int i = 0;
    int anz = 0;
    int wert;

    srand(time(NULL));

    puts("Anzahl 6: ");
    fflush(stdin);
    scanf("%d", &anzahl6);

    do
    {
        wert=wuerfel();
        printf("%d\t", wert);
        if (wert!=6)
        {
            anz++;
        }
    } while (anz != anzahl6);

    summe = 6 * anz;

    puts(" ");
    printf("Summe aller 6er: %d\n", summe);
    printf("Summe aller Versuche: %d", anz);
    

}