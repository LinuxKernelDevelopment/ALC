#include "PQindex.h"
#include "element.h"
typedef int Item;


int less(int i, int j)
{
   return data[i].grade < data[j].grade;
}
fixUp(Item a[], int k)
 {
  while (k > 1 && less(a[k/2], a[k]))
   { exch(a[k], a[k/2]); k = k/2;}
 }

fixDown(Item a[], int k, int N)
  { int j;
    while (2*k <= N)
     { j = 2*k;
       if (j < N && less(a[j], a[j+1])) j++;
       if (!less(a[k], a[j])) break;
       exch(a[k], a[j]); k = j;
     }

  }

static int  N, pq[maxPQ+1]; qp[maxPQ+1];
void exch(int i, int j)
  { int t;
    t = qp[i]; qp[i] = qp[j]; qp[j] = t;
    pq[qp[i]] = i; pq[qp[j]] = j;
  }
void PQinit() { N = 0; }
 int PQempty() { return !N; }
void PQinsert(int k)
  { qp[k] = ++N; pq[N] = k; fixUp(pq, N); }
 int PQdelmax()
  {
    exch(pq[1], pq[N]);
    fixDown(pq, 1, --N);
    return pq[N+1];
  }
void PQchange(int k)
  { fixUp(pq, qp[k]); fixDown(pq, qp[k], N); }

void test()
  { ITEMshow(data[pq[1]]); }

