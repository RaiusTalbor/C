//Fakult�t

#include <stdio.h>
#include <math.h>

int fakultaet (int zahl);

int main(void)
{
	
	int zahl, i, ergebnis=1;
	
	printf("Fakult�t\n\n");
	
	printf("\nZahl eingeben:");
	fflush(stdin);									//Speicher l�schen
	scanf("%i", &zahl);
	

		ergebnis=ergebnis*i;		
	}	for (int i=2; i <= zahl; i++)
	{
	
	printf("\nErgebnis: %i", ergebnis);
	
	ergebnis=fakultaet(zahl);
	printf("\nErgebnis: %i", ergebnis);

	return 0;	
}

int fakultaet (int zahl)
	{
	
	/*
	zahl=zahl*(zahl-1);
	
	if (zahl<2)
		zahl=fakultaet(zahl);
	else
		;	
	*/
		
	if (zahl < 2) return 1;
	return zahl*fakultaet(zahl-1);
	
	return zahl;
	
	}
	

