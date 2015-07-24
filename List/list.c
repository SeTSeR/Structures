#include "list.h"

list* createList()
{
	list* x;
	node* b;
	b = malloc(sizeof(node));
	x = malloc(sizeof(list));
	b->value = 0;
	b->next = NULL;
	b->prev = NULL;
	x->first = b;
	return x;
}

void deleteList(list* toDel)
{
	node* x = toDel->first;
	node* y = NULL;
	while(y!=toDel->first)
	{
		while(x!=NULL)
		{
			y = x;
			x = x->next;
		}
		y->value = 0;
		x = y;
		y = y->prev;
		free(x);
		x = NULL;
	}
	free(toDel->first);	
}

list* addElement(list* l, Type e)
{
	node* x;
	x = malloc(sizeof(node));
	l->first->prev = x;
	x->next = l->first;
	x->prev = NULL;
	x->value = e;
	l->first = x;
	return l;
}

Type head(list* l)
{
	return (l->first->value);
}

list* tail(list* l)
{
	node* x = l->first;
	x->prev = NULL;
	l->first = x->next;
	free(x);
	return l;
}
