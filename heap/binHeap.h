#ifndef _BinHeap_H

struct Heap;
typedef struct Heap *PriorityQueue;
PriorityQueue Initialize(int maxElement);

struct Heap
{
	int capacity;
	int size;
	ElementType *elements;
}

#endif
