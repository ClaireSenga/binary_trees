#include "binary_trees.h"
#define max(a, b) ((a) > (b) ? (a) : (b))

/**
 * measure_tree_depth - This function measures the depth of a
 * binary tree.
 * @tree: A pointer to the tree to measure its depth.
 *
 * Return: 0 if tree is NULL, otherwise the depth of the tree.
 */
size_t measure_tree_depth(binary_tree_t *tree)
{
	size_t depth_left_subtree, depth_right_subtree;

	if (tree == NULL)
		return (0);

	depth_left_subtree = measure_tree_depth(tree->left);
	depth_right_subtree = measure_tree_depth(tree->right);
	return (max(depth_left_subtree, depth_right_subtree) + 1);
}

/**
 * binary_tree_is_perfect - This function checks if a binary tree
 * is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL, 1 if tree is perfect, 0 if tree
 * is not perfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth_left_subtree, depth_right_subtree;
	int perfect_left_subtree, perfect_right_subtree;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	depth_left_subtree = measure_tree_depth(tree->left);
	depth_right_subtree = measure_tree_depth(tree->right);
	if (depth_left_subtree != depth_right_subtree)
		return (0);

	perfect_left_subtree = binary_tree_is_perfect(tree->left);
	perfect_right_subtree = binary_tree_is_perfect(tree->right);
	if (perfect_left_subtree == 1 && perfect_right_subtree == 1)
		return (1);
	return (0);
}
