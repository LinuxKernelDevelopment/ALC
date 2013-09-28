#define maxBQsize 100
typedef struct pq* PQ;
typedef struct PQnode* PQlink;
struct PQnode {int key; PQlink l, r;};
struct pq {PQlink *bq;};
//PQnode Pority[maxBQsize];

PQlink pair(PQlink , PQlink);
PQlink PQinsert(PQ, int);
int PQdelmax(PQ);
void PQjoin(PQ, PQ);
