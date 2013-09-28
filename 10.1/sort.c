#include <stdlib.h>
#include "Item.h"
#include "sort.h"

 void quicksortB(char a[], int l, int r, int w)
 { int i = l, j = r;
   if (r <= l || w > bitsbyte) return;
   while (j != i)
     {
       while (digit(a[i], w) == 0 && (i < j)) i++;
       while (digit(a[j], w) == 1 && (j > i)) j--;
       exch(a[i], a[j]);
     }
   printf("test:%d\n", digit(a[r], w));
   if (digit(a[r], w) == 0) j++;
   quicksortB(a, l, j-1, w+1);
   quicksortB(a, j, r, w+1);
 }

void sort(Item a[], int l, int r)
 { 
   quicksortB(a, l, r, 0);
 }
