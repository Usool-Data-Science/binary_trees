#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_postorder - Prints values of tree in inorder manner.
  * @tree: The tree to print.
  * @func: Function for printing the values of the tree.
  *
  */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	printf("%d\n", tree->n);

	return;
}
