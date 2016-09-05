#ifndef _AVL_TREE_H
#define _AVL_TREE_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

struct AvlNode
{
	ElementType element;
	AvlTree left;
	AvlTree right;
	int height;
}

#endif
