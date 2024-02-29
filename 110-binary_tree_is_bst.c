#include "binary_trees.h"

/**
 * is_bst_util - Checks if a binary tree is a valid BST recursively
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the minimum value the node can take
 * @max: Pointer to the maximum value the node can take
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= min->n) || (max != NULL && tree->n >= max->n))
		return (0);

	return (is_bst_util(tree->left, min, tree)
			&& is_bst_util(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_util(tree, NULL, NULL));
}
