#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_size - Computes the size of a tree.
  * @tree: The tree whose size we want to compute.
  *
  * Return: Size of the tree if it exists, otherwise 0
  */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_left = 0, size_right = 0;

	if (tree == NULL)
		return (0);

	size_left = tree->left ? binary_tree_size(tree->left) : 0;
	size_right = tree->right ? binary_tree_size(tree->right) : 0;

	return (size_left + size_right + 1);
}
