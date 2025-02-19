//Fibonacci

#include <stdio.h>
#include <math.h>

int fibo (int zahl);

int main(void)
{
	
	int zahl, ergebnis=1;
	
	printf("Fibo\n\n");
	
	printf("Zahl eingeben:");
	fflush(stdin);									//Speicher l�schen
	scanf("%i", &zahl);
	
	ergebnis=fibo(zahl);
	printf("\nErgebnis: %i", ergebnis);

	return 0;	
}

int fibo (int zahl)
	{		
	if (zahl <= 1)
		return zahl;
	else
		return fibo (zahl-1) + fibo (zahl-2);	
	}
