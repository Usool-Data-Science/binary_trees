#include "binary_trees.h"

/**
  * binary_tree_levelorder - Prints values of tree in levelorder manner.
  * @tree: The tree to print.
  * @func: Function for printing the values of the tree.
  *
  */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front, rear;

	if (tree == NULL || func == NULL)
		return;

	queue = (binary_tree_t **)malloc(sizeof(binary_tree_t *)
	* 1000);
	front = -1, rear = -1;

	queue[++rear] = (binary_tree_t *)tree;
	while (front != rear)
	{
		binary_tree_t *temp = queue[++front];

		(*func)(temp->n);

		/* Enqueue left child*/
		if (temp->left != NULL)
			queue[++rear] = temp->left;

		/* Enqueue right child*/
		if (temp->right != NULL)
			queue[++rear] = temp->right;
	}

	free(queue);
}
