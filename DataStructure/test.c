#include <stdio.h>

#include "list.h"

int main( )
{
	List* list;
	if ((list = (List *)malloc(sizeof(List))) == NULL) {
		fprintf(stderr, "malloc function error\n");
		return -1;
	}

	list_init(list);

	int a[] ={1, 4, 5, 21, 34, 12, 5, 4};
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

	fprintf(stdout, "\n");

	return 1;
}
