#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "singleList.h"

sList initSingleList(int *num, int count)
{
	sList list;
	pNode newp,p;
	list = calloc(sizeof(struct node), 1);
	p = list;
	while(count--)
	{
		newp = malloc(sizeof(struct node));
		newp->value = *num++;
		newp->next = NULL;
		p->next = newp;
		p = newp;
	}
	return list;
}

void sListAppendTest(sList list, int *num, int count)
{
	pNode p = list->next;
	while(count--)
	{
		p = p->next->next;
		sListAppend(list, *num++, p);
	}
}

void sListRemoveTest(sList list, int *num, int count)
{
	while(count--)
	{
		sListRemove(list, *num++);
		num++;
	}
}

void sListSearchTest(sList list, int *num, int count)
{
	while(count--)
	{
		printf("value:%4d ",*num);
		if(sListSearch(list, *num++))
			printf("have found\n");
		else
			printf("not found\n");
	}
}

int main(int argc, char **argv)
{
    int *num = randNum(10,500);
	sList list = initSingleList(num, 10);
	sListPrint(list);

//	sListAppendTest(list, num, 10);
//	sListRemoveTest(list, num+3, 2);
//	sListSearchTest(list, num, 5);

	sListPrint(list);

	sListDelete(list);
	free(num);
	return 0;
}

