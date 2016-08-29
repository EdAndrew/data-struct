
int IsEmpty(Stack s)
{
	return s->next == NULL;
}

Stack CreateStack()
{
	Stack head = (Stack)malloc(sizeof(struct Node));
	if (head == NULL)
		Fatal_Error("out of memory.");
	head->next = NULL;
	return head;
}

void Push(ElementType e, Stack s)
{
	PtrToNode tmp = (PtrToNode)malloc(sizeof(struct Node));
	if (tmp == NULL)
		Fatal_Error("out of memory.");
	tmp->element = e;
	tmp->next = s->next;
	s->next = tmp;
}

ElementType Top(Stack s)
{
	if (IsEmpty(s))
		Fatal_Error("empty stack.");
	return s->next->element;
}

void pop(Stack s)
{
	if (IsEmpty(s))
		Fatal_Error("empty stack."):
	PtrToNode tmp = s->next;
	s->next = tmp->next;
	free(tmp);
}










