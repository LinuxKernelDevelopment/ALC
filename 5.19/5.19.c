#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {int item; link l, r};

link NEW(int item, link l, link r)
{ link x = malloc(sizeof *x);
  x->item = item; x->l = l; x->r = r;
  return x;
}

link max(int a[], int l, int r)
{ int m = (l+r)/2; int u,v;
  link x = NEW(a[m], NULL, NULL);
  if (l == r) return x;
  x->l = max(a, l, m);
  x->r = max(a, m+1, r);
  u = x->l->item; v = x->r->item;
  if (u > v)
    x->item = u; else x->item = v;
  return x;
}

int main(void)
{
  int a[100], i;
  for(i = 0; i < 100; i++) a[i] = rand()%10000;
  link t = max(a, 1, 99);
  printf("the biggest is %d\n", t->item);
  return 0;
}

