/* C program to illustrate how to generate random number*/
/*withing a range*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	/* Set the upper bound for random numbers*/
	int upper_bound = 100;
	/* Set the lower bound for random numbers*/
	int lower_bound = 0;

	int i = 0;

	/*Loop through 10 times*/
	for (i; i < 10; i++) 
	{
		/* Generate a random number within the specified
		bounds;; Zufallszahl, Modulo sorgt dafür, dass die Zahl unter Obergrenze ist.
		Addition zur Untergrenze sorgt dafür, dass die Zufallszahl nie kleiner als lowerbound wird,
		da C nacheinander rechnet; Es muss am Anfang noch lowerbound vom Modulo abgezogen werden, weil am Ende ja noch
		lowerbound addiert wird*/
		int value = rand() % (upper_bound - lower_bound + 1)
					+ lower_bound;

		/*Print the generated random value*/
		printf("%d ", value);
	}

	return 0;
}
