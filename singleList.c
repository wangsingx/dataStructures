#include <stdio.h>
#include <stdlib.h>
#include "singleList.h"

pNode sListSearch(sList list, int value)
{
	if(!list)
		return NULL;
	pNode p = list->next;
	while(p)
	{
		if(p->value == value)
			return p;
		p = p->next;
	}
	return NULL;
}

void sListDelete(sList list)
{
	if(!list)
		return;

	pNode p = list->next;
	pNode tmp;
	while(p)
	{
		tmp = p;
		p = p->next;
		tmp->next = NULL;
		free(tmp);
	}
	list->next = NULL;
}

void sListAppend(sList list, int value, pNode p)
{
	if(!list || !p)
		return;
	pNode tmp;
	tmp = (pNode) malloc(sizeof(struct node));
	tmp->value = value;
	tmp->next = p->next;
	p->next = tmp;
}

void sListRemove(sList list, int value)
{
	if(!list)
		return;

	pNode p, tmp;
	p = list;
	while(p->next)
	{
		if(p->next->value == value)
		{
			tmp = p->next;
			p->next = tmp->next;
			tmp->next = NULL;
			free(tmp);
			return ;
		}
		p = p->next;
	}
}

void sListPrint(sList list)
{
	if(!list)
		return;

	pNode p = list->next;
	while(p)
	{
		printf("%4d  ",p->value);
		p = p->next;
	}
	printf("\n");
}

