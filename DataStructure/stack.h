#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "list.h"

/* Implement stack as linked list */
typedef List Stack;

/* Public interface */
#define stack_init list_init

int stack_push(Stack *stack, Datatype data);
int stack_pop(Stack *stack, Datatype* data);

#define stack_top(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#endif

