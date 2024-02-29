#include "binary_trees.h"
#include <stdbool.h>

/**
  * binary_tree_rotate_left - checks if a binary tree is complete
  * @tree: binary tree to rotate.
  * Return: rotated tree
  *
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	temp = new_root->left;
	new_root->left = tree;
	tree->right = temp;
	/*+---------------*/
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = new_root;
	new_root->parent = temp;

	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = new_root;
		else
			temp->right = new_root;
	}
	return (new_root);
}
