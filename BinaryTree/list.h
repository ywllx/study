#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/* define a structrue for linked list element */
typedef struct ListNode_
{
	void *data;
	struct ListNode_ *next;
}ListNode;

typedef struct List_
{
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	ListNode *head;
	ListNode *tail;
}List;

/* Public interface */
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListNode *node, const void *data);
int list_rem_next(List *list, ListNode *node, void *data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define node_is_head(list, node) ((node) == (list)->head ? 1:0)
#define node_is_tail(node) ((node)->next == NULL ? 1:0)
#define node_data(node) ((node)->data)
#define node_next(node) ((node)->next)

#endif

