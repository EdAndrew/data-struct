SearchTree MakeEmpty(SearchTree t)
{
	if (t != NULL)
	{
		MakeEmpty(t->left);
		MakeEmpty(t->right);
		free(t);
	}
	return NULL;
}

SearchTree Find(ElementType e, SearchTree t)
{
	if (t == NULL)
		return NULL;
	if (t->element < e)
		return Find(e, t->right);
	else if (e < t->element)
		return Find(e, t->left);
	else
		return t;
}

S







	
