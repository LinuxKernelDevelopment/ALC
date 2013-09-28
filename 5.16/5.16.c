#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node* link;
typedef struct node {char value; link l, r;};

int deep = 1, max = 100;

void visit(link t)
{ printf("the value of the node is %c\n", t->value);}

/*void traverse(link h, void (*visit)(link))
{
  if (h == NULL) return;
  (*visit)(h);
  //printf("%c", h->value);
  traverse(h->l, visit);
  traverse(h->r, visit);
}*/

/*void traverse(link h, void (*visit)(link))
{
   STACKinit(max); STACKpush(h);
   while (!STACKempty())
   {
      (*visit)(h = STACKpop());
      if (h->r != NULL) STACKpush(h->r);
      if (h->l != NULL) STACKpush(h->l);
   }
}*/

static link *q;
static int N, head, tail;
void QUEUEinit(int maxN)
{ q = malloc((maxN+1)*sizeof(link));
  N = maxN+1; head = N; tail =0;
}

int QUEUEempty()
{return head % N == tail; }
void QUEUEput(link item)
{ q[tail++] = item; tail = tail % N; }
link QUEUEget()
{ head = head % N; return q[head++]; }

void traverse(link h, void (*visit)(link))
{
 QUEUEinit(max); QUEUEput(h);
 while (!QUEUEempty())
 {
   (*visit)(h = QUEUEget());
   if (h->l != NULL) QUEUEput(h->l);
   if (h->r != NULL) QUEUEput(h->r);
 }
}

link CreateBiTree(link t)
{
   char ch;
   rewind(stdin);
   t = (link)malloc(sizeof(struct node));
   printf("please input the char of the data:");
   if(deep != 1) ch = getchar();
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
   //t = (link) malloc(sizeof(struct node));
   //t->value = 0;
   t = CreateBiTree(t);
   /*printf("E's value is %c\n", t->value);
   printf("E's left child is %c\n", t->l->value);
   printf("E's right child is %c\n", t->r->value);
   printf("D's left child is %c\n", t->l->l->value);
   printf("B's left child is %c\n", t->l->l->l->value);
   printf("B's right child is %c\n", t->l->l->r->value);
   printf("H's left child is %c\n", t->r->l->value);
   printf("F's right child is %c\n", t->r->l->r->value);*/
   traverse(t, visit);
   return 0;
}
      
