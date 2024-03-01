#include "binary_trees.h"

/**
* binary_tree_is_bst - Function to check if a binary tree is a valid BST
* @tree: binary tree
* Return: 1 if BST, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN; /* Previous value initialized to minimum integer value */

	if (tree == NULL)
		return (0);

	return (inorder_traversal(tree, &prev));
}

/**
* inorder_traversal - Helper function for inorder traversal
* @node: tree node
* @prev: previous val
* Return: true for valid BST, false otherwise
*/
bool inorder_traversal(const binary_tree_t *node, int *prev)
{
	if (node == NULL)
		return (true);

	/* Check left subtree*/
	if (!inorder_traversal(node->left, prev))
		return (false);

	/* Check current node value*/
	if (node->n <= *prev)
		return (false);
	*prev = node->n;

	/* Check right subtree*/
	return (inorder_traversal(node->right, prev));
}
