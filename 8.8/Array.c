#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "Array.h"
#include "Queue.h"

link NEW1(Item item, link next)
{
   link x = malloc(sizeof *x);
   x->item = item; x->next = next;
   return x;
}


link init(int n)
{
   int i;
   link dummy;
   link t = NULL;
   dummy = malloc(sizeof *dummy);
   int tem;
   for(i = 0; i < n; i++) {tem = rand()%100;  t  = NEW1(tem, t); printf("%d\n", t->item);}
   dummy->item = -1;
   dummy->next = t;
   show(dummy);
   return dummy;
}

link merge(link a, link b)
{ struct node  head; link c = &head;
  while ((a != NULL) && (b != NULL))
   if (less(a->item, b->item))
    { c->next = a; c = a; a = a->next; }
   else
    { c->next = b; c = b; b = b->next; }
  c->next = (a == NULL) ? b : a;
  return head.next;
}

/*link merge(link a, link b);
link mergesort(link c)
 { link a, b;
   if (c == NULL || c->next == NULL) return c;
   a = c; b = c->next;
   while ((b != NULL) && (b->next != NULL))
     { c = c->next; b = b->next->next; }
   b = c->next; c->next = NULL;
   return merge(mergesort(a), mergesort(b));
 }*/

link mergesort(link t)
 { link u;
   for (QUEUEinit(10); u != NULL; t = u);
     { u = t->next; t->next = NULL; QUEUEput(t);}
   t = QUEUEget();
   while (!QUEUEempty())
    { QUEUEput(t); t = merge(QUEUEget(), QUEUEget());}
   return t;
 }
   

void show(link t)
{
   
   for(;t != NULL; t = t->next) { printf("%d\t", t->item); }
   printf("\n");
}
