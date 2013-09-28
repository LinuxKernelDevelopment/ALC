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

void quicksort(Item a[], int, int);
void insertion(Item a[], int, int);
void sort(Item a[], int l, int r)
{ 
   quicksort(a, l, r); 
   insertion(a, l, r);
}

void insertion(Item a[], int l, int r)
{ int i;
  for (i = r; i > l; i--) compexch(a[i-1], a[i]);
  for (i = l+2; i <= r; i++)
  {  int j = i;  Item v = a[i];
     while (less(v, a[j-1]))
     { a[j] = a[j-1]; j--;}
     a[j] = v;
  }
}

#define M 10
void quicksort(Item a[], int l, int r)
{ int i;
  if (r-l <= M) return;
  exch(a[(l+r)/2], a[r-1]);
  compexch(a[l], a[r-1]);
    compexch(a[l], a[r]);
      compexch(a[r-1], a[r]);
  i = paratition(a, l+1, r-1);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}


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

Item aux[100];
shuffle(Item a[], int l, int r)
  { int i, j, m = (l+r)/2;
    for (i = 1, j = 0; i <= r; i+=2, j++)
       { aux[i] = a[l+j]; aux[i+1] = a[m+1+j]; }
    for (i = l; i <= r; i++) a[i] = aux[i];
  }

unshuffle(Item a[], int l, int r)
  { int i, j, m = (l+r)/2;
    for(i = l, j = 0; i <= r; i+=2, j++)
     { aux[l+j] = a[i]; aux[m+1+j] = a[i+1]; }
    for(i = l; i <= r; i++) a[i] = aux[i];
  }

mergeTD(Item a[], int l, int r)
 { int i, m = (l+r)/2;
   if (r == l+1) compexch(a[l], a[r]);
   if (r < l+2) return;
   unshuffle(a, l, r);
   mergeTD(a, l, m);
   mergeTD(a, m+1, r);
   shuffle(a, l, r);
   for (i = l+1; i < r; i+=2)
    compexch(a[i], a[i+1]);
   //shuffle(a, l, r);
 }

mergeBU(Item a[], int l, int r)
 { int i, j, k, N = r-l+1;
   for (k = N/2; k > 0; k /= 2)
    for (j = k % (N/2); j+k < N; j += (k+k))
     for (i = 0; i < k; i++)
     {
       compexch(a[l+j+i], a[l+j+i+k]);
       printf("%d's round compare:a[%d] and a[%d]\n", i, l+j+i, l+j+i+k);
     }
 }
