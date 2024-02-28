#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_is_root - Checks if a node is a root.
  *
  * @node: Pointer to a node under inspection.
  *
  * Return: 1 if its a root, 0 otherwise.
  */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (
			(node->left != NULL || node->right != NULL) &&
			node->parent == NULL)
		return (1);
	else
		return (0);
}
