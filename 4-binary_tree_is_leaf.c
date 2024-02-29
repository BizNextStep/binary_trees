#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_leaf - Checks if a given node is a leaf
 * @node: A pointer to the node to check
 *
 * Returns: 1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
 */
int _binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0); /* If the node is NULL */

	if (node->left == NULL && node->right == NULL)
		return (1); /* If the node has no left or right child */

	return (0); /* If the node has at least one child */
}
