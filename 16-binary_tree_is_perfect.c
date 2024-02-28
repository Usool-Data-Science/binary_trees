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
	 *		-all leaf nodes are at same level
	 * Condition 2: Left must be full and right must be full.
	 *		- all internodes have two children
	 * Condition 3: Both sides must be balance (For recurssion sake)
	 */
	/**
	*return (
	*	((binary_tree_height(tree->left)
		== binary_tree_height(tree->right)) << 2) |
	*	((binary_tree_is_full(tree->left)
		&& binary_tree_is_full(tree->right)) << 1) |
	*	((binary_tree_is_perfect(tree->left)
		&& binary_tree_is_perfect(tree->right)))
	*);
	*/

	if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
	{
		/*printf("failed 1st condition\n");*/
		return (0);
	}
	if (!binary_tree_is_full(tree->left) || !binary_tree_is_full(tree->right))
	{
		/*printf("failed 2nd condition\n");*/
		return (0);
	}
	/**
	*if (!binary_tree_is_perfect(tree->left)
		|| !binary_tree_is_perfect(tree->right))
	*{printf("failed 3rd condition\n");
	*	return (0);}
	*/
	/*printf("passed\n");*/
	return (1);
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

