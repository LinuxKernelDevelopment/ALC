#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "Array.h"
#include "Stack.h"

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

int paratition(Item a[], int l, int r);
/*void quicksort(Item a[], int l, int r)
{ int i;
  if (r <= l) return;
  i = paratition(a, l, r);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}*/


int paratition(Item a[], int l, int r)
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

#define push2(A, B) STACKpush(B); STACKpush(A);
void quicksort(Item a[], int l, int r)
{ int i;
  STACKinit(10); push2(l, r);
  while (!STACKempty())
  {
    l = STACKpop(); r = STACKpop();
    if (r <= l) continue;
    i = paratition(a, l, r);
    if (i-1 > r-i)
     { push2(l, i-1); push2(i+1, r); }
    else
     { push2(i+1, r); push2(l, i-1); }
  }

}
