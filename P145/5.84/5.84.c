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

link Node(char item, link left, link right)
{
   link t = malloc(sizeof *t);
   t->value = item;
   t->l = left;
   t->r = right;
   return t;
}

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

link CreateBiTree(char* str1, char* str2, int num)
{
   int k = 0;
   char tmp;
   if(num <= 0) return NULL;
   link t = Node(str1[0], NULL, NULL);
   for(tmp = *str1; tmp != str2[k]; k++) ;
   t->l = CreateBiTree(str1 + 1, str2, k);
   t->r = CreateBiTree(str1 + k +1, str2 + k + 1, num - k -1);
   return t;
}

int main(void)
{
   link t;
   char *str1, str2;
   str1 = malloc(9 * sizeof(char));
   str2 = malloc(9 * sizeof(char));
   printf("please input str1:");
   scanf("%s", str1);
   printf("\n");
   printf("please input str2:");
   scanf("%s", str2);
   printf("\n");
   t = CreateBiTree("EDBACHFG", "ABCDEFGH", 8);
   traverse(t, visit);
   return 0;
}
      
