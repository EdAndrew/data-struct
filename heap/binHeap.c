#include "binHeap.h"

PriorityQueue Initialize(int maxElement)
{
	PriorityQueue q;
	q = malloc(sizeof(struct Heap));
	if (!q)
	{
		fprintf(stderr, "out of memory.\n");
		return -1;
	}
	q->size = 0;
	q->capacity = maxElement;
	q->elements = malloc(sizeof(ElementType) * (1 + maxElement));
	if (!q->elements)
	{
		fprintf(stderr, "out of memory.\n");
		return -1;
	}
	return q;
}

void Insert(ElementType e, PriorityQueue q)
{
	if (q->Full())
	{
		fprintf(stderr, "heap is full.\n");
		return -1;
	}
	
	++q->size;
	int pos;
	for (pos = q->size; pos > 0 && q->elements[pos>>1] > e; pos >> 1)
		q->elements[pos] = q->elements[pos>>1];
	q->elements[pos] = e;
}

int Full(PriorityQueue q)
{
	return q->size >= q->capacity;
}
























