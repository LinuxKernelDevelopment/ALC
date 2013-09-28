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
