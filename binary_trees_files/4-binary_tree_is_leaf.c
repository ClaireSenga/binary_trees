#include "binary_trees.h"

/**
 * binary_tree_is_leaf - This function checks if a node is leaf.
 * @node: A pointer to the node to check.
 * In binary trees, a node that doesn't have children is considered a leaf.
 *
 * Return: 1 if node is a leaf, otherwise 0.
 * if node is NULL return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
