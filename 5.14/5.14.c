#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node* link;
typedef struct node {char value; link l, r;};
int deep = 1;

/*void delete(link t, int val)
{
   if(t->l->value != val && t->r->value !=val) 
   {
       delete(t->l, val);
       delete(t->r, val);
   }
   if(t->l->value == val) t->l = t->l->l;
   if(t->r->value == val) t->r = t->r->r; 
   if(t->l == NULL && t->r == NULL) return;
}*/

void visit(link t)
{ printf("the value of the node is %c\n", t->value);}

void traverse(link h, void (*visit)(link))
{
  if (h == NULL) return;
  (*visit)(h);
  //printf("%c", h->value);
  traverse(h->l, visit);
  traverse(h->r, visit);
}

/*link CreateBiTree(link t)
{
   link tem = t;
   tem = (link)malloc(sizeof(struct node));
   tem->l = tem->r =NULL;
   int  flag;
   char ch;
   if(deep == 1){ printf("please input the value of root:"); scanf("%c", &t->value);}
   else {printf("please input the value of the node:"); scanf("%c",&tem->value);}
   printf("please input the number of node:");
   scanf("%c", &ch);
   printf("please choose the way the tree head(0-left, 1-right, 2-return high level):");
   scanf("%d", &flag);
   if(flag == 0) {
                 printf("left\n"); 
                 deep++; 
                 tem->value = ch; 
                 tem -> l = CreateBiTree(tem->l);
                 printf("deep:%d\n", deep);
                 printf("please choose the way the tree head(0-left, 1-right, 2-return high level:");
                 scanf("%d", &flag);
                 }
   if(flag == 1) {
                 printf("right\n"); 
                 deep++; 
                 tem->value = ch; 
                 tem -> r = CreateBiTree(tem->r); 
                 printf("deep:%d\n", deep);
                 printf("please choose the way the tree head(0-left, 1-right, 2-return high level:"); 
                 scanf("%d", &flag);
                 }
   if(flag == 2) {printf("return high level\n"); deep--; return tem;} 
   if(deep == 1) {return t;}
   return tem;
}*/

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
   printf("E's value is %c\n", t->value);
   printf("E's left child is %c\n", t->l->value);
   printf("E's right child is %c\n", t->r->value);
   printf("D's left child is %c\n", t->l->l->value);
   printf("B's left child is %c\n", t->l->l->l->value);
   printf("B's right child is %c\n", t->l->l->r->value);
   printf("H's left child is %c\n", t->r->l->value);
   printf("F's right child is %c\n", t->r->l->r->value);
   traverse(t, visit);
   return 0;
}
      
