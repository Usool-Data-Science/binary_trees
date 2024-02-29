#include "binary_trees.h"

/**
 *  binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *  @first: tree node
 *  @second: tree node
 *  Return: LCA; NULL otherwise
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first
, const binary_tree_t *second)
{
	binary_tree_t *parent;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	parent = first->parent;
	if (first == second->parent || !parent || (!parent->parent && second->parent))
		return (binary_trees_ancestor(first, second->parent));
	else if (second == parent || !second->parent
		|| (!second->parent->parent && parent))
		return (binary_trees_ancestor(first->parent, second));
	return (binary_trees_ancestor(first->parent, second->parent));
}
