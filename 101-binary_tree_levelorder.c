#include "binary_trees.h"


void binary_tree_levelorder(const binary_tree_t* tree, void (*func)(int)) {
	// Check if tree or func is NULL
	if (tree == NULL || func == NULL)
		return;

	// Queue to perform level-order traversal
	binary_tree_t** queue = (binary_tree_t**)malloc(sizeof(binary_tree_t*) * 1000);
	int front = -1, rear = -1;

	// Enqueue root and perform level order traversal
	queue[++rear] = (binary_tree_t*)tree;
	while (front != rear) {
		binary_tree_t* temp = queue[++front];

		// Call the provided function for the current node
		(*func)(temp->n);

		// Enqueue left child
		if (temp->left != NULL)
			queue[++rear] = temp->left;

		// Enqueue right child
		if (temp->right != NULL)
			queue[++rear] = temp->right;
	}

	// Free allocated memory
	free(queue);
}
