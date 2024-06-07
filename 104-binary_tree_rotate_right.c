#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL || tree->left == NULL)
	{
	return (tree);
	}

	binary_tree_t *new_root = tree->left;

	tree->left = new_root->right;
	if (new_root->right != NULL)
	{
		new_root->right->parent = tree;
	}
	new_root->parent = tree->parent;
	if (tree->parent != NULL)
	{
	if (tree == tree->parent->left)
	{
		tree->parent->left = new_root;
	} else
	{
		tree->parent->right = new_root;
	}
	}
	new_root->right = tree;
	tree->parent = new_root;

	return (new_root);
}
