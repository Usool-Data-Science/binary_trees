#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_nodes - Counts the number of fertile nodes in a tree.
  * @tree: The three whose node we want to count.
  *
  * Return: The number of fertile nodes in a tree or 0 if none.
  */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t fertile = 0;

	if (tree == NULL)
		return (0);
	else
	{
		fertile += (tree->left || tree->right) ? 1 : 0;
		fertile += binary_tree_nodes(tree->left);
		fertile += binary_tree_nodes(tree->right);
	}

	return (fertile);
}
