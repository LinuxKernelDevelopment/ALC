typedef int item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
item ITEMrand(void);
 int ITEMscan(item *);
void ITEMshow(item);
