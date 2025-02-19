#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch
#include <ctype.h> //toupper
/* 1.15 SI-konforme Umwandlung angloamerikanischer
Ma�einheiten
Das nachstehende Programm soll analog dem vorigen funktionieren.
Erweitern Sie das vorige Programm �ber die Knoten-Ma�einheiten, wobei die weiteren
angloamerikanische Ma�einheiten:
Zoll in cm,
- Fu� in dm,
- Yard in Meter,
- Meile in km,
- Ounces in Gramm,
- Pfund (lbs) in kg
umgerechnet werden.
Hinweis:
- Geben Sie das Ergebnis in tabellarischer Form unter Nutzung des Tabulators \t:
Nr. | Nichtmetrische Eingabe | Metrische (SI-)Eingabe!
Schreiben Sie ein kleines Men� (Kommandoeingabe) dazu, welches dem User erlaubt, die
Ma�einheiten zu w�hlen sowie mehrere Werte einzugeben! */

#define Wert_P2K 0.453592 //Pfund zu Kilogramm
#define Wert_M2Y 1.09361 // Meter zu Yard
#define Wert_C2Z 0.393701 // Centimeter zu Zoll
#define Wert_G2O 0.035274 // Gramm zu Ounce
#define Wert_I2J 0.621371 // Meilen zu Kilometer
#define Wert_F2D 3.048 // Fuss zu Dezimeter
#define Wert_V2V 1.852 // Knoten in km/h

//Prototypen
float K2P(float x);
float M2Y(float x);
float C2Z(float x);
float G2O(float x);
float I2J(float x);
float J2I(float x);
float F2D(float x);
float D2F(float x);
float V2V(float x);

//Umwandlung Kilogramm zu Pfund
float K2P(float x){ return(x*Wert_P2K); }
//Umwandlung Meter zu Yard
float M2Y(float x){ return(x*Wert_M2Y); }
//Umwandlung Centimeter zu Zoll
float C2Z(float x){ return (x*Wert_C2Z); }
//Umwandlung Gramm to Ounces
float G2O(float x){ return (x*Wert_G2O); }
//Umwandlung Meilen zu Kilometer
float I2J(float x){ return (x*Wert_I2J); }
//Umwandlung Kilometer zu Meilen
float J2I(float x){ return (x/Wert_I2J); }
//Umwandlung Fuss zu Dezimeter
float F2D(float x){ return (x*Wert_F2D); }
//Umwandlung Dezimeter zu Fuss
float D2F(float x){ return (x/Wert_F2D); }
//Umwandlung Dezimeter zu Fuss
float V2V(float x){ return (x*Wert_V2V); }


int main() 
{
	
	float x;
	char quelle, ziel;
	puts("Aufgabe 1.15");
	puts("Bist Du Si-konform?");
	puts("Umwandlung ins metrische System");
	puts("Autor: Pedro Suarez, Paul Zenker, Ben Kaiser");
	
	do 
	{
		printf("Bitte Wert eingeben | 0 - Exit: ");
		fflush(stdin);
		scanf("%f", &x);

		if(x==0.0) 
			return -1;

		printf("Bitte Ausgangs-Masseinheit eingeben (K-kg, F-Fuss, P-Pfund, M - Meter, C - cm, G - Gramm, V-Knoten)\n");
		quelle=toupper(getch());

		printf("Bitte Ziel-Masseinheit eingeben (Z-Zoll, Y-Yard, O-Ounce, I - Meile, J - Kilometer, V-km/h)\n");
		ziel=toupper(getch());
		
		if (quelle == 'K' && ziel== 'P')  
		{	
			printf("%.2f %c sind %.2f %c\n", x, quelle, K2P(x), ziel );
		}
		else if (quelle == 'M' && ziel== 'Y')  
		{	
			printf("%.2f %c sind %.2f %c\n", x, quelle, M2Y(x), ziel );
		}
		else if (quelle == 'C' && ziel== 'Z')  
		{	
			printf("%.2f %c sind %.2f %c\n", x, quelle, C2Z(x), ziel );
		}
		else if (quelle == 'G' && ziel== 'O')  
		{	
			printf("%.2f %c sind %.2f %c\n", x, quelle, G2O(x), ziel );
		}
		else if (quelle == 'I' && ziel== 'J')  
		{	
			printf("%.2f %c sind %.2f %c\n", x, quelle, I2J(x), ziel );
		}
		else if (quelle == 'J' && ziel== 'I')  
		{	
			printf("%.2f %c sind %.2f %c\n", x, quelle, J2I(x), ziel );
		}
		else if (quelle == 'F' && ziel== 'D')  
		{	
			printf("%.2f %c sind %.2f %c\n", x, quelle, F2D(x), ziel );
		}
		else if (quelle == 'D' && ziel== 'F')  
		{	
			printf("%.2f %c sind %.2f %c\n", x, quelle, D2F(x), ziel );
		}
		else if (quelle == 'V' && ziel== 'V')  
		{	
			printf("%.2f KT sind %.2f km/h\n", x, V2V(x));
		}
		else 
			puts("Falsche Eingabe der Einheiten!");
	}
	while(100);
	
	return 0;
}