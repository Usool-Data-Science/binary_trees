#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_insert_left - A function that creates a new left child node.
  * @parent: The parent of the new child node.
  * @value: The value to assign to the new child node.
  *
  * Return: A pointer to the new child node.
  */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);

	/*Create and verify a new node for our value*/
	newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
		return (NULL);

	/*Populate the newNode with values*/
	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	/*
	 * Assign new node to the left of the parent if it is null
	 * otherwise replace the old left with the new node and
	 * assign the old left the left child of our new node then
	 * make the new node a parent to the old left node.
	 */
	if (parent->left != NULL)
	{
		newNode->left = parent->left;
		parent->left->parent = newNode;
	}
	parent->left = newNode;

	return (newNode);
}
