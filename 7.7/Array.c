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
{ quicksort(a, l, r); 
}

int partition(Item a[], int l, int r);
void quicksort(Item a[], int l, int r)
{ int i;
  if (r <= l) return;
  i = partition(a, l, r);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}

void Select(Item a[], int l, int r, int k)
{ 
  while (r > l)
   { int i = partition(a, l, r);
     if (i >= k) r = i-1;
     if (i <= k) l = i+1;
   }
}


int partition(Item a[], int l, int r)
{ int i = l-1, j = r; Item v = a[r];
  for(;;)
    {
     while (less(a[++i], v));
     while (less(v, a[--j])) if (j == l) break;
     if (i >= j) break;
     exch(a[i], a[j]);
    }
  exch(a[i], a[r]);
  return i;
}
