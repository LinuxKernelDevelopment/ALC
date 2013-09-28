typedef struct element{ char *name; int grade; } ITEM;
#define key(A) (A.grade)
//#define less(A, B) (key(A) < key(B))
//#define exch(A, B) { ITEM t = A;  A = B; B = t; }
void ITEMscan(ITEM);
void ITEMshow(ITEM);
ITEM data[11];
