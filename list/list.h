#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position p, List l);
Position Find(ElementType e, List l);
void Delete(ElementType e, List l);
Position FindPrev(ElementType p, List l);
void Insert(ElementType e, List l, Position p);
void FatalError(const char *);

struct Node
{
	ElementType element;
	Position next;
};

#endif
