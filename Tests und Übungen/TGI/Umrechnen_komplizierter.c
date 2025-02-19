/* Grad Celsius in Kelvin und Fahrenheit */

#include <stdio.h>	//Standard Ein-/Ausgabe

int main(void)
{
	
	float celsius, kelvin, fahrenheit;
	int wahl = 0;
	
	printf("Umrechnung von Grad Celsius in Kelvin oder Fahrenheit \n\n");
	
	printf("Bitte waehlen Sie: 0 fuer Kelvin oder 1 fuer Fahrenheit.");
	scanf("%d", &wahl);
	
	printf("Bitte Temperatur in Grad Celsius angeben: ");
	scanf("%f", &celsius);	
	//printf("Kontrollausgabe: %4.2f", celsius);
	
	
	if (wahl == 0)		//von C in K
	{
		kelvin = celsius + 273.15;

		printf("\nErgebnis in Kelvin: %4.2f", kelvin);
	}
	else					//von C in F
	{
		fahrenheit = celsius * 1.8 +32;
		//F nach C : (5.0/9.0) * (f-32.0)
	
		printf("\nErgebnis in Fahrenheit: %4.2f", fahrenheit);	
	}
	
	return 0;
}
