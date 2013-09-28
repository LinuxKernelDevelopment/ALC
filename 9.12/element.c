#include <stdio.h>
#include <stdlib.h>
#include "element.h"

 void ITEMscanf(ITEM *x)
   {
     int tem;
     printf("please input name:");
     (*x).name = malloc(sizeof(char) * 10);
     scanf("%s", (*x).name);
     printf("\n");
     printf("please input grade:");
     scanf("%d", &((*x).grade));
     printf("test1\n");
     printf("\n");
   }
  void ITEMshow(ITEM x)
  { printf("%s\t%d", x.name, x.grade);  printf("\n");}
