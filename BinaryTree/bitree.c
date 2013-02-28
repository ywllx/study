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

/* Insert the data on the left of node of the tree */
BiTreeNode* bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node, **position;

	/* find the position to insert data */
	if (node == NULL) 
	{
		if (bitree_size(tree) > 0)
			return NULL;

		position = &tree->root;
	}
	else
	{
		if (bitree_left(node) != NULL)
			return NULL;

		position = &node->left;
	}

	if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
		return NULL;

	/* insert the new_node to the tree */
	new_node->data = (void *)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	tree->size++;
	return *position;
}


/* Insert the data on the right of the node of the tree */
BiTreeNode* bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node, **position;

	/* find the position to insert data */
	if (node == NULL)
	{
		if (bitree_size(tree) > 0)
			return NULL;

		position = &tree->root;
	}
	else
	{
		if (bitree_right(node) != NULL )
			return NULL;

		position = &node->right;
	}

	if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == -1)
		return NULL;

	/* insert the new_node to the tree */
	new_node->data = (void *)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	tree->size++;
	return *position;
}

/* Remove the left sub-tree of the node */
void bitree_rem_left(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position;

	/* Could not remove sub-tree from an empty tree */
	if (bitree_size(tree) == 0)
		return;

	if (node == NULL)
		position = &tree->root;
	else
		position = &node->left;

	if (*position != NULL) 
	{
		bitree_rem_left(tree, *position);
		bitree_rem_right(tree, *position);

		if (tree->destroy != NULL)
		{
			tree->destroy((*position)->data);
		}

		free(*position);
		*position = NULL;
		tree->size--;
	}

	return;
}

/* Remove the right sub-tree of the node */
void bitree_rem_right(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position;

	/* Could not remove sub-tree from an empty tree */
	if (bitree_size(tree) == 0)
		return;

	if (node == NULL)
		position = &tree->root;
	else
		position = &node->right;

	if (*position != NULL) 
	{
		bitree_rem_left(tree, *position);
		bitree_rem_right(tree, *position);

		if (tree->destroy != NULL)
		{
			tree->destroy((*position)->data);
		}

		free(*position);
		*position = NULL;
		tree->size--;
	}

	return;
}

