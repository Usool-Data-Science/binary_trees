#include "binary_trees.h"

/**
 * bst_remove - Removes a node with a specific value from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;
	bst_t *successor;

	if (root == NULL)
	{
		return (NULL);
	}

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
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

		successor = root->right;
		while (successor->left != NULL)
			successor = successor->left;

		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}
