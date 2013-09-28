#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int max(int *a, int n)
{
   if(n == 0)  return a[0];
   else return a[0] > max(++a, n - 1) ? a[0] : max(a, n - 1); 
   
}

int main(void)
{
   int a[10], i;
   for(i = 0; i < 100000; i++)
        a[i] = rand()%1000000;
   printf("max number is:%d\n", max(a, 10));
   return 0;
}
   
