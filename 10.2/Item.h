#include "digit.h"
typedef char* Item;
#define key(A, w) digit(A, w)
#define less(A, B, w) (key(A, w) < key(B, w))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B, w) if (less(B, A, w)) exch(A, B)
//Item ITEMrand(void);
// int ITEMscan(Item *);
//void ITEMshow(Item);
