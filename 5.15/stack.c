#include <stdlib.h>
#include "Item.h"
#define Item link;
typedef struct STACKnode* Link;
struct STACKnode { Item item; Link next;};
static Link head;
Link NEW(Item item, Link next)
{ Link x = malloc(sizeof *x);
  x->item = item; x->next = next;
  return x;
}
void STACKinit(int maxN)
{ head = NULL; }
int STACKempty()
{ return head == NULL; }
STACKpush(Item item)
{ head = NEW(item, head); }
Item STACKpop()
{ Item item = head->item;
  Link t = head->next;
  free(head); head = t;
  return item;
}

