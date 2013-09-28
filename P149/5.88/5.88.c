#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node* link;
typedef struct node {char value; link l, r;};

int deep = 1, max = 100;

void visit(link t)
{ printf("the value of the node is %c\n", t->value);}

int count(link h)
{
  if (h == NULL) return 0;
  return count(h->l) + count(h->r) + 1;
}

int height(link h)
{ int u, v;
  if(h == NULL) return -1;
  u = height(h->l); v = height(h->r);
  if(u > v) return u + 1; else return v + 1;
}
int tem1 = 0, tem2 = 0;
int in_way(link h, int count)
{
  printf("count:%d\n", count);
  //printf("%c -- %d\n", h->value, count);
  if(h == NULL) return 0;
  if(h->l == NULL && h->r == NULL) return 0;
  tem1 = in_way(h->l, ++count);
  count--;
  tem2 = in_way(h->r, ++count);
  
  //printf("%c ------- %d\n", h->value, count);
  if(h->l != NULL || h->r != NULL) return count + tem1 + tem2;
 
}
static int allpath = 0;
void Path(link h, int hight)
{
  if(!h) return;
  else if(h->l || h->r)
  {
    allpath += hight;
    Path(h->l, hight++);
    Path(h->r, hight++);
  }
}
int countleaf(link t)
{
  if(t == NULL) return 0;
  if(t->l == NULL && t->r == NULL)  return 1;
  return countleaf(t->r) + countleaf(t->l); 
}
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
   t = CreateBiTree("EDBACHFG", "ABCDEFGH", 8);
   traverse(t, visit);
   printf("the height of the tree is %d\n", height(t));
   printf("the count of the tree is %d\n", count(t));
   printf("the leaf of the tree is %d\n", countleaf(t));
   printf("the in way of the tree is %d\n",in_way(t, 0));
   Path(t, 0);
   printf("the path of the tree is %d\n", allpath);
   return 0;
}
      
