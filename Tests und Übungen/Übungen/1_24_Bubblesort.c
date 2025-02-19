/*1.24 Bubblesort*/
/*Rouven L., s3005525, 3IT24-2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 200

void bubbleSort(double *A, int size);
void drucken(double *, int);

int datei(double *, int, char *);

int main (void)
{
    double a[200];
    int i;
    char fn[] = "1_24.log"; /*Str mit NULL als Begrenzer, so viele Buchstaben wie erste Eingabe*/

    srand(time(NULL));

    puts("Array unsortiert");
    
    for (i = 0; i < MAX; i++)
    {
        a[i] = (rand() % 10000 + 100)/100.00;  /*für floats*/
        printf("%.2lf\t", a[i]);            /*Tabulator*/
    }

    bubbleSort(a, MAX);

    puts("Array sortiert");

    for (i = 0; i < MAX; i++)
    {
       printf("%.2lf\t", a[i]);
    }
    printf("Schreibe in die Datei: ");
    puts(fn);
    datei(a, MAX, fn);    

    return 0;
}

void bubbleSort(double *A, int size)
{
int i, n;
double temp;

  for (n = size; n > 1; n = n - 1) 
  {                                             /*äußere Schleife*/
    for (i = 0; i < n - 1; i = i + 1) 
    {                                           /*innere Schleife*/
      if (A[i] > A[i + 1]) 
      {
        temp = A[i];
        A[i] = A[i+1];
        A[i+1] = temp;
      }
    } 
  }
}

/*Man könnte es auch als .bin speichern, für später interessant*/
int datei(double *p, int anz, char *fname)
{
    FILE *f;
    int i;

    f = fopen(fname, "w");

    if (f == NULL)
    {
        puts("Fehler aufgetreten!! :O");

        return -1;
    }
    else
    {
        for (i = 0; i < MAX; i++)
        {
            fprintf(f, "%.2lf\t", p[i]);
        }
    }
    
    fclose(f);
}