#include <stdio.h>

#include "list.h"
#include "stack.h"
#include "queue.h"

int main( )
{
	int a[] ={1, 4, 5, 21, 34, 12, 5, 4};

	List* list;
	if ((list = (List *)malloc(sizeof(List))) == NULL) {
		fprintf(stderr, "list malloc function error\n");
		return -1;
	}

	list_init(list);

	int i = 0;
	for (i = 0; i < 8; i++) {
		list_ins(list, i+1, a[i]);
	}

	fprintf(stdout, "print each element of the list\n");
	ListNode *node = list->head;
	while(node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	fprintf(stdout, "\n");

	int pos = 3;
	int ins = 134;
	list_ins(list, pos, ins);
	fprintf(stdout, "after insert the %dth element: %d\n", pos, ins);
	fprintf(stdout, "print each element of the list\n");
	node = list->head;
	while(node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	fprintf(stdout, "\n");

	int *p;
	if ((p = (int *)malloc(sizeof(int))) == NULL) {
		fprintf(stderr, "malloc function error\n");
		return -1;
	}

	pos = 5;
	list_rem(list, pos, p);
	fprintf(stdout, "after remove the %dth element: %d\n", pos, *p);
	fprintf(stdout, "print each element of the list\n");
	node = list->head;
	while(node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}

	fprintf(stdout, "\n\n");

	Stack* stack;
	if ((stack = (Stack *)malloc(sizeof(Stack))) == NULL) {
		fprintf(stderr, "stack malloc function error\n");
		return -1;
	}

	stack_init(stack);

	for (i = 0; i < 8; i++) {
		fprintf(stdout, "Push the element: %d\n", a[i]);
		stack_push(stack, a[i]);
	}
	fprintf(stdout, "\n");

	for (i = 0; i < 4; i++) {
		stack_pop(stack, p);
		fprintf(stdout, "Pop the element: %d\n", *p);
	}
	fprintf(stdout, "\n");


	Queue* queue;
	if ((queue = (Queue *)malloc(sizeof(Queue))) == NULL) {
		fprintf(stderr, "Queue malloc function error\n");
		return -1;
	}

	queue_init(queue);

	for (i = 0; i < 8; i++) {
		fprintf(stdout, "enqueue the element: %d\n", a[i]);
		queue_enqueue(queue, a[i]);
	}
	fprintf(stdout, "\n");

	for (i = 0; i < 8; i++) {
		queue_dequeue(queue, p);
		fprintf(stdout, "dequeue the element: %d\n", *p);
	}
	fprintf(stdout, "\n");

	return 1;
}
