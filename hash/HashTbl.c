#include "HashTbl.h"

HashTable InitializeTable(int size)
{
	HashTable ht;
	int i;

	if (size < MinTableSize)
		fatal_error("Table size is too small");

	ht = malloc(sizeof(struct HashTbl));
	if (ht == NULL)
		fatal_error("out of memory");
	
	ht->size = NextPrime(size);
	ht->lists = malloc(sizeof(struct List) * ht->size);
	if (ht->lists == NULL)
		fatal_error("out of memory");

	for (i = 0; i < ht->size; ++i)
	{
		ht->lists[i] = malloc(sizeof(struct ListNode));
		if (ht->lists[i] == NULL)
			fatal_error("out of memory");
		ht->lists[i]->next = NULL;
	}
	return ht;
}







