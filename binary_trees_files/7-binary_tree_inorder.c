#include "binary_trees.h"

/**
 * binary_tree_inorder - This function goes through a binary tree
 * using in-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: Is a pointer to a function to call for each node.
 * The value in the node must be
 * passed as a parameter to this function.
 *
 * Return: If a tree or func is NULL, do nothing (i.e return).
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
