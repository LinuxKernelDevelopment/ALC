#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "PQ.h"

int main(void)
{
   PQ Pority; int i;
   Pority = malloc(sizeof *Pority);
   Pority->bq = malloc((sizeof(PQlink)) * maxBQsize);
   for (i = 0; i < maxBQsize; i++) {
                               Pority->bq[i] = malloc(sizeof(struct PQnode));                                         Pority->bq[i] = NULL;
                             }
   printf("test1\n");
   for (i = 0; i < maxBQsize; i++)
     PQinsert(Pority, ITEMrand());
   for (i = 0; i < maxBQsize; i++) printf("%d\t",PQdelmax(Pority));
   printf("\n");
   return 0;
}
