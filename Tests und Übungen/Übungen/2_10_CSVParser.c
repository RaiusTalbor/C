/*Programmname
und was es tut*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main (void)
{
    char fname[] = "CSV-Data.txt";
    FILE *f;

    char string[] = "Kurt,Kanns;555678;DE";
    char delimiter[] = ",;";
    char *ptr;

    fopen(fname, "r");

    if(f==NULL) return -1;

    /*Parsing*/

    /*Teilen Datei auf Tokens, ordnen sie neu*/

    // initialisieren und ersten Abschnitt erstellen
    ptr = strtok(string, delimiter);

    while(ptr != NULL) {
	    printf("Abschnitt gefunden: %s\n", ptr);
	    // naechsten Abschnitt erstellen
 	    ptr = strtok(NULL, delimiter);
    }

    return 0;
}