#ifndef _SINGLE_LIST_H
#define _SINGLE_LIST_H


struct node;
typedef struct node * pNode;
typedef pNode sList;

struct node
{
	int value;
	pNode next;
};

pNode sListSearch(sList l, int v);
void sListDelete(sList l);
void sListAppend(sList l, int v, pNode p);
void sListRemove(sList l, int v);
void sListPrint(sList l);

#endif //_SINGLE_LIST_H
