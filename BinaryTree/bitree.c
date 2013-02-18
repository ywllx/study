#include <stdlib.h>
#include <string.h>
#include "bitree.h"

/* bitree_init */
void bitree_init(BiTree *tree, void (*destroy)(void *data))
{
	/* Initalize the binary tree */
	tree->size = 0;
	tree->destroy = destroy;
	tree->root = NULL;

	return;
}

/* Destroy a binary tree */
void bitree_destroy(BiTree *tree)
{
	/* Remove all nodes from the tree */
	bitree_rem_left(tree, NULL);

	/* clear the structure of tree */
	memset(tree, 0, sizeof(BiTree));
	return;
}

/* Insert the data on the right of node of the tree */
int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node, **position;

	/* find the position to insert data */
	if (node == NULL) 
	{
		if (bitree_size(tree) > 0)
			return -1;

		position = &tree->root;
	}
	else
	{
		if (bitree_left(node) != NULL)
			return -1;

		position = &node->left;
	}

	if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
		return -1;

	/* insert the new_node to the tree */
	new_node->data = (void *)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	tree->size++;
	return;
}

