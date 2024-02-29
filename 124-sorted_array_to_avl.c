#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (array_to_avl(array, 0, size - 1, NULL));
}

/**
 * array_to_avl - Recursive function to build an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Index of the start of the subarray
 * @end: Index of the end of the subarray
 * @parent: Pointer to the parent node
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, int start, int end, avl_t *parent)
{
	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;

	avl_t *node = binary_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);

	node->left = array_to_avl(array, start, mid - 1, node);
	node->right = array_to_avl(array, mid + 1, end, node);

	return (node);
}
