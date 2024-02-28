#include "binary_trees.h"

/**
  * binary_tree_sibling- finds sibling of node
  * @node: pointer to node to check for sibling.
  *
  * Return: pointer to the sibling, NULL otherwise.
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	return ((node && node->parent) ? (node->parent->left == node
	? node->parent->right : node->parent->left) : NULL);
}
