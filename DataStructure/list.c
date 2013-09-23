#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"

/* Initial a list */
void list_init(List *list)
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}

/* get the ListNode of the location i in the list */
ListNode* get_node(List* list, int pos)
{
	if (pos <=0 || pos > (list->size)) {
		fprintf(stderr, "i is outof range of list size)\n");
		return;
	}
	
	int i = 0;
	ListNode* head = list->head;
	ListNode* node = head;
	while (i < (pos-1)) {
		node = node->next;
		i++;
	}

	return node;
}

/* Insert the data in the position i of the list */
int list_ins(List *list, int pos, Datatype data)
{
	if (pos <=0 || pos > (list->size) + 1) {
		fprintf(stderr, "i is outof range of list size)\n");
		return;
	}
	
	ListNode *new_node;
	if ((new_node = (ListNode *)malloc(sizeof(ListNode))) == NULL) {
		fprintf(stderr, "malloc function error\n");
		return -1;
	}
	new_node->data = data;

	if (pos <= (list->size)) {
		ListNode *node = get_node(list, pos);
		/* insert the data in the head position of the list */
		if (pos == 1) {
			new_node->next = list->head;
			list->head = new_node;
		}
		/* insert the data somewhere other than the head and tail position of the list */ 
		else {
			new_node->next = node->next;
			node->next = new_node;
		}
	}
	/* insert the data in the tail position of the list */ 
	else {
		/* first if list is NULL */ 
		if (list->size == 0) {
			list->head = new_node;
			list->tail = new_node;
			new_node->next = NULL;
		}
		list->tail->next = new_node;
		new_node->next = NULL;
		list->tail = new_node;
	}

	list->size++;

	return 0;
}

/* Remove the node's next node from the list */
int list_rem(List *list, int pos, Datatype *data)
{
	if (pos <=0 || pos > (list->size)) {
		fprintf(stderr, "i is outof range of list size)\n");
		return;
	}

	if (list->size <= 0) {
		fprintf(stderr, "list size is less than 1)\n");
		return -1;
	}

	ListNode *node = get_node(list, pos);
	*data = node->data;

	/* remove the head from the list because there is NULL before head node */
	if (node == list->head) {
		list->head = list->head->next;
		
		if (list->size == 1)
			list->tail = NULL;
	}
	else {
		ListNode *prenode = get_node(list, pos-1);
		prenode->next = node->next;

		if (node->next = NULL)
			list->tail = prenode;
	}

	free(node);
	list->size--;

	return 0;
}

