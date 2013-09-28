#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node* link;
typedef struct node {int value; link l, r;};
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

link CreateBiTree(link t)
{
   link tem;
   int ch, flag;
   if(deep == 1){ printf("please input t->value:"); scanf("%d", &t->value);}
   printf("please input the number of node:");
   scanf("%d", &ch);
   printf("please choose the way the tree head(0-left, 1-right, 2-return high level):");
   scanf("%d", &flag);
   if(flag == 0) {
                 printf("left\n"); 
                 tem = (link)malloc(sizeof(struct node)); 
                 deep++; 
                 tem->value = ch; 
                 t -> l = CreateBiTree(tem); 
                 printf("deep:%d\n", deep);
                 printf("please choose the way the tree head(0-left, 1-right, 2-return high level:");
                 scanf("%d", &flag);
                 }
   if(flag == 1) {
                 printf("right\n"); 
                 tem = (link)malloc(sizeof(struct node)); 
                 deep++; 
                 tem->value = ch; 
                 t -> r = CreateBiTree(tem); 
                 printf("deep:%d\n", deep);
                 printf("please choose the way the tree head(0-left, 1-right, 2-return high level:"); 
                 scanf("%d", &flag);
                 }
   if(flag == 2) {printf("return high level\n"); deep--; return tem;} 
   return tem;
}

int main(void)
{
   link t;
   t = (link) malloc(sizeof(struct node));
   t->value = 0;
   CreateBiTree(t);
   return 0;
}
      
