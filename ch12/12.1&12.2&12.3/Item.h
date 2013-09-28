typedef int Item;
#define maxKey 100;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define NULLitem 0
Item ITEMrand(void);
 int ITEMscan(Item *);
void ITEMshow(Item);
