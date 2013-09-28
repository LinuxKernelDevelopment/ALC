#include <stdio.h>
#include <stdlib.h>
#include "Item.h"


void main(void)
{Item *ch;
 int i = 0;
 ch = malloc(sizeof(char) * 12);
 //scanf("%s", ch);
 ch = "EASYQUESTION";
 //printf("b\n");
 sort(ch, 0, 11);
 //for(i; i = 0; i < sizeof(index)/sizeof(int)) printf("%d\t", index[i]);
 //printf("\n");
 //insitu(ch, 0, 11);
 test();
}
