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
	/* Initialize a queue  */
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	if(queue != NULL) {
		queue_init(queue, destroy);
	}
	else {
		return -1;
	}
	
	/* Initialize a bitree */
	BiTree *tree = (BiTree *)malloc(sizeof(BiTree));
	if(tree != NULL) {
		bitree_init(tree, destroy);
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
/*			
			BiTreeNode *node;
			node = NULL;
			
			if(bitree->size == 0) {
				if (bitree_ins_left(bitree, node, p) == -1)
					return -1;
			}
*/				
			queue_enqueue(queue, p);
		}
		else {
			return -1;
		}
		p = NULL;
//		free(p);
	}
	
	while(queue_size(queue) > 0) {
		int *q;
		q = (int *)malloc(sizeof(int));
		if(q != NULL) {
			queue_dequeue(queue, (void **)(&q));
			putchar(*q);
		}
		else {
			return -1;
		}
		free(q);
		q = NULL;
	}
	putchar('\n');
	printf("End test\n");
	return 0;
}
