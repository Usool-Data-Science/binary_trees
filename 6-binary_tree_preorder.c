#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_preorder - Prints values of tree in preorder manner.
  * @tree: The tree to print.
  * @func: Function for printing the values of the tree.
  *
  */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		printf("%d\n", tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
