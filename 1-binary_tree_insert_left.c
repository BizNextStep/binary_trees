#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL
 * If parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);
	
	if (!new_node || !parent)
		return (NULL);

	/* Check if parent already has a left child */
	if (parent->left != NULL) {
		binary_tree_t *old_left = parent->left;
		parent->left = new_node;
		new_node->left = old_left;
		old_left->parent = new_node;
	} else {
		parent->left = new_node;
	}

	return (new_node);
}
