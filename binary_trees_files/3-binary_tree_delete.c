#include "binary_trees.h"

/**
 * binary_tree_delete - This function deletes an entire binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 *
 * A void function, if tree is NULL do nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *root;

	root = tree;
	if (root == NULL)
		return;
	binary_tree_delete(root->left);
	binary_tree_delete(root->right);
	free(root);
}
