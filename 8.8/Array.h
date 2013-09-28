typedef struct node *link;
struct node { Item item; link next; };
link NEW(Item, link);
link init(int);
void show(link);
void sort(link);
link findmax(link);
link h;
link partition(link, link, link);
