#include <stdlib.h>
#include <stdio.h>

#include "bitree.h"
#include "queue.h"
#include "list.h"
#include "traverse.h"

void destroy(void *data){
	free(data);
	data = NULL;
}

int main()
{
	/* Initialize a queue  */
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	if (queue != NULL) {
		queue_init(queue, destroy);
	}
	else {
		return -1;
	}
	
	/* Initialize a bitree */
	BiTree *tree = (BiTree *)malloc(sizeof(BiTree));
	if (tree != NULL) {
		bitree_init(tree, destroy);
	}
	else {
		return -1;
	}

	/* Initialize a list */
	List *list = (List *)malloc(sizeof(List));
	if (list != NULL) {
		list_init(list, destroy);
	}
	else {
		return -1;
	}

	BiTreeNode *root, *node;
	root = NULL;
	node = NULL;

	int c;	
	while ((c = getchar()) != '#') {
		int *p;
		p = (int *)malloc(sizeof(int));
		if (p == NULL) {
			return -1;
		}
		else
		{
			*p = c;
			
			/* first insert the root node of the tree */
			if (bitree_size(tree) == 0) {
				root = bitree_ins_left(tree, NULL, p);
				if (root == NULL) {
					return -1;
				}
				node = root;
				/* enqueue the node pointer to the queue */
				queue_enqueue(queue, node);
			}

			/* Insert the other node other than root node */
			if (bitree_size(tree) > 0) {
				/* get the insert position pointer of the tree */
				BiTreeNode **q;
				queue_dequeue(queue, (void **)(&q));

				/* Insert the left node */
				if (*p != '$') {
					node = bitree_ins_left(tree, *q, p);
					if (root == NULL) {
						return -1;
					}
					queue_enqueue(queue, node);
				}
				/* Insert the right node */
				if (*p != '$') {
					node = bitree_ins_right(tree, *q, p);
					if (root == NULL) {
						return -1;
					}
					queue_enqueue(queue, node);
				}
			}
		}
	}
	

	if (preorder(root, list) != 0)
		return -1;

	while(list_size(list) > 0) {
		int *q;
		q = (int *)malloc(sizeof(int));
		if(q != NULL) {
			list_rem_next(list, NULL, (void **)(&q));
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
