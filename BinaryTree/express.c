#include <stdlib.h>
#include <stdio.h>

#include "bitree.h"
#include "queue.h"
#include "list.h"

void destroy(char *data)
{
	free(data);
	data = NULL;
}


int main()
{
	/* construct a binary tree use a queue */
	Queue *queue;
	queue_init(queue, (void (*)(void *))destroy);
	

	int c;	
	int count = 0;
	while((c = getchar()) != '#') {
		queue_enqueue(queue, (void *)(&c));
		count++;
	}

	int *data;
	while(queue_size(queue) > 0){
		queue_dequeue(queue, (void **)(&data));
		putchar(*data);
	}
	putchar('\n');
	printf("count = %d\n", count);
		
}
