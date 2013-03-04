/* traverse.c */
#include <stdlib.h>

#include "traverse.h"

/* preorder */
int preorder(const BiTreeNode *node, List *list)
{
	/* Load the list with a preorder listing of the tree */
	if (node != NULL) {
		if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
			return -1;

		if (bitree_left(node) != NULL) {
			if (preorder(bitree_left(node), list) != 0)
				return -1;
		}

		if (bitree_right(node) != NULL) {
			if (preorder(bitree_right(node), list) != 0)
				return -1;
		}
	}

	return 0;
}

int inorder(const BiTreeNode *node, List *list)
{
	if (node != NULL) {
		if (bitree_left(node) != NULL) {
			if (inorder(bitree_left(node), list) != 0)
				return -1;
		}

		/* Load the list with a inorder listing of the tree */
		if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
			return -1;

		if (bitree_right(node) != NULL) {
			if (inorder(bitree_right(node), list) != 0)
				return -1;
		}
	}

	return 0;
}

int postorder(const BiTreeNode *node, List *list)
{
	if (node != NULL) {
		if (bitree_left(node) != NULL) {
			if (postorder(bitree_left(node), list) != 0)
				return -1;
		}

		if (bitree_right(node) != NULL) {
			if (postorder(bitree_right(node), list) != 0)
				return -1;
		}

		/* Load the list with a postorder listing of the tree */
		if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
			return -1;
	}

	return 0;
}


	


