#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include <fcntl.h>
#include "ST.h"
#define Key Item

#define maxN 200000000
#define maxQ 20
#define null(A) (eq(key(A), key(NULLitem)))
static char text[maxN];
main(int argc, char *argv[])
  { int i, t, N = 0; char query[maxQ]; char *v;
    printf("test1\n");
    FILE *corpus = open(*++argv, O_RDONLY);
    printf("test2\n");
    printf("%d\n", getc(corpus));
    while ((t = getc(corpus)) != EOF)
      if (N < maxN-1) text[N++] = t; else break;
    text[N] = '\0';
    STinit(maxN);
    for (i = 0; i < N; i++) STinsert(&text[i]);
    while (gets(query) != NULL)
      if (!null(v = STsearch(query)))
           printf("%11d %s\n", v-text, query);
      else printf("(not found) %s\n", query);
  }
