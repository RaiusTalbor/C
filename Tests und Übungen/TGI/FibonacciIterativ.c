//Fibonacci

#include <stdio.h>
#include <math.h>

float fibo (float zahl);

int main(void)
{
	
	float zahl, gschnitt, ergebnis=1;
	
	printf("Fibo\n\n");
	
	printf("Zahl eingeben:");
	fflush(stdin);									//Speicher löschen
	scanf("%f", &zahl);
	
	ergebnis=fibo(zahl);
	
	gschnitt=ergebnis/fibo(zahl-1);
	
	printf("\nErgebnis: %f", ergebnis);
	printf("\nGoldener Schnitt: %f", gschnitt);

	return 0;	
}

float fibo (float zahl)
{
	float a, b, c, d, ergebnis;
	
	ergebnis = 1 / sqrt(5);
	a=(1+sqrt(5))/2;
	b=(1-sqrt(5))/2;
	c=pow(a, zahl);
	d=pow(b, zahl);
	ergebnis = ergebnis * (c-d);
	
	return ergebnis;
}
