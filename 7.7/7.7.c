#include <stdlib.h>
#include "Item.h"
#include "Array.h"

main(int argc, char *argv[])
{ int i, N = atoi(argv[1]), sw = atoi(argv[2]);
  Item *a = malloc(N*sizeof(Item));
  if (sw) randinit(a, N); else scaninit(a, &N);
  Select(a, 0, N-1, (N-1)/2);
  show(a, 0, N-1);
}
