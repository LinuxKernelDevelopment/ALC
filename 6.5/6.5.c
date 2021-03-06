#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(B, A)
void sort(Item a[], int l, int r)
{ int i, j;
  for (i = l + 1; i <= r; i++)
   for (j = i; j > l; j--)
    compexch(a[j-1], a[j]);
}

void selection(Item a[], int l, int r)
{ int i, j;
  for (i = l; i < r; i++)
  { int min = i;
    for ( j = i+1; j <= r; j++)
        if (less(a[j], a[min])) min = j;
    exch(a[i], a[min]);
  }
  
}

void insertion(Item a[], int l, int r)
{ int i;
  for (i = r; i > l; i--) compexch(a[i-1], a[i]);
  for (i = l+2; i <= r; i++)
  {  int j = i;  Item v = a[i];
     while (less(v, a[j-1]))
     { a[j] = a[j-1]; j--;}
     a[j] = v;
  }
}

void bubble(Item a[], int l, int r)
{ int i, j;
  for (i = l; i < r; i++)
   for (j = r; j > i; j--)
     compexch(a[j-1], a[j]);
}

void shellsort(Item a[], int l, int r)
{ int i, j, h;
  for (h = 1; h <= (r-1)/9; h = 3*h+1) ;
  for (; h > 0; h /= 3)
    for (i = l+h; i <= r; i++)
     { int j = i; Item v = a[j];
       while (j >= l+h && less(v, a[j-h]))
       { a[j] = a[j-h]; j -= h; }
       a[j] = v;
     }
}
  

main(int argc, char *argv[])
{ int i, N = atoi(argv[1]), sw = atoi(argv[2]);
  int *a = malloc(N*sizeof(int));
  if (sw)
     for (i = 0; i < N; i++)
       a[i] = 1000*(1.0*rand()/RAND_MAX);
  else
     while (scanf("%d", &a[N]) == 1) N++;
  //sort(a, 0, N-1);
  //selection(a, 0, N-1);
  //bubble(a, 0, N-1);
  //insertion(a, 0, N-1);
  shellsort(a, 0, N-1);
  for (i = 0; i < N; i++) printf("%3d ", a[i]);
  printf("\n");
}
