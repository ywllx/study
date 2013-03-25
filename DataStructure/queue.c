/* queue.c */
#include <stdlib.h>

#include "queue.h"
#include "list.h"

/* enqueue like insert the data to the list of tail */
int queue_enqueue(Queue *queue, const void *data)
{
	list_ins_next(queue, list_tail(queue), data);
}

/* dequeue like remove the data of the head */
int queue_dequeue(Queue *queue, void **data)
{
	list_rem_next(queue, NULL, data);
}

