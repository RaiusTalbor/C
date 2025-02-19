#include <stdio.h>
#include <time.h>
#define MAX 200
//Prototypen
void generiere(double *, int);
void bubbleSort(double *, int);
void drucke(double *, int);
int datei(double *, int, char *);
int datei_bin(double *, int , char *);
/*1.24 Sortiere ein Zufallsarray mit reellen Zahlen
Schreiben Sie C- Programm mit einer Funktion, welche ein mit Zufallszahlen zwischen 1.0 und 100.0
belegtes double-Feld X (mindestens 50 Feldelemente) nach dem Bubble-Sort-Verfahren sortiert.
Hinweis:
Nutzen Sie die vorgefertigte Prozedur BubbleSort() in Pseudsprache
und passen Sie diese an als
void bubble_double (double *Array, int Grenze);
Erweitern Sie das Programm, indem Sie in der Funktion main() das Feld X vor und nach der
Sortierung in tabellarischer Form ausgeben.
Nutzen Sie printf() mit dem Zeichen \t als Tabulator.*/

int main (void){
	char fn[] = "D:\\Workplace\\ARRAY.log"; //eine String mit NULL als Begrenzer zus‰tzlich!
	char fnb[] = "D:\\Workplace\\ARRAY.bin"; //eine String mit NULL als Begrenzer zus‰tzlich!
	
	puts("Lennart, Aufgabe 1.24 Zufallsarray");
	double a[MAX];
	int i;
	srand(time(NULL));
	
	puts("\nArray unsortiert");
	generiere(a, MAX);
	drucke(a, MAX);
	
	puts("\nArray sortiert");
	bubbleSort(a, MAX);
	drucke(a, MAX);
	
	printf("\nSchreibe in die ASCII-Datei: "); 
	puts(fn);
	datei(a, MAX, fn);
	
	printf("\nSchreibe in die Binaer-Datei: "); 
	puts(fnb);
	datei_bin(a, MAX, fnb);
	
	return 0;
}

/*bubbleSort*/
void bubbleSort(double *A, int size)
{
	int n, i;
	double tmp;
  for (n = size; n > 1; n = n - 1) { // ‰uﬂere Schleife
    for (i = 0; i < n - 1; i = i + 1) { // innere Schleife
      if (A[i] > A[i + 1]) {
        //A.swap(i, i + 1)
        tmp = A[i];
        A[i] = A[i+1];
        A[i+1] = tmp; 
      }//if
    } //i
  }//for n
}//bubbleSort

/*print Array*/
void drucke(double *p, int anz){
	int i;
	for(i = 0; i < anz; i++)
	{
		printf("%.2lf\t", p[i]);	
	}
}

/*erzeuge Array*/
void generiere(double *p, int anz){
	int i;
	for(i = 0; i < anz; i++)
	{
		p[i] = (rand() % 10000 + 100)/100.;	
	}
}

/*Schreibe in ASCII-Datei*/
int datei(double *p, int anz, char *fname)
{
	int i;
	FILE *f; /*Zeiger auf eine Datei*/
	f = fopen(fname, "w");
	if(f==NULL) 
	{
		puts("Datei wurde nicht geoeffnet...");
		return -1;
	}
	//die Datei wurde erfolgreich geoeffnet

	for(i = 0; i < anz; i++)
	{
		fprintf(f, "%.2lf\t", p[i]);	
	}	
	
	
	fclose(f);
	return 0;
}

/*Schreibe in Binaer-Datei*/
int datei_bin(double *p, int anz, char *fname)
{
	int i;
	FILE *f; /*Zeiger auf eine Datei*/
	f = fopen(fname, "w");
	if(f==NULL) 
	{
		puts("Datei wurde nicht geoeffnet...");
		return -1;
	}
	//die Datei wurde erfolgreich geoeffnet
	fwrite(p, sizeof(double), anz, f);
	
	/*for(i = 0; i < anz; i++)
	{
		fwrite(p, sizeof(double), 1, f);		
	}*/	
	
	fclose(f);
	return 0;
}
