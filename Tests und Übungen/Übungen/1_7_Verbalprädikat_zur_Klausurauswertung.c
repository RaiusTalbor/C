/*1_7_Verbalprädikat_zur_Klausurauswertung
Rouven Lacour, 3IT24-2, s3005525*/

#include <stdio.h>

int main (void)
{
    int punkte, ende=0;

    printf("1_7_Ausgabe der Notenpunkte mit Woertern.\n\n");

    do
    {
        printf("\nGeben Sie die Punkte an, die der oder die Schueler*in erreicht hat: ");
        fflush(stdin);
        scanf("%i", &punkte);

        if (punkte<50)
        {
            if (punkte == 1)
                printf("%i Punkt ist ungenuegend.\n", punkte);
            else
                printf("%i Punkte sind ungenuegend.\n", punkte);
        }
        else if (punkte<61)
        {
            printf("%i Punkte sind ausreichend.\n", punkte);
        }
        else if (punkte<76)
        {
            printf("%i Punkte sind befriedigend.\n", punkte);
        }
        else if (punkte<97)
        {
            printf("%i Punkte sind gut.\n", punkte);
        }
        else
        {
            printf("%i Punkte sind sehr gut.\n", punkte);
        }

        printf("\nWenn Sie das Programm beenden wollen und keinen weiteren Schueler abfragen moechten, druecken Sie 1.\nSonst druecken Sie eine beliebige Taste.");
        fflush(stdin);
        scanf("%i", &ende);
    } while (ende != 1);
    

    return 0;
}