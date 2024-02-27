#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_depth - Computes the depth of the tree.
  * @tree: The tree whose depth we want to compute.
  *
  * Return: Depth of the tree.
  */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/*dept of a valid node = depth of the parent + 1*/
	return (
			(tree && tree->parent) ?
			binary_tree_depth(tree->parent) + 1 :
			0);
}
