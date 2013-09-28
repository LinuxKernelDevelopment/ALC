//#include "ST.h"
#include "Item.h"
#define Key Item
//struct STnode { Item item; link next;};
typedef struct STnode* link;
struct STnode { Item item; link next;};
static link head, z;
static int N;
static link NEW(Item item, link next)
  { link x = malloc(sizeof *x);
    x->item = item; x->next = next;
    return x;
  }
void STinit(int max)
  { N = 0; head = (z = NEW(NULLitem, 0)); }
int STcount() { return N; }
Item searchR(link t, Key v)
  {
   if (t == z) return NULLitem;
   if (eq(key(t->item), v)) return t->item;
   return searchR(t->next, v);
  }
void STshow()
{
  link t = head;
  for(; t!= 0; t = t->next)
   printf("%d\t", t->item);
  printf("\n");
}
Item STsearch(Key v)
  { return searchR(head, v); }
void STinsert(Item item)
  { head = NEW(item, head); N++; }
