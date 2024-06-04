#include "binary_trees.h"

/**
 * binary_tree_size - This function measures the size of a binary tree.
 * @tree: A pointer to the root node to measure the size.
 * 
 * Return: 0 if tree is NULL, otherwise the size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	const binary_tree_t *curr_node;
	size_t curr_node_left, curr_node_right;

	if (tree == NULL)
		return (0);

	curr_node = tree;
	curr_node_left = binary_tree_size(curr_node->left);
	curr_node_right = binary_tree_size(curr_node->right);
	return ((curr_node_left + curr_node_right) + 1);
}
