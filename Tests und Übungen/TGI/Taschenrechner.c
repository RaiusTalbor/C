//Taschenrechner

#include <stdio.h>
#include <math.h>

int main(void)
{
	
	float op1, op2, ergebnis; 	//operand 1,2..
	int mop1, mop2, mergebnis;
	char operator;
	
	printf("Taschenrechner\n\n");
	

	printf("Geben Sie ein:\n+ fuer Addition\n- fuer Subtraktion\n* fuer Multiplikation\n/ fuer Division\nw fuer Quadratwurzel\nm fuer Modulo\n\nEingabe:");
	scanf("%c", &operator);
	//hier schon abfangen??
		
	
	if (operator!='m')			
		{
		printf("\nOperand 1: ");
		scanf("%f", &op1);
		}
	
	if (operator!='w')
		{			
		if  (operator!='m')
			{
			printf("\nOperand 2: ");
			scanf("%f", &op2);
			}
		else
			;
		}
	else
		{
		op2='1';
		}
		
	//Prüfung, welche Operanden nötig sind

	
	switch(operator)
	{
		
		case '+':
			ergebnis = op1 + op2 ;
			break;
			
		case '-':
			ergebnis = op1 - op2 ;
			break;
			
		case '*':
			ergebnis = op1 * op2 ;
			break;
			
		case '/':
			if (op2==0)				
				{
				printf("\nDivision durch 0 ist nicht erlaubt. Mathematischer Fehler!");
				}
			else
				{
				ergebnis = op1 / op2 ;
				printf("\n\n%f %c %f = %f", op1, operator, op2, ergebnis);
			   }
				
			break;
			
		case 'm':
			printf("\nOperand 1: ");
			scanf("%i", &mop1);
		
			printf("\nOperand 2: ");
	   	scanf("%i", &mop2);
			mergebnis = mop1 % mop2 ;
			break;		
			
		case 'w':
			if (op1<0)
				printf("\nWurzel von negativen Zahlen ist nicht erlaubt. Mathematischer Fehler!");
			else
				ergebnis = sqrt(op1) ;
				printf("\n\nDie Wurzel von %f betraegt %f.", op1, ergebnis);
			break;
			
		default:
			printf("Falsche Eingabe!");
			
	//eigentliche Berechnung mit Sonderfällen
		
	}
	
	switch (operator)
		{
		case 'w':
			break;		
		case 'm':
			printf("\nDer Rest der Division von %i/%i betraegt %i .", mop1, mop2, mergebnis);
			break;
		case '/':
			break;
			
		default:
			printf("\n\n%f %c %f = %f", op1, operator, op2, ergebnis);
		}
		
	//Ergebnisausgabe
	
	return 0;
			
	
}
