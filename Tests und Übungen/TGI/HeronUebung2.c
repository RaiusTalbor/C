/*Heron V0.0.1
Rouven J. Lacour, s3005525, 3IT24-2*/

/*zeichnet und schmückt einen Tannenbaum*/

/*Einfügen der Standardbibliotheken*/
#include <stdio.h>
#include <stdlib.h>

#define GENAUIGKEIT 0.0000001

int main (void)
{
    float x, y, hilf;

    /*Eingabe der Zahl*/
    puts("Geben Sie eine Zahl ein: ");
    fflush(stdin);
    scanf("%f", &hilf);

    x = hilf;
	y=1.0;
	
    /*Eigentliches Verfahren*/
	while ((x-y) > GENAUIGKEIT)
	{
		x = (x+y)/2;
		y = hilf/x;
		//printf("\nx= %f y=%f Zahl=%f", x, y, zahl);
	}	

    printf("%f", x);

    return 0;    
}