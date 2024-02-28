#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_inorder - Prints values of tree in inorder manner.
  * @tree: The tree to print.
  * @func: Function for printing the values of the tree.
  *
  */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
