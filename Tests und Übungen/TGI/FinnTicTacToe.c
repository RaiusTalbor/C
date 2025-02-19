/*Tic Tac Toe von Finn*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spielfeld();
int pruefeGewinn();
int computer();

int beginner = 0;
int feld;
int zaehlen = 0;
int zufall = 0;
int hilf = 0;

char hilf1 = 'x';
char hilf2 = 'o';
char ooderx = 'x';
char vierzehn = ' ';
char fuenfzehn = ' ';
char sechzehn = ' ';
char vierundzwanzig = ' ';
char fuenfundzwanzig = ' ';
char sechsundzwanzig = ' ';
char vierunddreissig = ' ';
char fuenfunddreissig = ' ';
char sechsunddreissig = ' ';


int main() {


	printf("Hallo und wilkommen zu meinem Tic Tac Toe Spiel!\n\n");

	spielfeld();

	printf("Es gibt zwei Spieler: Spieler 1 mit x und Spieler 2 mit o. Legen Sie bitte fest, wer von Ihnen welcher Spieler ist.\nSpieler 1 beginnt.\n\n");



	while (pruefeGewinn() == 0) {


		if (ooderx == 'x') {

			printf("In welches Feld wollen Sie setzen? Schreiben sie ohne Leerzeichen und beginnen Sie mit der kleineren Zahl, beispw. 25:\n");

			scanf("%i", &feld);
		}    

		switch (feld) {
		case 14:

			if (vierzehn == ' ') {

				vierzehn = ooderx;

				ooderx = hilf2;
				hilf2 = hilf1;
				hilf1 = ooderx;

				spielfeld();
				zaehlen = zaehlen + 1;

				break;
			}


			break;
		case 15:

			if (fuenfzehn == ' ') {

				fuenfzehn = ooderx;

				ooderx = hilf2;
				hilf2 = hilf1;
				hilf1 = ooderx;

				spielfeld();
				zaehlen = zaehlen + 1;

				break;
			}

			break;
		case 16:

			if (sechzehn == ' ') {

				sechzehn = ooderx;

				ooderx = hilf2;
				hilf2 = hilf1;
				hilf1 = ooderx;

				spielfeld();
				zaehlen = zaehlen + 1;

				break;
			}

			break;
		case 24:

			if (vierundzwanzig == ' ') {

				vierundzwanzig = ooderx;

				ooderx = hilf2;
				hilf2 = hilf1;
				hilf1 = ooderx;

				spielfeld();
				zaehlen = zaehlen + 1;

				break;
			}

			break;
		case 25:

			if (fuenfundzwanzig == ' ') {

				fuenfundzwanzig = ooderx;

				ooderx = hilf2;
				hilf2 = hilf1;
				hilf1 = ooderx;

				spielfeld();
				zaehlen = zaehlen + 1;

				break;
			}

			break;
		case 26:

			if (sechsundzwanzig == ' ') {

				sechsundzwanzig = ooderx;

				ooderx = hilf2;
				hilf2 = hilf1;
				hilf1 = ooderx;

				spielfeld();
				zaehlen = zaehlen + 1;

				break;
			}

			break;
		case 34:

			if (vierunddreissig == ' ') {

				vierunddreissig = ooderx;

				ooderx = hilf2;
				hilf2 = hilf1;
				hilf1 = ooderx;

				spielfeld();
				zaehlen = zaehlen + 1;

				break;
			}

			break;
		case 35:

			if (fuenfunddreissig == ' ') {

				fuenfunddreissig = ooderx;

				ooderx = hilf2;
				hilf2 = hilf1;
				hilf1 = ooderx;

				spielfeld();
				zaehlen = zaehlen + 1;

				break;
			}

			break;
		case 36:

			if (sechsunddreissig == ' ') {

				sechsunddreissig = ooderx;

				ooderx = hilf2;
				hilf2 = hilf1;
				hilf1 = ooderx;

				spielfeld();
				zaehlen = zaehlen + 1;

				break;
			}

			break;

		default:
			printf("Falsche Eingabe!\n\n");

		}

        

		computer();

		if (pruefeGewinn()) {

			ooderx = hilf2;
			hilf2 = hilf1;
			hilf1 = ooderx;

			printf("Spieler %c hat gewonnen!\n", ooderx);
		}

		if (zaehlen == 9 && pruefeGewinn == 0) {

			printf("Unentschieden. Niemand hat gewonnen.");

			break;
		}
		
	}

	return 0;
}



void spielfeld() {
	printf("    1   2   3 \n");
	printf(" 4  %c | %c | %c \n", vierzehn, vierundzwanzig, vierunddreissig);
	printf("   ---+---+---\n");
	printf(" 5  %c | %c | %c \n", fuenfzehn, fuenfundzwanzig, fuenfunddreissig);
	printf("   ---+---+---\n");
	printf(" 6  %c | %c | %c \n\n", sechzehn, sechsundzwanzig, sechsunddreissig);
}


int pruefeGewinn() {
	// Zeilen prüfen
	if ((vierzehn == fuenfzehn && fuenfzehn == sechzehn && vierzehn != ' ') ||
		(vierundzwanzig == fuenfundzwanzig && fuenfundzwanzig == sechsundzwanzig && vierundzwanzig != ' ') ||
		(vierunddreissig == fuenfunddreissig && fuenfunddreissig == sechsunddreissig && vierunddreissig != ' ')) {
		return 1;
	}
	// Spalten prüfen
	if ((vierzehn == vierundzwanzig && vierundzwanzig == vierunddreissig && vierzehn != ' ') ||
		(fuenfzehn == fuenfundzwanzig && fuenfundzwanzig == fuenfunddreissig && fuenfzehn != ' ') ||
		(sechzehn == sechsundzwanzig && sechsundzwanzig == sechsunddreissig && sechzehn != ' ')) {
		return 1;
	}
	// Diagonalen prüfen
	if ((vierzehn == fuenfundzwanzig && fuenfundzwanzig == sechsunddreissig && vierzehn != ' ') ||
		(sechzehn == fuenfundzwanzig && fuenfundzwanzig == vierunddreissig && sechzehn != ' ')) {
		return 1;
	}

	return 0;
}

int computer() {
    
    int zufall[8] = { 14, 15, 16, 24, 25, 26, 34, 35, 36 };

	srand(time(NULL));

	hilf = zufall[rand() % 9];

	feld = hilf;

	return feld;


}