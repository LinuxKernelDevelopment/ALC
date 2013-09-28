#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct STACKnode* Link;
typedef struct node* link;
typedef struct node {char value; link l, r;};
struct STACKnode { link item; Link next;};
static Link head;
Link NEW(link item, Link next)
{ Link x = malloc(sizeof *x);
  x->item = item; x->next = next;
  return x;
}
void STACKinit(int maxN)
{ head = NULL; }
int STACKempty()
{ return head == NULL; }
STACKpush(link item)
{ head = NEW(item, head); }
link STACKpop()
{ link item = head->item;
  Link t = head->next;
  free(head); head = t;
  return item;
}

int deep = 1, max = 100;


void visit(link t)
{ printf("the value of the node is %c\n", t->value);}

void traverser(link h)
{
  if (h == NULL) return;
  traverser(h->l);
  printf("%c", h->value);
  traverser(h->r);
}

void traverse(link h, void (*visit)(link))
{
   STACKinit(max);STACKpush(h);
   for(h; h->l != NULL; h = h->l) if(h->l != NULL) STACKpush(h->l);
   while (!STACKempty())
   {
      (*visit)(h = STACKpop());
      if (h->r != NULL) 
      {
            STACKpush(h->r);
            h = h->r; 
            for(h; h->l != NULL; h = h->l) if(h->l != NULL) STACKpush(h->l);
      }
   }
}




link CreateBiTree(link t)
{
   char ch;
   rewind(stdin);
   t = (link)malloc(sizeof(struct node));
   printf("please input the char of the data:");
   if(deep!=1) ch = getchar();
   ch = getchar();
   t->value = ch;
   int flag;
   printf("please choose the way it grows(0-left, 1-right, 2-return high level):");
   scanf("%d", &flag);
   if(flag == 0) { deep++; t->l = CreateBiTree(t->l); printf("choose:"); scanf("%d",&flag); }
   if(flag == 1) { deep++; t->r = CreateBiTree(t->r); printf("choose:"); scanf("%d",&flag); }
   printf("deep is %d\n", --deep);
   return t;
}

int main(void)
{
   link t;
   
   t = CreateBiTree(t);
   traverser(t);
   printf("\n");
   traverse(t, visit);
   return 0;
}
      
