#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
  * binary_tree_insert_right - A function that creates right child node.
  * @parent: The parent of the new child node.
  * @value: The value to assign to the new child node.
  *
  * Return: A pointer to the new child node.
  */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	/*Create and verify a new node for our value*/
	binary_tree_t *newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
		return (NULL);

	/*Populate the newNode with values*/
	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	/*
	 * Assign new node to the right of the parent if it is null
	 * otherwise replace the old right with the new node and
	 * assign the old right the right child of our new node then
	 * make the new node a parent to the old left node.
	 */
	if (parent->right != NULL)
	{
		newNode->right = parent->right;
		parent->right->parent = newNode;
	}
	parent->right = newNode;

	return (newNode);
}
