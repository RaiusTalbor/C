/*1.13 ASCII-Zeichen und Augabeformate*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
    int i;
    char y;
    int erg[7];
    int erg2[7];
    int ergx[7]; /*XOR*/
    int konst = 0x20; /*XOR mit 5C: 01011001*/

    printf("Geben Sie einen Buchstaben an: ");
    fflush(stdin);
    scanf("%c", &y);

    printf("%c als Dezimal    : %d\n", y, y);
    printf("%c als Oktal      : %o\n", y, y);
    printf("%c als Hexadezimal: 0x%x\n", y, y);

    printf("%c als Binaer     : ", y);

    /*Für Binärausgabe muss gerechnet werden:*/
    for (i = 0; (int)y >= 1; i++)
    {
        erg[i] = y % 2;         /*Der Rest wird als Dezimalzahl gespeichert. Ich weiß, dass ein Buchstabe max. 8 Bit braucht.*/
        y = y / 2;              /*Da nur Modulo gerechnet wird, ich brauche aber noch die Zahl, mit der ich weiterrechnen muss.*/
        /*printf("%d\n", y);      Kontrollausgabe*/
    }

    for (i = 7; i >= 0; i--)     /*Umgekehrt, da Binärzahl falsch herum gespeichert; i entspricht Feldnr.*/
    {
        printf("%d", erg[i]);   /*Die Felder werden nacheinander ausgegeben und ergeben zusammen die Binaerzahl*/
    }
    printf("\n\n");

    /*Aufgabenstellung Teil III: Ybin mit 0x5C XOR*/

    /*printf("konst als Dezimal    : %d\n", konst);
    printf("konst als Oktal      : %o\n", konst);
    printf("konst als Hexadezimal: %x\n", konst); Kontrolle*/ 
    
    for (i = 0; konst >= 1; i++)
    {
        erg2[i] = konst % 2;         /*Der Rest wird als Dezimalzahl gespeichert. Ich weiß, dass ein Buchstabe max. 8 Bit braucht.*/
        konst = konst / 2;           /*Da nur odulo gerechnet wird, ich brauche aber noch die Zahl, mit der ich weiterrechnen muss.*/
        /*printf("%d\n", konst);      Kontrollausgabe*/
    }

    /*printf("konst als Binaer     : ");
    for (i = 7; i >= 0; i--)     Umgekehrt, da Binärzahl falsch herum gespeichert; i entspricht Feldnr.
    {
        printf("%d", erg2[i]);   Die Felder werden nacheinander ausgegeben und ergeben zusammen die Binaerzahl
    }*/

   /*Eigentliches XOR*/

   printf("XOR: ");

   for (i = 7; i >= 0; i--)
   {
        if (erg[i] == erg2[i])
        {
            ergx[i] = 0;
        }
        else
        {
            ergx[i] = 1;
        }

    printf("%d", ergx[i]);
        
   }

    return 0;
}