typedef char Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define bitsword 32
#define bitsbyte 8
#define bytesword 4
#define R (1 << bitsbyte)
//#define digit(A, B) ((A) & (1 << (bitsword - B - 1)))
#define digit(A, B)  ((A) & (1<<8-(B)-1)>>(8 - (B) -1))
Item ITEMrand(void);
 char ITEMscan(Item *);
void ITEMshow(Item);
