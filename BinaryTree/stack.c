/* stack.c */
#include <stdio.h>

#include "list.h"
#include "stack.h"

/* stack push */
int stack_push(Stack *stack, const void *data)
{
	/* push the data onto the stack like insert the data to the head of the list */
	return list_int_next(stack, NULL, data);
}

/* stack pop */
int stack_pop(Stack *stack, void **data)
{
	/* pop the data of the stack like remove the data of the head of the list */
	return list_rem_next(stack, NULL, data);
}
