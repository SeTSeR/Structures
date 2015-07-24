#include "vector.h"

vector* createVector()
{
	vector* x = malloc(sizeof(vector));
	x->size = MINSIZE;
	x->factsize = 0;
	x->first = malloc((x->size)*sizeof(int));
	return x;
}

void deleteVector(vector* vect)
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

vector* addElement(vector* vect, int index, Type element)
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

vector* deleteElement(vector* vect, int index)
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

int getSize(vector* vect)
{
	return vect->factsize;
}

vector* pushBack(vector* vect, Type element)
{
	if(++(vect->factsize)>(vect->size))
	{
		vect->size*=2;
		vect->first = realloc(vect->first, (vect->size)*sizeof(Type));
	}
	*(vect->first + vect->factsize - 1) = element;
	return vect;
}

Type pop(vector* vect)
{
	Type result = *(vect->first + vect->factsize - 1);
	*(vect->first + vect->factsize - 1) = 0;
	vect->factsize--;
	return result;
}
