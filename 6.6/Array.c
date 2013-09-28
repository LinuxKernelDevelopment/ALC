#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "Array.h"

void randinit(Item a[], int N)
{ int i;
  for (i = 0; i < N; i++) a[i] = ITEMrand();
}

void scaninit(Item a[], int *N)
{ int i = 0;
  for (i = 0; i < *N; i++)
   if (ITEMscan(&a[i]) == EOF) break;
  *N = i;
}

void show(Item a[], int l, int r)
{ int i;
  for (i = l; i <= r; i++) ITEMshow(a[i]);
  printf("\n");
}

void sort(Item a[], int l, int r)
{ int i, j, h;
  for( h = 1; h <= (r-1)/9; h = 3*h+1) ;
  for ( ; h > 0; h /= 3)
    for (i = l + h; i <= r; i++)
    { int j = i; Item v = a[i];
      while (j >= l+h && less(v, a[j-h]))
      { a[j] = a[j-h]; j -= h; }
      a[j] = v;
    }
}
