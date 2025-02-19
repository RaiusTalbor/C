#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
typedef struct 
{
  	char n[20];
  	char v[20];
  	char l[20];
  	char t[20];
} PERSON;

PERSON p[30];

int main(void) {
	char fname[] = "D:\\Workplace\\CSV-Data.txt";
	puts("2_10_CSV-Parser");
	FILE *file;
	char string[200] = "Kurt,Kanns;555678;DE";
	char delimiter[] = ".:,;_-\n ";
	char *ptr;
	
   file=fopen(fname, "r");
   if (file == NULL) {
       printf("Failed to open file.\n");
       return 1;
   }
   while (fgets(string, 180, file) != NULL) {
       printf("Ausgelesen: %s", string);
       
    //Parsing
	// initialisieren und ersten Abschnitt erstellen
	ptr = strtok(string, delimiter);
	
	while(ptr != NULL) {
		printf("Abschnitt gefunden: %s\n", ptr);
		// naechsten Abschnitt erstellen
	 	ptr = strtok(NULL, delimiter);
	}//Ende Parsing
   }//Ende der Filearbeit

   if (feof(file)) {
       printf("End of file reached.\n");
   } else if (ferror(file)) {
       printf("An error occurred.\n");
   }

	fclose(file);
	return 0;
}
