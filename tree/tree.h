#ifndef _TREE_H
#define _TREE_H

typedef struct TreeNode *PtrToNode;
typedef struct PtrToNode Position;
typedef PtrToNode Tree;
typedef PtrToNode SearchTree;

struct TreeNode
{
	ElementType element;
	PtrToNode left;
	PtrToNode right;
};

#endif
