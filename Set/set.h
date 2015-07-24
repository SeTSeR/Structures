#include <stdlib.h>

typedef int Type;

typedef struct
{
	char* a;
} set;

set* createSet(int);
void deleteSet(set*);
int getIndex(Type);
set* addElement(set*, Type);
set* deleteElement(set*, Type);
char inSet(set*, Type);
