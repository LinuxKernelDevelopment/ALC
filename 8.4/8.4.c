#include <stdlib.h>
#include "Item.h"
#include "Array.h"

main(int argc, char *argv[])
{ int i, N = atoi(argv[1]);
  Item *c = malloc(sizeof(Item)*N);
  for(i = 0; i < N; i++) c[i] = rand()%100;
  mergesortAB(c, 0, N-1);
  show(c, 0, N);
}
