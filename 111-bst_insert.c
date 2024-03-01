#include "binary_trees.h"

/**
  * bst_insert - Inserts a value in a Binary Search Tree (BST).
  * @tree: A double pointer to the root node of the BST to insert the value.
  * @value: The value to store in the node to be inserted.
  * Return: A pointer to the created node, or NULL on failure.
  */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		/* If the tree is empty, create a new node and make it the root */
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* If the value is already present, ignore it */
	if ((*tree)->n == value)
		return (NULL);

	/* If value is less than current node's value, insert into left subtree */
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			/* If the left child is NULL, create a new node and insert */
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		/* Recursively insert into the left subtree */
		return (bst_insert(&((*tree)->left), value));
	}

	/* If value is greater than current node's value, insert into right subtree */
	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			/* If the right child is NULL, create a new node and insert */
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		/* Recursively insert into the right subtree */
		return (bst_insert(&((*tree)->right), value));
	}

	return (NULL);
}
