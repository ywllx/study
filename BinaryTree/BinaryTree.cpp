#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

/*
 * Allocates a new node with the given data and set the left and right points to
 * NULL
 */
struct node* new_node(int data) {
	struct node* node = new(struct node);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/*
 * Given a binary search tree and a number, insert the number to the binary tree
 */
struct node* insert(struct node* root, int data) {
	if (root == NULL) {
		return new_node(data);
	}
	else {
		if (data <= root->data) root->left = insert(root->left, data);
		else root->right = insert(root->right, data);
		return root;
	}
}

/*
 * Given a binary tree, return ture if a node with the target data is found in 
 * the tree. Recurs down the tree, choose the left or right branch by comparing
 * the target data to each data.
 */
static int lookup(struct node* root, int target) {
	if (root == NULL) {
		return -1;
	}
	else {
		if (target == root->data) return target;
		else {
			if (target <= root->data) return lookup(root->left, target);
			else return lookup(root->right, target);
		}
	}
}

/*
 * print the data of each node recursly
 */
void print_binary_tree(struct node* root) {
	if (root == NULL) {
		return;
	}
	else {
		cout << root->data << ' ';
	}
	print_binary_tree(root->left);
	print_binary_tree(root->right);
}

int main() {
	struct node* root;
	root = NULL;
	int data;
	while(cin >> data, !cin.eof()) {
		cout << "Now insert data: " << data << endl;
		root = insert(root, data);
	}
	print_binary_tree(root);
}
