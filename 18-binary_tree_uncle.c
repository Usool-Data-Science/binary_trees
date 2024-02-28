#include "binary_trees.h"

/**
 * binary_tree_uncle - finds uncle of a node in a binary tree.
 * @node: pointer to node to check for uncle.
 * Return: pointer to the uncle node, or NULL otherwise.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	return ((node && node->parent && node->parent->parent)
	? (node->parent->parent->left == node->parent
	? node->parent->parent->right : node->parent->parent->left) : NULL);
}

