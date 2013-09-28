#include <stdio.h>
#include "UF.h"
#include "UF.c"

main(int argc, char *argv[])
{ int p, q, N = atoi(argv[1]), tmp;
  UFinit(N);
  while (scanf("%d %d", &p, &q) == 2)
    if (!UFfind(p, q))
     { tmp = UFunion(p, q); printf(" %d %d %d", p, q, tmp); }
  UF_display(tmp);
  UF_debug(N);
}
