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
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	return (0);
}
