typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
Item ITEMrand(void);
 int ITEMscan(Item *);
void ITEMshow(Item);
//void shuffle(Item *, int , int);
//void unshuffle(Item *, int, int);