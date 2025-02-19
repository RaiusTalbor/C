#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ABS(x) ((x)<0? -(x):(x))
#define EPS 0.000001
#define PI 3.1415926535

double EXPO(double x);
double SINU(double x);

/* MacLaurenische Annaeherung sin() */
double SINU(double x)
{
	int i;
	double summe = x, glied=x;
	
	for(i=3; ; i+=2)
	{
		glied *=((x*x) / (i*(i-1)));
		glied = -glied;
		if (ABS(glied) <= EPS) break;
		summe += glied;
		/*printf("Summe = %lf\n", summe);*/
	}
	return summe;
}

/* MacLaurensche Ann�herung exp() */
double EXPO(double x)
{
	int i;
	double summe = 1 + x, glied=x;
	
	for(i=2; ; i++)
	{
		glied *= x/i;
		if (glied <= EPS) break;
		summe += glied;
		/*printf("Summe = %lf\n", summe);*/
	}
	return summe;
}

int main() {
	double x;
    int ausgabe;
	
	puts("1_10 Mclauren-Reihen");

    printf("0 fuer Exponentialfkt.\n1 fuer Sinusfkt.\nEingabe: ");
	fflush(stdin);
	scanf("%d", &ausgabe);

    printf("Bitte Argument eingeben: ");
	fflush(stdin);
	scanf("%lf", &x);

    if (ausgabe==0)
    {
        printf("Argument: %.3lf | STD-      Funktion exp(): %.3lf\n", x, exp(x));
	    printf("Argument: %.3lf | Userspez.-Funktion exp(): %.3lf\n", x, EXPO(x));	
    }
    else
    {
        printf("Argument: %.3lf | STD-      Funktion sin(): %.3lf\n", x, sin(x));
	    printf("Argument: %.3lf | Userspez.-Funktion sin(): %.3lf\n", x, SINU(x));	
    }

	return 0;
}
