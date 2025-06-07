#include <stdio.h>
#include <stdlib.h>

typedef struct{
   unsigned int size;
   float *udiag, *diag, *ldiag;
}TDMAT;

TDMAT *tdmat_create_with_type(unsigned int size);     //vytvorenie zakladnej datovej struktury TDMAT
void   tdmat_unit(TDMAT *mat);                        //inicializuje maticu ako jednotkovu tridiagonalnu
void   tdmat_print(const TDMAT *mat);                 //vypise maticu mat na obrazovku
void   tdmat_destroy(TDMAT *mat);                     //uvolnenie pamati po tridiagonalnej matici reprezentovanej typom TDMAT
float tdmat_determinant(TDMAT *mat);


int main (void) 
{
 unsigned int n = 6;

 TDMAT *mat = tdmat_create_with_type(n);

 if (mat == NULL)
 {
  printf ("Nemoznost vytvorenia matice %ux%u\n", n,n);
  return 1;
 }

 tdmat_unit(mat);
 tdmat_print(mat);

 float determinant = tdmat_determinant(mat);            //zapis determinantu
 printf("Determinant: %.2f\n", determinant);

 tdmat_destroy(mat);

 return 0;
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

 return(mat);
}


void tdmat_unit(TDMAT *mat) 
{
 if (mat == NULL)
 return;

 for (unsigned int i = 0; i < mat->size; i++)
 {
  mat->diag[i] = 1;
 }

 for (unsigned int i = 0; i < mat->size - 1; i++)
 {
  mat->udiag[i] = 0;
  mat->ldiag[i] = 0;
 }
}


void tdmat_print(const TDMAT *mat)
{
 if (mat == NULL)
 return;

 mat->size;

 for (unsigned int i = 0; i < mat->size; i++)
 {
  for (unsigned int j = 0; j < mat->size; j++)
  {
   if (j == i)
   {
    printf("%.2f ", mat->diag[i]);
   }
    else if (j == i + 1 && i < mat->size - 1)
    {
     printf("%.2f", mat->udiag[i]);
    }
     else if (i == j + 1 && j < mat->size - 1)
     {
      printf("%.2f", mat->ldiag[i])
     }
      else
      {
       printf("%.2f", 0.0);
      }
  }
 }
}


float tdmat_determinant(TDMAT *mat) 
{
if (mat == NULL)
return;   
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



