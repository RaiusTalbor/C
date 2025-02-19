/*1.10 Maclaurinische Reihen
Rouven J. Lacour 3IT24-2*/

/*FUNKTIONIERT NICHT!!!*/

#include <stdio.h>
#include <math.h>

double Potenz(double basis, double potenz);
int Fakultaet(int zahl);

int main (void)
{
    int auswahl, n; /*n ist Genauigkeit*/
    double x, erge=0.0, hilf1, hilf2, hilf3, vergleich;

    puts("1.10 Maclaurinische Reihe");

    printf("0 fur Exponentialfunktion\n1 fuer Sinusfunktion\nIhre Auswahl: ");
    fflush(stdin);
    scanf("%i", &auswahl);

    printf("Eingabe fuer x: ");
    fflush(stdin);
    scanf("%lf", &x);

    if (auswahl==0)
    {
        /*Exponentialfunktion*/
        for (n=0; n<=20; n++)
        {
            hilf1=Potenz(x, (double)n);
            hilf2=(double)Fakultaet(n);
            erge=erge+(hilf1/hilf2);
            /*printf("(%lf ^ %d)/ %d ! = %lf\n", x, n, n, hilf1/hilf2);*/
        }
        erge+=1;
        vergleich=exp(x);
    }  
    else
    {
        /*Sinusfunktion*/

        for (n=0; n<=10; n=n+2)
        {
            hilf1=Potenz((-1), (double)n);
            hilf2=Potenz(x, (double)((2*n)+1));
            hilf3=Fakultaet((2*n)+1);
            erge=erge+(hilf1*(hilf2/hilf3));
        }
        vergleich=sin(x);
    }

    printf("Berechnet: %f | Math: %f", erge, vergleich);

    return 0;
}

double Potenz (double basis, double potenz)
{
    double erg;

    erg = basis;

    if (potenz >= 2)
    {
        for (potenz; potenz >= 2; potenz--)
        {
            erg = erg * basis;
        }

    return erg;
    }
    else
        return 1;

    
}

int Fakultaet(int zahl)
{
    if (zahl>1)
        zahl=zahl*(Fakultaet(zahl-1));
    else
        zahl=1;

    return zahl;
}