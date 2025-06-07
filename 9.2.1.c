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



}

