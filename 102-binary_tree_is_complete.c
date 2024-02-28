#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count = 0, index = 0;
	const binary_tree_t **queue = NULL;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *));
	if (!queue)
		return (0);

	queue[count++] = tree;

	while (index < count)
	{
		const binary_tree_t *node = queue[index++];

		if (node->left)
		{
			if (index >= count || !queue[index])
			{
				free(queue);
				return (0);
			}
			queue[count++] = node->left;
		}

		if (node->right)
		{
			if (index >= count || !queue[index])
			{
				free(queue);
				return (0);
			}
			queue[count++] = node->right;
		}
	}

	free(queue);
	return (1);
}
