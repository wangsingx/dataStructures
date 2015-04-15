#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define MINSTACKSIZE	5
struct stack *createStack(int max)
{
	struct stack *s;
	if(max < MINSTACKSIZE)
	{
		printf("stack size too small\n");
		return NULL;
	}

	s = (struct node *)malloc(sizeof(struct stack));
	if(!s)
	{
		printf("malloc failed\n");
		return NULL;
	}

	s->array = (int *)calloc(max, sizeof(int));
	if(!s->array)
	{
		printf("malloc failed\n");
		free(s);
		return NULL;
	}
	s->capacity = max;
	makeEmpty(s);
	return s;
}

void disposeStack(struct stack *s)
{
	if(s)
	{
		if(s->array)
			free(s->array);
		free(s);
	}
}

int isEmpty(struct stack * s)
{
	if(!s)
		return (s->topOfStack == -1);
	else
		return -1;
}

int isFull(struct stack * s)
{
	if(!s)
		return (s->topOfStack >= (s->capacity - 1));
	else
		return -1;
}

void makeEmpty(struct stack * s)
{
	if(!s)
		s->topOfStack = -1;
}

void push(int v, struct stack * s)
{
	if(!s)
		return;
	if(isFull(s))
		printf("the stack is full\n");
	else
		s->array[++s->topOfStack] = v;
}

int top(struct stack * s, int *v)
{
	if(!s)
		return -1;
	if(!isEmpty(s))
	{
		*v = s->array[s->topOfStack];
		return 0;
	}
	else
		return -1;
}

void pop(struct stack * s)
{
	if(!s)
		return ;
	if(!isEmpty(s))
		s->topOfStack--;
}



