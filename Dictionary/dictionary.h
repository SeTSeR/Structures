#include <stdlib.h>

typedef int Type;
typedef char* KeyType;

typedef struct
{
	KeyType key;
	Type value;
} node;

typedef struct
{
	node* first;
	int size;
	int factsize;
} dictionary;

dictionary* createDictionary();
void deleteDictionaru(dictionary*);
dictionary* insertElement(dictionary*, Type, KeyType);
dictionary* deleteElement(dictionary*, KeyType);
Type getElement(keyType);
int getSize(dictionary*);
