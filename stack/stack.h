#ifndef _STACK_H
#define _STACK_H

struct Node;
typedef struct Node *PtrToNode;
Typedef PtrToNode Stack;

int IsEmpty(Stack s);


struct Node
{
	ElementType element;
	Position next;
};

#endif
