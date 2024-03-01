#include "binary_trees.h"

/**
 * min_value_node - Finds node with the minimum value in a BST.
 * @node: A pointer to the root node of the BST or a subtree.
 * Return: A pointer to the node with the minimum value in the BST.
*/
bst_t *min_value_node(bst_t *node)
{
	bst_t *current = node;

	/* Find the leftmost leaf node */
	while (current && current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: Pointer to the root node of the tree where the node will be removed.
 * @value: The value to remove from the tree.
 * Return: Pointer to the new root node of tree after removing desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (root);

	/* Search for the node with the value to be deleted */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node with the value to be deleted found */

		/* Node with only one child or no child */
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = min_value_node(root->right);

		/* Copy the in-order successor's content to this node */
		root->n = temp->n;

		/* Recursively remove the in-order successor from the right subtree */
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
