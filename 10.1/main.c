#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include "Item.h"
#include "sort.h"

int main(void)
{
   char a[100], i;
   //char s[10];
   //int t;
   for(i = 0; i < 100; i++) a[i] = ITEMrand();
   //for(i = 0; i < 100; i++) printf("%d\n", a[i]);
   //for(i = 0; i < 100; i++) printf("%x\t%d\n", a[i], digit(a[i], 0));
   printf("%d\n", sizeof(char));
   printf("%d\t%d\n", 255, digit(255, 1));
   sort(a, 0, 99);
   for(i = 0; i < 100; i++) {while(a[i] > 0) {int t = a[i] % 2; printf("%d",t); a[i]/=2;}   printf("\n");}
}
