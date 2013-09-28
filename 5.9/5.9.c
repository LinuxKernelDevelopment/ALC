#include <stdio.h>

void mark(int m, int h)
{ 
   printf("%d's height is %d\n", m, h);
}

void rule(int l, int r, int h)
{
   int i, j, t;
   for (t = 1, j = 1; t <= h; j+=j, t++)
    for (i = 0; l + j + i <= r; i += j+j)
     mark(l + j + i, t);
}

int main(void)
{
   rule(1, 5, 5);
}
