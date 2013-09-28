#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

int ITEMrand(void)
         { return rand()%100; }

int ITEMscan(int *x)
         { return scanf("%d", x); }
void ITEMshow(int x)
         { printf("%d\t", x); }
