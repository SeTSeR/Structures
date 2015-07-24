#include "set.h"

set* createSet(int count)
{
	char* a = malloc(count*sizeof(char));
	set* x = malloc(sizeof(set));
	x->a = a;
	return x;
}

void deleteSet(set* x)
{
	free(x->a);
}

int getIndex(Type element)
{
	return 0;
}

set* addElement(set* x, Type element)
{
	int index = getIndex(element);
	*(x->a+index) = 1;
	return x;
}

set* deleteElement(set* x, Type element)
{
	int index = getIndex(element);
	*(x->a+index) = 0;
	return x;
}

char inSet(set* x, Type element)
{
	int index = getIndex(element);
	return *(x->a+index);
}
