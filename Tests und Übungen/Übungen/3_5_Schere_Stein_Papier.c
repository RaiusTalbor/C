#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
	
	int score1, score2, choice1, choice2, maxPunkte;
	char player1[100], player2[100];
	char wahl1[20], wahl2[20];
	char *zeichen[] = { "Stein", "Schere", "Papier", NULL };
	srand(time(NULL));
	
	printf("Bitte den Namen von Player 1 eingeben: ");
	fflush(stdin);
	scanf("%s", player1);
	
	printf("Bitte den Namen von Player 2 eingeben: ");
	fflush(stdin);
	scanf("%s", player2);
	
	do
	{  score1 = 0; score2 = 0; 
    puts("Noch einmal?");
	printf("Bitte max. Punktestand eingeben, 0 - terminiere ... -> ");
	fflush(stdin);
	scanf("%d", &maxPunkte);
	if(maxPunkte==0) return -1;
	printf("Das Spiel dauert bis %d Punkte!\n ", maxPunkte);
	
	do {
		//Werfen f�r Player 1
		choice1 = rand() % 3; //Stein (0), Schere (1), Papier (2)
		strcpy(wahl1, zeichen[choice1]); 
		
		//Werfen f�r Player 2
		choice2 = rand() % 3; //Stein (0), Schere (1), Papier (2)
		strcpy(wahl2, zeichen[choice2]);
		
		printf("|%20s %10s| %20s %10s|\n", player1, wahl1, player2, wahl2); 
		
		if (choice1==choice2) puts("Unentschieden!");
		else if ((choice1==0) && (choice2==1) ||
				(choice1==1) && (choice2==2) ||
				(choice1==2) && (choice2==0)) 
				 {
				   score1 ++; puts("Game Player 1!"); 
				 }
			else {
				   score2 ++; puts("Game Player 2!"); 
				 }
		printf("Score: %d| %d\n", score1, score2);
		//soll das Spiel weiter gemacht werden.
		if (score1 >= maxPunkte) break;
		if (score2 >= maxPunkte) break;
		
	  } while(1);
	
    }while(2); //noch einmal?
	return 0;
}
