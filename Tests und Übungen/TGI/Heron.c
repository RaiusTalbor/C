//Heron

#include <stdio.h>
#include <math.h>

float heron (float zahl);						//Deklaration; Prototyp

int main(void)
{
	
	float zahl, ergebnis;
	
	printf("Heronverfahren\n\n");
	
	printf("\nZahl eingeben:");
	fflush(stdin);									//Speicher l�schen
	scanf("%f", &zahl);
	
	ergebnis = heron(zahl);						//Aufruf
	
	printf("\nErgebnis: %f", ergebnis); 

	return 0;	
}

float heron (float zahl)						//Definition
	{
	//Heron-Algorithmus

	float x,y;

	x = zahl;
	y=1.0;

	do
	{
		x = (x+y)/2;
		y = zahl/x;
		//printf("\nx= %f y=%f Zahl=%f", x, y, zahl);
	}
	while ((x-y) > 0.00000001);
		
	return x;
	}
