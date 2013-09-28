#include <stdio.h>
#include <math.h>
#define unknown 0

int knownF[46];
int F(int i)
{
    int t;
    if (knownF[i] != unknown) return knownF[i];
    if (i == 0) t = 0;
    if (i == 1) t = 1;
    if (i > 1)  t = F(i-1) + F(i-2);
    return knownF[i] = t;
}

int main(void)
{
  int i;
  for(i = 0; i < 46; i++) knownF[i] = 0;
  printf("F(45) is %d\n", F(45));
  return 0;
}
