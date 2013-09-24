/* queue.h */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "list.h"

/* Implement the queue an linked list */
typedef List Queue;

/* Public interface */
#define queue_init list_init

int queue_enqueue(Queue *queue, Datatype data);
int queue_dequeue(Queue *queue, Datatype* data);

#define queue_top(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)

#endif

