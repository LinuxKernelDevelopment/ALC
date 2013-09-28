#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "Array.h"

link NEW(Item item, link next)
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
   for(i = 0; i < n; i++) {tem = rand()%100;  t  = NEW(tem, t); printf("%d\n", t->item);}
   dummy->item = -1;
   dummy->next = t;
   show(dummy);
   return dummy;
}

/*link listselection(link h)
{ link max, t, out = NULL;
  while (h->next != NULL)
  {
      max = findmax(h);
      t = max->next; max->next = t->next;
      t->next =out; out = t;
  }
  h->next = out;
 return (h);
}

link findmax(link h)
{
  link mark, t = h;
  link p = h;
  h = h->next;
  link max = h;
  mark = p;
  for(h; h != NULL; h = h->next, p = p->next){printf("max->item:%d\n", max->item);if(h->item >= max->item) {max = h; mark = p;} printf("h->item:%d\nmax->item:%d\nmark->item:%d\n",h->item,max->item, mark->item);}
  show(t);
  //if(!max) printf("the previous of max is %d\n", max->item);
  return mark;
}*/


void quicksort(link h, link start, link end)
{
   if(start == end) return;
   link middle = partition(h, start, end);
   printf("%d\n", middle->item);
   quicksort(h, start, middle);
   quicksort(h, middle->next, end);
}

link partition(link h, link start, link end)
{
   link middle = h->next;
   h->next->next = middle->next;
   link dummy = malloc(sizeof *dummy);
   dummy->item = -1;
   dummy->next = middle;
   middle->next = NULL;
   link begin = h->next->next;
   /*for(; begin != end ; begin = begin->next) if(begin->item < middle->item) { begin->next = dummy->next; dummy->next = begin; }
                                      else {begin->next = middle->next; middle->next = begin; }*/
   link t = begin;
   link tmp;
   while(t != end)
   {
      if(t->item < middle->item) { tmp = t; t = t->next; tmp->next = dummy->next; dummy->next = tmp; }
      else { tmp = t; t = t->next; tmp->next = middle->next; middle->next = tmp; }
   }
   return middle;
}
void sort(link t)
{
 link end = t;
 for(; end->next; end = end->next);
   quicksort(t, t->next->next, end);
}
void show(link t)
{
   
   for(;t != NULL; t = t->next) { printf("%d\t", t->item); }
   printf("\n");
}
