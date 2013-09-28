#include <string.h>
typedef char *Item;
#define maxKey 100;
#define key(A) (A)
#define eq(A, B) (strcmp(key(A), key(B)) == 0)
#define less(A, B) (strcmp(key(A), key(B)) < 0)
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define NULLitem 0
Item ITEMrand(void);
 int ITEMscan(Item *);
void ITEMshow(Item);
