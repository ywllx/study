#include <stdlib.h>
#include <string.h>

#include "list.h"

/* Initial a tree */
void list_init(List* list, void (*destroy)(void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}

/* destroy a tree by removing each node of the list */
void list_destroy(List *list)
{
	void *data;

	/* remove each node */
	while (list_size(list) > 0) {
		if (list_rem_next(list, NULL, (void **)&data) == 0 && (list->destroy != NULL))
			list->destroy(data);
	}

	memset(list, 0, sizeof(list));
	return;
}

/* Insert the data behind the node */
int list_ins_next(List *list, ListNode *node, const void *data)
{
	ListNode *new_node;

	if ((new_node = (ListNode *)malloc(sizeof(ListNode))) == NULL)
		return -1;

	new_node->data = (void *)data;
	/* insert the data in the head position of the list */
	if (node == NULL) {
		if (list_size(list) == 0)
			list->tail = new_node;

		new_node->next = list->head;
		list->head = new_node;
	}
	/* insert the data somewhere other than the head position of the list */ 
	else {
		if (node->next == NULL)
			list->tail = new_node;

		new_node->next = node->next;
		node->next = new_node;
	}

	list->size++;

	return 0;
}

/* Remove the node's next node from the list */
int list_rem_next(List *list, ListNode *node, void **data)
{
	ListNode *old_node;

	if (list_size(list) <= 0)
		return -1;

	/* remove the head from the list because there is NULL before head node */
	if (node == NULL) {
		*data = list->head->data;
		old_node = list->head;
		list->head = list->head->next;
		
		if (list_size(list) == 1)
			list->tail = NULL;
	}
	else {
		if (node->next == NULL)
			return -1;

		*data = node->next->data;
		old_node = node->next;
		node->next = node->next->next;

		if (node->next = NULL)
			list->tail = node;
	}

	free(old_node);
	list->size--;

	return 0;
}


