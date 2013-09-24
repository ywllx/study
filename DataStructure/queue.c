/* queue.c */
#include <stdlib.h>

#include "queue.h"
#include "list.h"

/* enqueue like insert the data to the list of tail */
int queue_enqueue(Queue *queue, Datatype data)
{
	list_ins(queue, (queue->size)+1, data);
}

/* dequeue like remove the data of the head */
int queue_dequeue(Queue *queue, Datatype* data)
{
	list_rem(queue, 1, data);
}

