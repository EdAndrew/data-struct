#include "avl_tree.h"

static int Height(Position p)
{
	if (p == NULL)
		return -1;
	return p->height;
}

AvlTree SingleRotateWithLeft(AvlTree t)
{

}


AvlTree Insert(ElementType e, AvlTree t)
{
	if (t == NULL)
	{
		t = malloc(sizeof(struct AvlNode));
		if (t == NULL)
			fatal_error("out of memory");
		t->element = e;
		t->height = 0;
		t->left = NULL;
		t->right = NULL;	
	}
	else if (t->element < e)
	{
		t->right = Insert(e, t->right);
		if (Height(t->right) - Height(t->left) == 2)
		{
			if (t->right->element < e) // why don't consider equal?
				t = SingleRotateWithRight(t);
			else
				t = DoubleRotateWithRight(t);
		}	
	}
	else if (e < t->element)
	{
		t->left = Insert(e, t->left);
		if (Height(t->left) - Height(t->right) == 2)
		{
			if (e < t->left->element)
				t = SingleRotatWithLeft(t);
			else
				t = DoubleRotateWithLeft(t);
		}
	}
	t->height = max(Height(t->left), Height(t->right));
	
	return t;
}

static Position SingleRotateWithLeft(Position k2)
{
	Position k1, tmp;
	k1 = k2->left;
	tmp = k1->right;
	k1->right = k2;
	k2->left = tmp;
	k2->height = max(Height(k2->left), Height(k2->right)) + 1;	
	k1->height = max(Height(k1->left), Height(k1->right)) + 1;	

	return k1;	
}

static Position DoubleRotateWithLeft(Position k3)
{
	k3->left = SingleRotateWithLeft(k3->left);
	return SingleRotateWithLeft(k3);
}







