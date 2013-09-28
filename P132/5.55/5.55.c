#include <stdio.h>
#include <stdlib.h>

int F(int N, int k)
{
   if(k == 0 || N == k) return 1;
   else return F(N - 1, k) + F(N - 1, k - 1);
}

int main(void)
{
   printf("F(N, 0)=%d\n", F(10, 0));
   printf("F(N, N)=%d\n", F(10, 10));
   printf("F(10, 5)=%d\n", F(10, 5));
}
