#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "Array.h"

main()
{
 int i = 0;
 PQinit(100);
 for (i; i < 100; i++) PQinsert(rand()%100);
 for (i = 0; i < 100; i++) printf("%d\t", PQdelmax());
 PQshow();
}
