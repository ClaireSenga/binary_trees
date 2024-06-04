#include "binary_trees.h"

/**
 * binary_tree_depth - This function measures the depth of a node
 * in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *node;
	size_t i;

	if (tree == NULL)
		return (0);

	node = tree;
	i = -1;
	while (node != NULL)
	{
		i++;
		node = node->parent;
	}
	return (i);
}
