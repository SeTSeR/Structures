#include "dictionary.h"

dictionary* createDictionary()
{
	dictionary* x = malloc(sizeof(dictionary));
	x->size = MINSIZE;
	x->factsize = 0;
	x->first = malloc((x->size)*sizeof(node));
	x->first->key = "";
	x->first->value = 0;
	return x;
}

void deleteDictionary(dictionary* vect)
{
	int i;
	for(i = vect->factsize; i>=0; i--)
	{
		*(vect->first + i) = 0;
	}
	vect->factsize = 0;
	free(vect->first);
	vect->size = 0;
}

dictionary* addElement(dictionary* vect, KeyType index, Type element)
{
	if(++(vect->factsize)>(vect->size))
	{
		vect->size*=2;
		vect->first = realloc(vect->first, (vect->size)*sizeof(Type));
	}
	if(*(vect->first + index))
	{
		int i;
		int tmp;
		tmp = *(vect->first + index);
		for(i = (index+1); i<(vect->factsize); i++)
		{
			*(vect->first + i) = tmp;
			tmp = *(vect->first + (i+1));
		}
	}
	*(vect->first + index) = element;
	return vect;
}

dictionary* deleteElement(dictionary* vect, int index)
{
	*(vect->first + index) = 0;
	if(*(vect->first + (index+1)))
	{
		int i;
		int tmp;
		tmp = *(vect->first+(index+1));
		for(i = index; i<(--(vect->factsize)); i++)
		{
			*(vect->first + i) = tmp;
			tmp = *(vect->first + (i+2));
		}
	}
	return vect;
}

int getSize(dictionary* vect)
{
	return vect->factsize;
}
