#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_node - A function that creates a new child node.
  * @parent: The parent of the new child node.
  * @value: The value to assign to the new child node.
  *
  * Return: A pointer to the new child node.
  */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/*Create and verify a new node for our value*/
	binary_tree_t *newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
