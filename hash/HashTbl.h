#ifndef _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

struct ListNode
{
	ElementType e;
	Position next;
};

typedef Position List;

struct HashTbl
{
	int size;
	List *lists;
};










