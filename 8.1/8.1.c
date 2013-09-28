#include <stdlib.h>
#include "Item.h"
#include "Array.h"

main(int argc, char *argv[])
{ int i, sw = atoi(argv[1]), N = atoi(argv[2]), M = atoi(argv[3]);
  Item *a = malloc(N*sizeof(Item));
  Item *b = malloc(M*sizeof(Item));
  Item *c = malloc((N+M-2)*sizeof(Item));
  if (sw) {randinit(a, N); randinit(b, M);}else scaninit(a, &N);
  quicksort(a, 0, N-1);
  quicksort(b, 0, M-1);
  printf("Array a:");
  show(a, 0, N-1);
  printf("\n");
  printf("Array b:");
  show(b, 0, M-1);
  mergeAB(c, a, N, b, M);
  show(c, 0, N+M);
}
