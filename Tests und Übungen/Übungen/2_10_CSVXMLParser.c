#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 /*maximale Anzahl an Einträgen*/

typedef struct {
 	char Vorname [50];
	char Name [50];		 
	char Phone [20]; 
	char Land [4];
 } Eintrag;

Eintrag a [MAX];

/*Prototypen*/
int PrintAll(Eintrag *array, int anz);	/*druckt alle Profile in Konsole*/
int PrintAll_in_XML(Eintrag *array, int anz, char *fn); /*druckt alle Profile in XML-Datei*/

int main(void) {
	int i=0, counter;
	char string[105] = "Kurt,Kannsnicht;5556789;DE"; /*Wofür??*/
	char delimiter[] = ",;:_ \n\t";
	char *ptr;
	char fn[] = "Parser.txt"; /*Inputdatei*/      
	char fn_XML[] = "Parserdatei.XML"; /*Outputdatei*/

	FILE *fp;
	
	/*Datei oeffnen - liest Profile aus txt aus*/
	fp = fopen(fn, "r");
	if(fp == NULL) {
		printf("Datei %s konnte NICHT geoeffnet werden.\n", fn);
		return -1;
	} 

	printf("Datei %s konnte geoeffnet werden.\n", fn);

    while( fgets (string, 80, fp)!=NULL ) 
	{ /*lese bis EOF*/

		counter = 0;
    	puts(string);

   		/*Parsing
		initialisieren und ersten Abschnitt erstellen*/
		ptr = strtok(string, delimiter);

		while(ptr != NULL) 
		{
			printf("%d. Abschnitt gefunden: %s\n", ++counter, ptr);
		
			switch(counter) /*Counter zeigt an, wievieltes Element --> deswegen weiß ich wo was*/
			{
				case 1:
					strcpy(a[i].Vorname, ptr); /* .Vorname wegen Struct; packt das an diese Stelle*/
					break;
				case 2:
					strcpy(a[i].Name, ptr);
					break;
				case 3:
					strcpy(a[i].Phone, ptr);
					break;
				case 4:
					strcpy(a[i].Land, ptr);
					break;
			}
			/*naechsten Abschnitt erstellen*/
	 		ptr = strtok(NULL, delimiter);
	  	}
		/*while fuer ein element*/
	  	i++; /*String wurde eingelesen und geparst;; i steht für den so und so vielten struct, der gespeichert wurde*/
	}/*while fuer Datei*/

	printf("Datei %s enthaelt %d Eintraege", fn, i);
	fclose(fp);

	/*Drucke alle Einträge aus dem Array of Struct*/
	PrintAll(a, i);
	PrintAll_in_XML (a, i, fn_XML);

	return 0;
}

int PrintAll_in_XML(Eintrag *array, int anz, char *fn)
{
	FILE *fp;
	int i;
	
	fp = fopen(fn, "w");
	if(fp == NULL) {
		printf("Datei %s konnte NICHT geoeffnet werden.\n", fn);
		return -1;
	} 	

	for (i=0; i<anz; i++) {
		if(array[i].Phone) /*irgendwas, hauptsache Eintrag existiert*/
        {
			fprintf (fp, "<PERSON># %d\n", i+1);
			fprintf (fp, "	<NAME>%s</NAME>\n", array[i].Vorname); /*dank struct kann ich einfach so zugreifen*/
			fprintf (fp, "	<NAME>%s</NAME>\n", array[i].Name);
			fprintf (fp, "	<PHONE>%s</PHONE>\n", array[i].Phone);
			fprintf (fp, "	<STATE>%s</STATE>\n", array[i].Land);
			fprintf (fp, "</PERSON>\n");
		}	
	}
	printf("Datei %s wurde erstellt.\n", fn);
}

int PrintAll(Eintrag *array, int anz){

	int i, zae=0;

    printf("Ausgabe von Profilen von 1 bis %d\n", anz);

    for (i = 0; i<anz ;i++) 
    { 
        if(array[i].Phone)
        {
            printf("\nPerson #%d\n",i+1);
            printf("Name: %s\n", array[i].Name);
            printf("Vorname: %s\n", array[i].Vorname);
            printf("Telefon: %d\n", array[i].Phone);
            printf("Land: %d\n", array[i].Land);
            zae++;
        }
    }
    if(zae) 
        puts("Fertig...");
    else
        puts("Keine Eintraege vorhanden.");
}