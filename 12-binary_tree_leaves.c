#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
  * binary_tree_leaves - Counts the number of leaves in a tree.
  * @tree: The tree whose leave we want to count.
  *
  * Return: Total leaf counts if any, else Zero.
  */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_size = 0;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		leaf_size += 1;
	else
	{
		leaf_size += tree->left ? binary_tree_leaves(tree->left) : 0;
		leaf_size += tree->right ? binary_tree_leaves(tree->right) : 0;
	}

	return (leaf_size);
}
