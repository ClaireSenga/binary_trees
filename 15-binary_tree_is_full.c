#include "binary_trees.h"

/**
 * binary_tree_is_full - This function checks if a binary tree
 * is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	const binary_tree_t *curr_node;
	int left_subtree, right_subtree;

	if (tree == NULL)
		return (0);

	curr_node = tree;
	if (curr_node->left == NULL && curr_node->right == NULL)
		return (1);

	left_subtree = binary_tree_is_full(curr_node->left);
	right_subtree = binary_tree_is_full(curr_node->right);
	if (left_subtree == 1 && right_subtree == 1)
		return (1);

	if (left_subtree == 0 || right_subtree == 0)
		return (0);
	return (0);
}
