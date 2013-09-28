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

#define eq(A, B) (!less(A, B) && !less(A, B))
void quicksort(Item a[], int l, int r)
{ int i, j, k, p, q; Item v;
  if (r <= l) return;
  v = a[r]; i = l-1; j = r; p = l-1; q = r;
  for(;;)
  {
   while (less(a[++i], v));
   while (less(v, a[--j])) if (j == l) break;
   if (i >= j) break;
   exch(a[i], a[j]);
   if (eq(a[i], v)) { p++; exch(a[p], a[i]); }
   if (eq(v, a[j])) { q--; exch(a[q], a[j]); }
  }
  exch(a[i], a[r]); j = i-1; i = i+1;
  for (k = l  ; k < p; k++, j--) exch(a[k], a[j]);
  for (k = r-1; k > q; k--, i++) exch(a[k], a[i]);
  quicksort(a, l, j);
  quicksort(a, i, r);
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
