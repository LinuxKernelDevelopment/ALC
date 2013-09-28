#include <stdlib.h>
#include "UF.h"
static int *id, *sz;
int head;
int time;
void UFinit(int N)
{ int i;
  id = malloc(N*sizeof(int));
  sz = malloc(N*sizeof(int));
  for ( i = 0; i < N; i++)
    { id[i] = i; sz[i] = 1; }
}

static int find(int x)
{ int i = x;
  while ( i != id[i]) i = id[i]; return i;}

void UF_display(int x)
{
  int i = x;
  while (i != id[i]) {printf("%d\t", i);  i = id[i]; }
  printf("%d\n", i);
}

int UFfind(int p, int q)
 { return (find(p) == find(q)); }

int UFunion(int p, int q)
{ int i = find(p), j = find(q);
  time++;
  if (i == j) return;
 if(time == 1)
  head = sz[i] > sz[j] ? i : j;
 else
  head = sz[i] > sz[j] ? head : j;
  if (sz[i] > sz[j])
     {  id[i] = j; sz[j] += sz[i]; }
  else {  id[j] = i; sz[i] += sz[j]; }
  return head;
}
 
void UF_debug(int N)
{
   int i;
   for(i = 0; i < N; i++) printf("%d\t%d\t%d\n", i, id[i], sz[i]);
}
   
