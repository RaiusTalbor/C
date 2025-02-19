/*Osterdatum*/

#include <stdio.h>

int main(void)
{
	
	int jahreszahl, a, b, c, d, e, ergebnis ;
	
	printf("Geben Sie eine Jahreszahl ein, fuer die der Ostersonntag berechnet werden soll:");
	scanf("%i", &jahreszahl);
	
	a = jahreszahl%19;
	b = jahreszahl%4;
	c = jahreszahl%7;
	
	d = (19*a+24)%30;
	e = (2*b+4*c+6*d+5)%7;
	
	if (22+d+e>31)
	{
		ergebnis =d+e-9;
		printf("Der Ostersonntag ist am %i April %i.", ergebnis, jahreszahl);
	}
	else
		{
		ergebnis = 22+d+e;
		printf("Der Ostersonntag ist am %i Maerz %i.",ergebnis, jahreszahl);
	}
	
}
