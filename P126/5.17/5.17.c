#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;
struct node { int item; link next;};

int max(link t)
{
   if(t->next == NULL) return t->item;
   else return t->item > max(t->next) ? t->item : max(t->next);
}

int main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]), M = atoi(argv[2]);
    link t = malloc(sizeof *t), x = t;
    t->item = 1;
    for(i = 2; i <= N; i++)
    {
       x = (x->next = malloc(sizeof *x));
       x->item = rand() % M; x->next = NULL;
    }
    printf("the max item is:%d\n", max(t));
    return 0;
}    
