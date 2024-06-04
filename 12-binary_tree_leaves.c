#include "binary_trees.h"

/**
 * binary_tree_leaves - This function counts the leaves in a
 * binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 * 
 * Return: 0 if tree is NULL, otherwise the counted number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	const binary_tree_t *curr_node;
	size_t num_leaves_left, num_leaves_right;

	if (tree == NULL)
		return (0);

	curr_node = tree;
	if (curr_node->left == NULL && curr_node->right == NULL)
		return (1);
	num_leaves_left = binary_tree_leaves(curr_node->left);
	num_leaves_right = binary_tree_leaves(curr_node->right);
	return (num_leaves_left + num_leaves_right);
}
