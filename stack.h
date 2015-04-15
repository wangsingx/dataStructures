#ifndef _STACK_H
#define _STACK_H

struct stack{
	int capacity;
	int topOfStack;
	int *array;
};

int isEmpty(struct stack *s);
int isFull(struct stack *s);
struct stack *createStack(int max);
void disposeStack(struct stack *s);
void makeEmpty(struct stack *s);
void push(int v, struct stack *s);
int top(struct stack *s, int *v);
void pop(struct stack *s);



#endif // _STACK_H
