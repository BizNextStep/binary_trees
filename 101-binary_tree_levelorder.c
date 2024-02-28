#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;

	if (tree == NULL || func == NULL)
		return;

	queue = queue_push(queue, (void *)tree);

	while (queue)
	{
		const binary_tree_t *node = (binary_tree_t *)queue->ptr;
		func(node->n);

		if (node->left)
			queue = queue_push(queue, (void *)node->left);
		if (node->right)
			queue = queue_push(queue, (void *)node->right);

		queue = queue_pop(queue);
	}

	queue_free(queue);
}
