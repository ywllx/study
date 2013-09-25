/* bitree.h */
#ifndef BITREE_H
#define BITREE_H

#include <stdlib.h>

typedef int Datatype

/* Define a structure for binarytree node */
typedef struct BiTreeNode_
{
	Datatype data;
	struct BiTreeNode_ *left;
	struct BiTreeNode_ *right;
}BiTreeNode;

/* Define a structure for binary trees */
typedef struct BiTree_
{
	int size;
	BiTreeNode *root;
}BiTree;


/* Public interface */
void bitree_init(BiTree *tree);
BiTreeNode* bitree_ins_left(BiTree *tree, BiTreeNode *node, Datatype *data);
BiTreeNode* bitree_ins_right(BiTree *tree, BiTreeNode *node, Datatype *data);
void bitree_rem_left(BiTree *tree, BiTreeNode *node);
void bitree_rem_right(BiTree *tree, BiTreeNode *node);

#define bitree_size(tree) ((tree)->size)
#define bitree_root(tree) ((tree)->root)
#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)
#define bitree_data(node) ((node)->data)
#define bitree_left(node) ((node)->left)
#define bitree_right(node) ((node)->right)

#endif

