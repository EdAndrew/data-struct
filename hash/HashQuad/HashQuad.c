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

Position Find(ElementType key, HashTable h)
{
	Position currentPos;
	int collisionNum;

	collisionNum = 0;
	currentPos = Hash(key, h->size);
	while (h->cells[currentPos]->info != empty && h->cells[currentPos]->e != key)
	{
		currentPos = (++collisionNum) << 1 - 1;
		if (currentPos >= h->size)
			currentPos -= h->size;
	}	
	return currentPos;
}

void Insert(ElementType key, HashTable h)
{
	int pos;
	pos = Find(key, h);
	if (h->cells[pos].e != Legitimate)
	{
		h->cells[pos].info = Legitimate;
		h->cells[pos].e = key;
	}
}

HashTable Rehash(HashTable h)
{
	int oldSize, i;
	Cell *oldCells = h->cells;
	oldSize = h->size;
	h->size = NextPrime(oldSize << 1);
	h->cells = malloc(sizeof(Cell) * h->size);
	if (h->cells == NULL)
	{
		Error("out of memory");
		return NULL;
	}
	for (i = 0; i < oldSize; ++i)
	{
		if (oldCells[i]->info == Legitimate)
			Insert(oldCells[i].e, h);	
	}
	free(oldCells);
	return h;	
}














