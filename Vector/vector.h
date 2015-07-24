#include <stdlib.h>

#ifndef MINSIZE
	#define MINSIZE 100
#endif

typedef int Type;

typedef struct
{
	int size;
	int factsize;
	Type* first;
} vector;

vector* createVector();
void deleteVector(vector*);
vector* insertElement(vector*, int, Type);
vector* deleteElement(vector*, int);
int getSize(vector*);
vector* pushBack(vector*, Type);
Type pop(vector*);
