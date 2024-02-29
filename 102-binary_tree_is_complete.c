#include "binary_trees.h"
#include <stdbool.h>

/**
  * binary_tree_is_complete - checks if a binary tree is complete
  * @tree: The tree to print.
  * Return: 1 if complete, 0 if not
  *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	int front, rear;
	bool flag;

	if (tree == NULL)
		return (0);

	queue = (binary_tree_t **)malloc(sizeof(binary_tree_t *) * 1000);
	front = -1, rear = -1;
	flag = false;

	queue[++rear] = (binary_tree_t *)tree;
	while (front != rear)
	{
		binary_tree_t *temp = queue[++front];

		if (temp->left == NULL && temp->right != NULL)
		{
			free(queue);
			return (0);
		}

		if (flag && (temp->left != NULL || temp->right != NULL))
		{
			free(queue);
			return (0);
		}
		/* Enqueue left child*/
		if (temp->left != NULL)
			queue[++rear] = temp->left;
		else
			flag = true;
		/* Enqueue right child*/
		if (temp->right != NULL)
			queue[++rear] = temp->right;
		else
			flag = true;
	}
	free(queue);
	return (1);
}

