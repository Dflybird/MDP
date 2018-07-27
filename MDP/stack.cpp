#include <stdlib.h>
#include <string.h>
#include "stack.h"


int InitialStack(Stack *stack, int element_size, int length) {
	int status = 1;
	stack->element_size = element_size;
	stack->length = length;
	stack->top = 0;
	stack->element = malloc(element_size * length);
	if (stack->element == NULL)
		status = -1;
	return status;
}

void DestroyStack(Stack *stack) {
	free(stack->element);
}

int Pop(Stack *stack, void *element) {
	int status = 1;
	if (stack->top == 0)	//stack is empty
		status = -1;
	else
	{
		void* source = (char *)(stack->element) + (stack->top - 1) * stack->element_size;
		memcpy(element, source, stack->element_size);
		stack->top--;
	}
	return status;
}

int Push(Stack *stack, void *element) {
	int status = 1;
	if (stack->top == stack->length) {	//stack is full
		stack->length += 8;
		stack->element = realloc(stack->element, stack->length * stack->element_size);
	}
	if (stack->element == NULL)
		status = -1;
	else
	{
		void* source = (char *)(stack->element) + stack->top * stack->element_size;
		memcpy(source, element, stack->element_size);
		stack->top++;
	}
	return status;
}

bool IsStackEmpty(Stack *stack) {
	if (stack->top == 0)		return true;
	else
		return false;
}