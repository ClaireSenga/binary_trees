#include "binary_trees.h"

/**
 * binary_tree_sibling - This function finds the sibling
 * of a node.
 * @node: A pointer to the node to find the sibling.
 *
 * Return: NULL, if the node is NULL. NUll, if the node
 * has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	else if (node == node->parent->right)
		return (node->parent->left);
	return (0);
}
