#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_is_full - Check if the tree is full.
  * @tree: The tree under investigation.
  *
  * Return: 1 if its full, 0 otherwise.
  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/*If the parent tree is null*/
	if (tree == NULL)
		return (0);

	/* if both are NULL */
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/*If both are not NULL*/
	if (tree->left && tree->right)
	{
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));
	}

	/*If one of the subtree is NULL*/
	return (0);
}
