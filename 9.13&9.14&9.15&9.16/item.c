#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int ITEMrand(void)
         { return rand()%100; }

int ITEMscan(int *x)
         { return scanf("%f", x); }
void ITEMshow(int x)
         { printf("%d\t", x); }
