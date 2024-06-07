#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>

/**
 * Helper function to check if a bi-tree is a valid BST within a given range.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Min allowed value for nodes (exclusive).
 * @max: Max allowed value for nodes (exclusive).
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
	is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a bi-tree is valid Binary Search Tree (BST).
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
