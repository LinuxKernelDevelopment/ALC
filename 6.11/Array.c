#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "Array.h"

int compare(void *i, void *j)
{ return strcmp(*(Item *)i, *(Item *)j); }



void scaninit(Item a[], int *N)
{ int i = 0;
  
  for (i = 0; i < *N; i++)
  {
   if (ITEMscan(&a[i]) == EOF) break;
  }
  *N = i;
}

void show(Item a[], int l, int r)
{ int i;
  for (i = l; i <= r; i++) ITEMshow(a[i]);
  printf("\n");
}

void sort(Item a[], int l, int r)
{ qsort(a, r-l+1, sizeof(Item), compare);}
