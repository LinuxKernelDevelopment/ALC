#include <stdio.h>
#include <stdlib.h>

typedef struct {char thing; int size; int val;} Item;
Item item[5];
#define N 5;


int knap(int cap)
{ int i, space, max, t;
  for (i = 0, max = 0; i < 5; i++)
    if ((space = cap - item[i].size) >= 0)
      if ((t = knap(space) + item[i].val) > max)
      {
           max = t;
           printf("max is %d\n", max);
      }
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
