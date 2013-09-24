/* stack.c */
#include <stdio.h>

#include "list.h"
#include "stack.h"

/* stack push */
int stack_push(Stack *stack, Datatype data)
{
	/* push the data onto the stack like insert the data to the head of the list */
	return list_ins(stack, 1, data);
}

/* stack pop */
int stack_pop(Stack *stack, Datatype* data)
{
	/* pop the data of the stack like remove the data of the head of the list */
	return list_rem(stack, 1, data);
}
