/* Grad Celsius in Kelvin und Fahrenheit */

#include <stdio.h>	//Standard Ein-/Ausgabe

int main(void)
{

	float celsius, kelvin, fahrenheit;

	printf("Umrechnung von Grad Celsius in Kelvin und Fahrenheit \n\n");

	printf("Bitte Temperatur in Grad Celsius angeben: ");
	scanf("%f", &celsius);
	//printf("Kontrollausgabe: %4.2f", celsius);

	kelvin = celsius + 273.15;		//Zuweisung

	printf("\nErgebnis in Kelvin: %4.2f", kelvin);

	fahrenheit = celsius * 1.8 +32;
	//F nach C : (5.0/9.0) * (f-32.0)

	printf("\nErgebnis in Fahrenheit: %4.2f", fahrenheit);

	return 0;
}
