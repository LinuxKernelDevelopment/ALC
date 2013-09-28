#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

double ITEMrand(void)
         { return rand()%100; }

int ITEMscan(double *x)
         { return scanf("%f", x); }
void ITEMshow(double x)
         { printf("%f\t", x); }
