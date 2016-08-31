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

SearchTree FindMin(SearchTree t)
{
	if (t->left == NULL)
		return t;
	return FindMin(t->left);
}	

SearchTree FindMax(SearchTree t)
{
	if (t->right == NULL)
		return t;
	return FindMax(t->right);
}	

SearchTree Insert(ElementType e, SearchTree t)
{
	if (t == NULL)
	{
		t = malloc(sizeof(struct TreeNode));
		if (t = NULL)
			fatal_error("out of memory");
		t->element = e;
		t->left = NULL;
		t->right = NULL;
	}
	if (t->element < e)
		t->right = Insert(e, t->right);
	else if (e < t->element)
		t->left = Insert(e, t->left);

	return t;	
}

SearchTree Delete(ElementType e, SearchTree t)
{
	SearchTree tmp;
	if (t == NULL)
		fatal_error("node not exist.");
	if (t->element < e)
		t->right = Delete(e, t->right);
	else if (t->element > e)
		t->left = Delete(e, t->left);
	else
	{
		if (!t->left && !t->right)
		{
			free(t);
			t = NULL;
		}
		else if (t->left && !t->right)
		{
			tmp = t;
			t = t->left;
			free(tmp);
		}
		else if (!t->left && t->right)
		{
			tmp = t;
			t = t->right;
			free(tmp);
		}
		else
		{
			tmp = FindMin(t->right);
			t->element = tmp->element;
			t->right = Delete(t->element, t->right);
		}
	}
	
	return t;	
}




















