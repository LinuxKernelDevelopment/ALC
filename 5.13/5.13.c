#include <stdio.h>
#include <stdlib.h>

typedef struct {char thing; int size; int val;} Item;
Item item[5];
#define N 5;
#define unknown 0
int maxKnown[50]={0,0};
Item itemKnown[50]={0,0};

int knap(int M)
{ int i, space, max, maxi, t;
  if (maxKnown[M] != unknown) return  maxKnown[M];
  for (i = 0, max = 0; i < 5; i++)
    if ((space = M - item[i].size) >= 0)
      if ((t = knap(space) + item[i].val) > max)
      {
           max = t;
           maxi = i;
           printf("max is %d\n", max);
      }
  maxKnown[M] = max; itemKnown[M] = item[maxi];
  return max;
}


void init(Item *ITEM)
{
  int i;
  for(i = 0; i < 5; i++) {ITEM[i].thing = 65 + i; }
  ITEM[0].size = 3;
  ITEM[0].val = 4;
  ITEM[1].size = 4;
  ITEM[1].val = 5;
  ITEM[2].size = 7;
  ITEM[2].val = 10;
  ITEM[3].size = 8;
  ITEM[3].val = 11;
  ITEM[4].size = 9;
  ITEM[4].val = 13;
}

int main(void)
{
   init(item);
   knap(17);
   return 0;
}

