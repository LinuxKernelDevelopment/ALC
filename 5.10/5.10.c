#include <stdio.h>
#include <math.h>

int F(int i)
{
   if (i < 1) return 0;
   if (i == 1) return 1;
   return F(i - 1) + F(i - 2);
}

int main(void)
{
   printf("F(45) is %d\n", F(45));
}
