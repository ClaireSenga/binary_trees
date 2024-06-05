#include "binary_trees.h"

/**
 * binary_tree_nodes - This function counts the nodes with at least
 * 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number
 * of nodes.
 *
 * Return: 0 if tree is NULL, otherwise the number of nodes with
 * at least 1 child.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_nodes_left, count_nodes_right;
	size_t total_count = 0;
	const binary_tree_t *curr_node;

	if (tree == NULL)
		return (0);

	curr_node = tree;
	count_nodes_left = binary_tree_nodes(curr_node->left);
	count_nodes_right = binary_tree_nodes(curr_node->right);
	if (curr_node->left != NULL || curr_node->right != NULL)
	{
		total_count = 1 + (count_nodes_left + count_nodes_right);
	}
	return (total_count);
}
