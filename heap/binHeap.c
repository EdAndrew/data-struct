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
	q->elements[0] = MINELEMENT;
	return q;
}

void Insert(ElementType e, PriorityQueue q)
{
	if (q->Full())
	{
		fprintf(stderr, "heap is full.\n");
		return -1;
	}
	
	int pos;
	++q->size;
	for (pos = q->size; q->elements[pos>>1] > e; pos >> 1)
		q->elements[pos] = q->elements[pos>>1];
	q->elements[pos] = e;
}

int Full(PriorityQueue q)
{
	return q->size >= q->capacity;
}

int Empty(PriorityQueue q)
{
	return q->size == 0;
}

ElementType MinElement(PriorityQueue q)
{
	if (q->Empty())
	{
		fprintf(stderr, "heap is empty");
		return q->elements[0];
	}
	return q->elements[1];
}

void DeleteMin(PriorityQueue q)
{
	if (q->Empty())
	{
		fprintf(stderr, "heap is empty");
	}

	int pos, childPos;	
	ElementType lastElement = q->elements[q->size--];

	while (pos = 1; pos * 2 <= q->size; pos = )
	{
		childPos = pos * 2;
		if (childPos != q->size && q->element[childPos+1] < q->element[childPos])
			++childPos;

		if (q->elements[childPos] < lastElement)
			q->elements[pos] = q->elements[childPos];
		else
			break;
	}
	q->elements[pos] = lastElement;
}



















