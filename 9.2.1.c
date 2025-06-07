#include <stdio.h>
#include <stdlib.h>

typedef struct{
   unsigned int size;
   float *udiag;
   float *diag;
   float *ldiag;
}TDMAT;

float tdmat_determinant(TDMAT *mat);

TDMAT *tdmat_create_with_type(unsigned int size);     //vytvorenie zakladnej datovej struktury TDMAT
void   tdmat_unit(TDMAT *mat);                        //inicializuje maticu ako jednotkovu tridiagonalnu
void   tdmat_random(TDMAT *mat);                      //naplni maticu nahodnymi hodnotami v rozsahu (-1, +1)
void   tdmat_print(const TDMAT *mat);                 //vypise maticu mat na obrazovku
void   tdmat_destroy(TDMAT *mat);                     //uvolnenie pamati po tridiagonalnej matici reprezentovanej typom TDMAT

int main (void) 
{
unsigned int n = 6;


}

