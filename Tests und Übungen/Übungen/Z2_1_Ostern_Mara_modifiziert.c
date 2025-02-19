#include <stdio.h>
#include <stdlib.h>
#include <math.h> /*floor() -- abrunden*/

/*
Aufgabe 2.1 (Zusatzskript) Osterformel

Schreiben Sie das Programm in der Sprache Python zum Berechnen von Osterdatum unter
Nutzung von vereinfachten Algorithmus nach O�Beirne (1965) basierend auf dem VL-Skript.
Hinweis:
Nutzen Sie den folgenden Pseudocode:
# Einfacher Algorithmus von T. H. O�Beirne (1965)
# g�ltig f�r 1900... 2099
- N = Jahr � 1900
- A = N mod 19
- B = [(7A + 1) / 19]   []...abrunden
- M = (11A + 4 � B) mod 29
- Q = [N / 4]
- W = (N + Q + 31 � M) mod 7
- P = 25 � M � W
- Ostersonntag ist der P. April bzw. der (P + 31). M�rz
Erg�nzen Sie das Programm um die Funktionen f�r Berechnung von beweglichen Feiertagen!
*/

/*prototypes*/
int berechneOstern(int, int*, int*);
int berechneHimmelfahrt(int, int, int*, int*);
int berechnePfingsten(int, int, int*, int*);
int berechneFastnacht(int, int, int*, int*);

/*functions*/
int berechneOstern(int year, int *ostertag, int *ostermonat){ /*use pointers bc I can't return two values*/

    int N, A, B, M, Q, W, P;

    N = year - 1900;
    A = N % 19;
    B = floor((7*A + 1) / 19);
    M = (11*A + 4 - B) % 29;
    Q = floor(N / 4);
    W = (N + Q + 31 - M) % 7;
    P = 25 - M - W;

    if (P<1) {
        *ostertag = P + 31;
        *ostermonat = 3;
    } else {
        *ostertag = P;
        *ostermonat = 4;
    }
    return 0;
}

int berechneHimmelfahrt(int ostertag, int ostermonat, int *himmelfahrtstag, int *himmelfahrtsmonat) {
    int tageImMonat[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; /*schaltjahr nicht relevant*/
    int gesamttage = ostertag + 39;
    int monat = ostermonat;

    while (gesamttage > tageImMonat[monat - 1]) {
        gesamttage -= tageImMonat[monat - 1];
        monat++;
    }

    *himmelfahrtstag = gesamttage;
    *himmelfahrtsmonat = monat;

    return 0;
}

int berechnePfingsten(int ostertag, int ostermonat, int *pfingsttag, int *pfingstmonat) {
    int tageImMonat[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; /*schaltjahr nicht relevant*/
    int gesamttage = ostertag + 49;
    int monat = ostermonat;

    while (gesamttage > tageImMonat[monat - 1]) {
        gesamttage -= tageImMonat[monat - 1];
        monat++;
    }

    *pfingsttag = gesamttage;
    *pfingstmonat = monat;

    return 0;
}

int berechneFastnacht(int ostertag, int ostermonat, int *fasttag, int *fastmonat) {
    int tageImMonat[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; /*schaltjahr nicht relevant*/
    int gesamttage = ostertag - 46;
    int monat = ostermonat;

    while (gesamttage < 0) {
        gesamttage += tageImMonat[monat - 1];
        monat--;
    }

    *fasttag = gesamttage;
    *fastmonat = monat;

    return 0;
}

int main(void) {

    int year, minYear, maxYear;
    int ostertag, ostermonat, himmelfahrtstag, himmelfahrtsmonat, pfingsttag, pfingstmonat, fasttag, fastmonat;
    minYear = 1900;
    maxYear = 2099;

    while (1) {
        /*input*/
        printf("Jahr (zwischen 1900 und 2099, 0 beendet): ");
        fflush(stdin);
        scanf("%d", &year);

        /*Abbruchbedingung*/
        if (year == 0) {
            printf("Programm beendet.\n");
            break; /*completely stops the while loop and therefore the program will end*/
        }

        /*check input*/
        if (year < minYear || year > maxYear) {
            printf("Jahr muss zwischen 1900 und 2099 liegen.\n");
            continue; /*only stops this while loop and starts with a new one*/
        }

        berechneOstern(year, &ostertag, &ostermonat); /*& marks the variables as pointers -> passes only the addresses*/
        berechneHimmelfahrt(ostertag, ostermonat, &himmelfahrtstag, &himmelfahrtsmonat);
        berechnePfingsten(ostertag, ostermonat, &pfingsttag, &pfingstmonat);
        berechneFastnacht(ostertag, ostermonat, &fasttag, &fastmonat);

        /*output*/
        printf("Ostersonntag:        %d.%d.%d\n", ostertag, ostermonat, year);
        printf("Christi Himmelfahrt: %d.%d.%d\n", himmelfahrtstag, himmelfahrtsmonat, year);
        printf("Pfingstsonntag:      %d.%d.%d\n", pfingsttag, pfingstmonat, year);
        printf("Fastnacht:           %d.%d.%d\n\n", fasttag, fastmonat, year);
    }
    return 0;
}

