#include "binary_trees.h"
#define max(a, b) ((a) > (b) ? (a) : (b))

/**
 * binary_tree_height - This function measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, return 0, else return the size of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;
	
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (max(left_height, right_height) + 1);
}

/**
 * binary_tree_balance - This function measures the balance factor of
 * a binary tree.
 * @tree: A pointer to the root node of the tree.
 * This function calls the binary_tree_height function to calculate
 * the height of the left and right subtrees.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_subtree, right_subtree;
	int tree_balance;
	
	if (tree == NULL)
		return (0);

	left_subtree = binary_tree_height(tree->left);
	right_subtree = binary_tree_height(tree->right);
	tree_balance = left_subtree - right_subtree;
	return (tree_balance);
}
