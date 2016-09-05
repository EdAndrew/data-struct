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

Position Find(ElementType key, HashTable h)
{
	Position p;
	List l;
		
	l = h->lists[Hash(key, h->size)];
	p = l->next;
	while (p != NULL && p->e != key)
		p = p->next;
	return p;
}

void Insert(ElementType key, HashTable h)
{
	Position p;
	List l;

	p = Find(key, h);
	if (p == NULL)
	{
		l = h->lists[Hash(key, h->size)];
		p = malloc(sizeof(struct ListNode));
		if (p == NULL)
			fatal_error("out of memory.");
		p->next = l->next;
		p->element = key;
		l->next = p;
	}	
}

void Delete(ElementType key, HashTable h)
{
	Position p, tmp;
	List l;
	
	l = h->lists[Hash(key, h->size)];
	p = l;
	while(p->next != NULL && p->next->e != key)
		p = p->next;
	if (p->next != NULL)
	{
		tmp = p->next;
		p->next = tmp->next;
		free(tmp);	
	}
}



























































	


