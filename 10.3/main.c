#include <stdio.h>
#include <stdlib.h>

#include "Item.h"

void init(Item *a)
{
  int i;
  for(i = 0; i < 34; i++) a[i] = malloc(sizeof(char) * 4);
  a[0] = "now";
  a[1] = "for";
  a[2] = "tip";
  a[3] = "ilk";
  a[4] = "dim";
  a[5] = "tag";
  a[6] = "jot";
  a[7] = "sob";
  a[8] = "nob";
  a[9] = "sky";
  a[10] = "hut";
  a[11] = "ace";
  a[12] = "bet";
  a[13] = "men";
  a[14] = "egg";
  a[15] = "few";
  a[16] = "jay";
  a[17] = "owl";
  a[18] = "joy";
  a[19] = "rap";
  a[20] = "gig";
  a[21] = "wee";
  a[22] = "was";
  a[23] = "cab";
  a[24] = "wad";
  a[25] = "caw";
  a[26] = "cue";
  a[27] = "fee";
  a[28] = "tap";
  a[29] = "ago";
  a[30] = "tar";
  a[31] = "jam";
  a[32] = "dug";
  a[33] = "and";
}

int main(void)
{
  int i;
  Item a[34];
  init(a);
  //printf("%c\n", a[1][1]);
  //radixMSD(a, 0, 34, 0); 
  quicksortX(a, 0, 34, 0);
  for(i = 0; i < 34; i++) printf("%s\n", a[i]);
}
