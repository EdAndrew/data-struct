#include "list.h"

int IsEmpty(List l)
{
	return l->next == NULL;
}

int IsLast(Position p, List l)
{
	return p->next == NULL;
}

Position Find(ElementType e, List l)
{
	l = l->next;
	while (l != NULL && l->element != e)
		l = l->next;
	return l;
}

void Delete(ElementType e, List l)
{
	Position d = FindPrev(e, l);
	Position tmp;
	if (!IsLast(d, l))
	{
		tmp = d->next;
		d->next = tmp->next;
		free(tmp);		
	}
}

Position FindPrev(ElementType e, List l)
{
	while(l->next != NULL && l->next->element != e)
		l = l->next;
	return l;
}

//insert after this node
void Insert(ElementType e, List l, Position p)
{
	Position tmp;
	tmp = (Position)malloc(sizeof(struct Node));
	if (tmp == NULL)
		FatalError("out of space.");
	tmp->element = e;
	tmp->next = p->next;
	p->next = tmp;	
}





	
