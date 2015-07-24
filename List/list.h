#include <stdlib.h>

typedef int Type;

typedef struct
{
	Type value;
	struct node *next;
	struct node *prev;
} node;

typedef struct
{
	node* first;
} list;

list* createList();
void deleteList(list*);
list* addElement(list*, Type);
Type head(list*);
list* tail(list*);
