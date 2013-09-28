#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

Item ITEMrand(void)
         { Item t;
          t.x = 1.0 * rand()/RAND_MAX; 
          t.y = 1.0 * rand()/RAND_MAX;
          t.val = t.x * t.x + t.y * t.y;
          return t;}

/*int ITEMscan(Item *x)
         { return scanf("%f", x); }*/
void ITEMshow(Item t)
         { printf("%7.5fi+%7.5f\n", t.x, t.y); }
