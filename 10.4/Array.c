#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "Array.h"
#include "digit.h"
/*void randinit(Item a[], int N)
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
}*/

/*void sort(Item a[], int l, int r)
{ int i, j, h;
  for( h = 1; h <= (r-1)/9; h = 3*h+1) ;
  for ( ; h > 0; h /= 3)
    for (i = l + h; i <= r; i++)
    { int j = i; Item v = a[i];
      while (j >= l+h && less(v, a[j-h]))
      { a[j] = a[j-h]; j -= h; }
      a[j] = v;
    }
}*/
//#define digit(A, B) A[B]
void insertion(Item a[], int l, int r, int w)
  { int i;
    for (i = r; i > l; i--)compexch(a[i-1], a[i], w);
    for (i = l+2; i <= r; i++)
      { int j = i; Item v = a[i];
        while (less(v, a[j-1], w))
            { a[j] = a[j-1]; j--; }
        a[j] = v;
      }
  }

#define M 3
Item aux[33];
#define R 200
#define bin(A) l+count[A]
#define bytesword 3
//#define digit(A, B) A[B]
/*void radixMSD(Item a[], int l, int r, int w)
{ int i, j, count[R+1];
  if (w > bytesword) return;
  if (r-l <= M) 
  {
    for(i = l; i <= r; i++) printf("%s\t", a[i]);
    printf("\n");
    printf("l:%d\tr:%d\n", l, r);
    insertion(a, l, r, w); 
    return;  
  }
  //if(r <= l) return;
  for (j = 0; j < R+1; j++) count[j] = 0;
  for (i = 1; i <= r; i++)
  {
   count[digit(a[i], w) + 1]++;
  }
  for (j = 1; j < R; j++)
   count[j] += count[j-1];
  for (i = l; i <= r; i++)
   aux[count[digit(a[i], w)]++] = a[i];
  for (i = l; i <= r; i++) a[i] = aux[i];
  radixMSD(a, l, bin(0)-1, w+1);
  for (j = 0; j < R-1; j++)
    radixMSD(a, bin(j), bin(j+1)-1, w+1);
}*/

void radixLSD(Item a[], int l, int r)
  {
    int i, j, w, count[R+1];
    for (w = bytesword-1; w >= 0; w--)
    {
      for (j = 0; j < R; j++) count[j] = 0;
      for (i = l; i <= r; i++)
      {
        /*printf("w:%d\n", w);
        printf("a[i]:%s\n", a[i]);
        printf("index:%d\n", digit(a[i], w)+1);*/
        count[digit(a[i], w) + 1]++;
      }
      for (j = 1; j < R; j++)
        count[j] += count[j-1];
      for (i = l; i <= r; i++)
        aux[count[digit(a[i], w)]++] = a[i];
      for (i = l; i <= r; i++) a[i] = aux[i];
     }
   }
