#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "Array.h"


/*void randinit(Item a[], int N)
{ int i;
  for (i = 0; i < N; i++) a[i] = ITEMrand();
}
int *index;

void scaninit(Item a[], int *N)
{ int i = 0;
  for (i = 0; i < *N; i++)
   if (ITEMscan(&a[i]) == EOF) break;
  *N = i;
}*/

/*void show(Item a[], int l, int r)
{ int i;
  for (i = l; i <= r; i++) ITEMshow(a[i]);
  printf("\n");
}*/

void sort(Item a[], int l, int r)
{ index = malloc(sizeof(int) * (r - l + 1));
  int k;
  for(k = 0; k < r-l; k++) index[k] = 0;
  Item tmp;
  int i = l, j = l;
  for(tmp = a[i]; i <= r, tmp = a[i]; i++)
    for(j = l; j <= r; j++)
    { 
       if(less(a[j], tmp)) index[i]++;
    }
  int tem;
  for(i = l; i <= r; i++)
    for(j = i+1; j <= r; j++)
  {
       if(a[i] == a[j]) index[j]++;
  }
}

insitu(Item data[], int a[], int N)
{ int i, j, k, tem;
  for (i = 0; i < N; i++)
  { Item v = data[i];
    for (k = i; a[k] != i; k = a[j], a[j] = j)
      { j = k;  data[k] = data[a[k]]; }
    data[k] = v; a[k] = k;
  }
}
void test()
{
  int i;
  for (i = 0; i < 12; i++) printf("%d\t", index[i]);
 printf("\n");
}
