#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef int Datatype;

/* define a structrue for linked list element */
typedef struct ListNode_
{
	Datatype data;
	struct ListNode_ *next;
}ListNode;

typedef struct List_
{
	int size;
	ListNode *head;
	ListNode *tail;
}List;

/* Public interface */
void list_init(List *list);
ListNode* get_node(List *list, int pos);
int list_ins(List *list, int pos, Datatype data);
int list_rem(List *list, int pos, Datatype* data);

#endif

