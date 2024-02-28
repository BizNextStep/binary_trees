#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL
			|| node->parent->parent == NULL)
		return (NULL);

	/* If node's parent is the left child of its grandparent */
	if (node->parent == node->parent->parent->left)
	{
		/* Return the right child of the grandparent (if not NULL) */
		if (node->parent->parent->right != NULL)
			return (node->parent->parent->right);
	}
	else /* If node's parent is the right child of its grandparent */
	{
		/* Return the left child of the grandparent (if not NULL) */
		if (node->parent->parent->left != NULL)
			return (node->parent->parent->left);
	}

	/* If no uncle is found */
	return (NULL);
}
