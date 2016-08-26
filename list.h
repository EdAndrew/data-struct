#ifdef _LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);


#endif

struct Node
{
	ElementType Element;
	Position next;
}
