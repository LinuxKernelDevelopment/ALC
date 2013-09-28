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

mergeAB(Item c[], Item a[], int N, Item b[], int M)
{ int i, j, k;
  for (i = 0, j = 0, k = 0; k < N+M; k++)
  {
    if (i == N) { c[k] = b[j++]; continue; }
    if (j == M) { c[k] = a[i++]; continue; }
    c[k] = (less(a[i], b[j])) ? a[i++] : b[j++];
  }
}
#define maxN 1000
Item aux[maxN];
void mergesortABr(Item a[], Item b[], int l, int r)
{ int m = (l+r)/2;
  if (r-l <= 10) {insertion(a, l, r); return; }
  mergesortABr(b, a, l, m);
  mergesortABr(b, a, m+1, r);
  mergeAB(a+l, b+l, m-l+1, b+m+1, r-m);
}

void insertion(Item a[], int l, int r)
{ int i;
  for (i = r; i > l; i--) compexch(a[i-1], a[i]);
  for (i = l+2; i <= r; i++)
    { int j = i; Item v = a[i];
      while (less(v, a[j-1]))
       {a[j] = a[j-1]; j--;}
     a[j] = v;
    }
      
}
void mergesortAB(Item a[], int l, int r)
{ int i;
  for (i = l; i <= r; i++) aux[i] = a[i];
  mergesortABr(a, aux, l, r);
}
