#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
void main(int argc, char *argv[])
{ int i, N = atoi(argv[1]), sw = atoi(argv[2]);
  Item *a = malloc(N *sizeof(Item));
  if (sw) ; 
  else  scaninit(a, &N);
  sort(a, 0, N-1);
  show(a, 0, N-1);
}
