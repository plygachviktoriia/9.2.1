#include <stdio.h>
#include <stdlib.h>

typedef struct{
   unsigned int size;
   float *udiag;
   float *diag;
   float *ldiag;
}TDMAT;

float tdmat_determinant(TDMAT *mat);