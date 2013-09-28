#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"
#include "item.h"
//#define item int

//void BQjoin(PQlink*, PQlink*);
PQlink pair(PQlink p, PQlink q)
  {
    if (less(p->key, q->key))
         { p->r = q->l; q->l = p; return q; }
    else {q->r = p->l; p->l = q; return p; }
  }

#define z NULL
PQlink PQinsert(PQ pq, item v)
  { int i; PQlink c, t = malloc(sizeof *t);
    c = t; c->l = z; c->r = z; c->key = v;
    for (i = 0; i < maxBQsize; i++)
    {
      if (c == z) break;
      if (pq->bq[i] == z)
        { pq->bq[i] = c; break; }
      c = pair(c, pq->bq[i]); pq->bq[i] = z;
    }
   return t;
  }

item PQdelmax(PQ pq)
  { int i, max; PQlink x; item v;
    PQlink temp[maxBQsize];
    for (i = 0, max = -1; i < maxBQsize; i++) 
      if (pq->bq[i] != z)
        if ((max == -1) || less(v, pq->bq[i]->key))
          { max = i; v = pq->bq[max]->key; }
    x = pq->bq[max]->l;
    for (i = max; i < maxBQsize; i++) temp[i] = z;
    for (i = max; i > 0; i--)
      { temp[i-1] = x; x = x->r; temp[i-1]->r =z; }
    free(pq->bq[max]); pq->bq[max] = z;
    BQjoin(pq->bq, temp);
    return v;
  }

#define test(C, B, A) 4*(C) + 2*(B) + 1*(A)
void BQjoin(PQlink *a, PQlink *b)
  { int i; PQlink c = z;
    for (i = 0; i < maxBQsize; i++)
      switch(test(c != z, b[i] != z, a[i] != z))
        {
          case 2: a[i] = b[i]; break;
          case 3: c = pair(a[i], b[i]);
                  a[i] = z; break;
          case 4: a[i] = c; c = z; break;
          case 5: c = pair(c, a[i]);
                  a[i] = z; break;
          case 6:
          case 7: c = pair(c, b[i]); break;
        }
  }
void PQjoin(PQ a, PQ b)
  { BQjoin(a->bq, b->bq); }
