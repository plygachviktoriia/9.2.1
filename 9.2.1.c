#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
   unsigned int size;
   float *udiag, *diag, *ldiag;
}TDMAT;

TDMAT *tdmat_create_with_type(unsigned int size);     //vytvorenie zakladnej datovej struktury TDMAT
void   tdmat_print(const TDMAT *mat);                 //vypise maticu mat na obrazovku
void   tdmat_destroy(TDMAT *mat);                     //uvolnenie pamati po tridiagonalnej matici reprezentovanej typom TDMAT
float tdmat_determinant(TDMAT *mat);
void tdmat_random(TDMAT *mat);


void tdmat_random(TDMAT *mat)
{
 if (mat == NULL)
 {
  return;
 }
 
srand((unsigned int)time(NULL));

 for (unsigned int i = 0; i < mat->size; i++)          //hlavna diagonal
 { 
  int cely = rand() % 101 - 50;                      // zaporny a kladny cisla 
  int drob = rand() % 100;
  mat->diag[i] = cely + drob / 100.0f;
 }

 for (unsigned int i = 0; i < mat->size - 1; i++)
 {
  int cely1 = rand() % 101 - 50;
  int drob1 = rand() % 100;
  mat->udiag[i] = cely1 + drob1 / 100.0f;

  int cely2 = rand() % 101 - 50;  
  int drob2 = rand() % 100;
  mat->ldiag[i] = cely2 + drob2 / 100.0f;
 }
}


TDMAT *tdmat_create_with_type(unsigned int size)
{
 TDMAT *mat = malloc(sizeof(TDMAT));                   //dynamicka alokacia
 if (mat == NULL)
 return NULL;

 mat->size = size;                                    //za[is v pole size struktury na ktoru ukazuje ukazovatel mat, hodnotu premennej size

 mat->udiag = malloc(sizeof(float) * (size - 1));     //dynamicka alokacia podlia 3 diagonalej
 mat->diag = malloc(sizeof(float) * size);
 mat->ldiag = malloc(sizeof(float) * (size - 1));

 if ((size > 1 && (mat->udiag == NULL || mat->ldiag == NULL)) || mat->diag == NULL) 
 {
  free(mat->udiag);
  free(mat->diag);
  free(mat->ldiag);
  free(mat);
  return NULL;
 }

 return(mat);
}


void tdmat_print(const TDMAT *mat)
{
 if (mat == NULL)
 return;


 for (unsigned int i = 0; i < mat->size; i++)
 {
  for (unsigned int j = 0; j < mat->size; j++)
  {
   if (j == i)
   {
    printf("%.2f  ", mat->diag[i]);
   }
    else if (j == i + 1 && i < mat->size - 1)
    {
     printf("%.2f  ", mat->udiag[i]);
    }
     else if (i == j + 1 && j < mat->size - 1)
     {
      printf("%.2f  ", mat->ldiag[j]);
     }
      else
      {
       printf("0.00  ");
      }
  }
printf("\n");
 }
}


float tdmat_determinant(TDMAT *mat) 
{
if (mat == NULL || mat->size == 0)
 {
  return 0;
 } 

unsigned int n = mat->size;

float *D = malloc(sizeof(float) * n);
if (D == NULL)
{
 return 0;
}

D[0] = mat->diag[0];                  //det podlia 1x1

if (n > 1)
{
 D[1] = mat->diag[1] * D[0] - mat->ldiag[0] * mat->udiag[0];    //det 2x2
}

for (unsigned int i = 2; i < n; i++)                            //pocitanie podlia minorov
{
 float a = mat->diag[i];
 float b = mat->ldiag[i - 1];
 float c = mat->udiag[i - 1];
 D[i] = a * D[i - 1] - b * c * D[i - 2];
}

float determinant = D[n - 1];
free(D);
return determinant;  
}


int main (void) 
{
 unsigned int n;
 printf("Zadaj rozmernost' matice tyou nxn:\n");
 scanf("%u", &n);

 TDMAT *mat = tdmat_create_with_type(n);

 if (mat == NULL)
 {
  printf ("Nemoznost vytvorenia matice %ux%u\n", n,n);
  return 1;
 }

 tdmat_random(mat);
 tdmat_print(mat);

 float determinant = tdmat_determinant(mat);            //zapis determinantu
 printf("Determinant: %.2f\n", determinant);

 tdmat_destroy(mat);

 return 0;
}


void   tdmat_destroy(TDMAT *mat)
{
if (mat == NULL)
return;

free(mat->udiag);
free(mat->diag);
free(mat->ldiag);
free(mat);
}