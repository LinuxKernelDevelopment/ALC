#include "Item.h"
#include "ST.h"
#define Key Item
static Item *st;
static int N;
void STinit(int maxN)
 { st = malloc((maxN)*sizeof(Item)); N = 0; }
int STcount()
 { return N; }
void STinsert(Item item)
 { int j = N++; Key v = key(item);
   while (j>0 && less(v, (st[j-1])))
     {   st[j] = st[j-1]; j--; }
   st[j] = item;
 }
/*Item STsearch(Key v)
 { int j;
   for (j = 0; j < N; j++)
     {
       if (eq(v, key(st[j]))) return st[j];
       if (less(v, key(st[j]))) break;
     }
   return NULLitem;
 }*/
Item STselect(int k)
 { return st[k]; }
void STsort(void (*visit)(Item))
 { int i;
   for (i = 0; i < N; i++) visit(st[i]);
 }
Item search(int l, int r, Key v)
 { int m = (l+r)/2;
   if (l > r) return NULLitem;
   if (eq(v, key(st[m]))) return st[m];
   if (l == r) return NULLitem;
   if (less(v, key(st[m])))
         return search(l, m-1, v);
   else return search(m+1, r, v);
 }

Item STsearch(Key v)
 { return search(0, N-1, v); }
