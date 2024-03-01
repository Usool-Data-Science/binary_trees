#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: A pointer to the node containing the value, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	/* Traverse the tree until the value is found */
	while (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree); /* Found the value, return the node */

		if (value < tree->n)
			tree = tree->left; /* Search in the left subtree */
		else
			tree = tree->right; /* Search in the right subtree */
	}

	return (NULL);
}
