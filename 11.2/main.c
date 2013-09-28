#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "Array.h"

main(int argc, char *argv[])
{ int i, N = atoi(argv[1]), sw = atoi(argv[2]);
  Item *a = malloc(N*sizeof(Item));
  if (sw) randinit(a, N); else scaninit(a, &N);
  show(a, 0, 99);
  printf("\n");
  //quicksort(a, 0, N-1);
  //mergeTD(a, 0, N-1);
  mergeBU(a, 0, N-1);
  show(a, 0, N-1);
}
