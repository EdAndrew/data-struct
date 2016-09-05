#include "HashQuad.h"

HashTable InitializeTable(int size)
{
	HashTable h;
	int i;

	if (size < MinTableSize)
	{
		Error("Table size too small");
		return NULL;
	}

	h = malloc(sizeof(struct HashTbl));
	if (h == NULL)
	{
		Error("out of memory");
		return NULL;
	}
	h->size = NextPrime(size);
	h->cells = malloc(sizeof(Cell) * h->size);
	if (h->cells == NULL)
	{
		free(h);
		Error("out of memory");
		return NULL;
	}
	for (i = 0; i < h->size; ++i)
		h->cells[i].info = Empty;
	return h;
}
