#include "binary_trees.h"
#define max(a, b) (a > b ? a : b)

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree. If tree is NULL, return 0
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst_helper - Helper function to check if a tree is a BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the min node
 * @max: Pointer to the max node
 *
 * Return: 1 if tree is a valid BST, & 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree,
const binary_tree_t *min, const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);
	if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
		return (0);
	return (is_bst_helper(tree->left, min, tree) &&
	is_bst_helper(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, & 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_helper(tree, NULL, NULL));
}

/**
 * is_balanced - Checks if a tree is balanced & a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a balanced AVL tree, & 0 otherwise
 */
int is_balanced(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (1);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is valid AVL tree
 * @tree: Pointer to root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, & 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	return (is_balanced(tree));
}
