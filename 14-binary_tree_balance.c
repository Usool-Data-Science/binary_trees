#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_balance - Computes the balance factor of a tree.
  * @tree: The tree whose balance factor we want to compute.
  *
  * Return: Balance factor or 0 if the tree is empty.
  */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return (left_height - right_height);
}


