#ifndef _HashQuad_H
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

enum KindOfEntry {Legitimate, Empty, Deleted};

struct HashEntry
{
	ElementType e;
	enum KindOfEntry info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
	int size;
	Cell *cells;
};

#endif
