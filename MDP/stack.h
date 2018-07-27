#pragma once
#ifndef _STACK_H
#define _STACK_H

typedef struct
{
	void *element;
	int element_size;
	int top;
	int length;
}Stack;

int InitialStack(Stack *stack, int element_size, int length);
void DestroyStack(Stack *stack);
int Pop(Stack *stack, void *element);
int Push(Stack *stack, void *element);
bool IsStackEmpty(Stack *stack);

#endif // !_STACK_H

