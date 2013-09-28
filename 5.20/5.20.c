#include <stdio.h>
#include <stdlib.h>

char *a; int i;
typedef struct Tnode* link;
struct Tnode { char token; link l, r; };
link NEW(char token, link l, link r)
{ link x = malloc(sizeof *x);
  x->token = token; x->l = l; x->r = r;
  return x;
}
void traverse(link t)
{
  if(t == NULL) return;
  traverse(t->l);
  printf("%c", t->token);
  traverse(t->r);
}

link parse()
{ char t = a[i++];
  link x= NEW(t, NULL, NULL);
  if ((t == '+') || (t == '*'))
    { x->l = parse(); x->r = parse(); }
  return x;
}

int main(void)
{ 
  a = malloc(sizeof(char) * 12);
  a = "*+a**bc+def";
  i = 0;
  link t = parse();
  traverse(t);
  printf("\n"); 
}
