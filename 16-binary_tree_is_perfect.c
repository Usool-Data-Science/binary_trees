#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
  * binary_tree_is_perfect - Checks if the tree is perfect.
  * @tree: The tree under investigation.
  * Return: 1 if perfect, 0 otherwise.
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*
	 * Condition 1: Left_height must eq Right_height
	 * Condition 2: Left must be full and right must be full.
	 * Condition 3: Both sides must be balance (For recurssion sake)
	 */
	return (
		((binary_tree_height(tree->left) == binary_tree_height(tree->right))
		&& (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
		&& (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right))) ? 1 : 0
		);
}

/**
  * binary_tree_height - Compute the height of the tree.
  * @tree: The tree under investigation.
  * Return: The height of the tree.
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return ((left_height > right_height ? left_height : right_height));
}

/**
  * binary_tree_is_full - Checks if the tree is full.
  * @tree: The tree under investigation.
  *
  * Return: 1 if full, 0 otherwise.
  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left && tree->right)
		return ((binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right)));
	return (0);
}
