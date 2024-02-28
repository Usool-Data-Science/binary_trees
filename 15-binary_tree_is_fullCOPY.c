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
	if (tree == NULL)
		return (0);

	return ((tree->left == NULL && tree->right == NULL) ||
			(binary_tree_is_full(tree->left)
			&& binary_tree_is_full(tree->right)) ? 1 : 0);
}
