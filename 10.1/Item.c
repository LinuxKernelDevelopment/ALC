#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

char ITEMrand(void)
         { return rand()%256; }
char ITEMscan(char *x)
         { return scanf("%d", x); }
void ITEMshow(char x)
         { printf("%d", x); }
