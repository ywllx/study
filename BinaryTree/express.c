#include <stdlib.h>
#include <stdio.h>

#include "bitree.h"
#include "queue.h"
#include "list.h"

void destroy(void *data){
	free(data);
	data = NULL;
}

int main()
{
	/* construct a binary tree use a queue */
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	if(queue != NULL) {
		queue_init(queue, destroy);
	}
	else {
		return -1;
	}
	

	int c;	
	while((c = getchar()) != '#') {
		int *p;
		p = (int *)malloc(sizeof(int));
		if(p != NULL) {
			*p = c;
			queue_enqueue(queue, p);
			putchar(c);
		}
		else {
			return -1;
		}
		free(p);
	}
	int *data;
	while(queue_size(queue) > 0){
		queue_dequeue(queue, (void **)(&data));
		putchar(*data);
	}
	putchar('\n');
	printf("End test\n");
}
