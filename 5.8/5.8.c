#include <stdio.h>
#include <math.h>

void mark(int l, int m, int h)
{ 
   if(m > l) 
   printf("%d's height is %d\n", m, h);
}

void rule(int l, int r, int h)
{
   int m = (l + r)/2;
   if(h > 0)
     {
        rule(l, m, h - 1);
        mark(l, m, h);
        rule(m, r, h - 1);
     }
}

int main(void)
{
   rule(1, 9, 5);
}
