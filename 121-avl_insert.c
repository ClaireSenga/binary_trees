#include "binary_trees.h"
#include <stdlib.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to root node of the tree to measure the height
 *
 * Return: The height of tree. If tree is NULL, return 0
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * update_height - Updates the height of a node
 * @node: Pointer to node
 */
void update_height(binary_tree_t *node)
{
	if (node)
		node->n = 1 + (height(node->left)
		> height(node->right) ? height(node->left)
		: height(node->right));
}

/**
 * balance_avl_tree - Balances an AVL tree node
 * @node: Pointer to the node to balance
 *
 * Return: Pointer to new root node after balancing
 */
binary_tree_t *balance_avl_tree(binary_tree_t *node)
{
	update_height(node);
	int balance = binary_tree_balance(node);

	if (balance > 1)
	{
	if (binary_tree_balance(node->left) < 0)
		node->left = binary_tree_rotate_left(node->left);
	return (binary_tree_rotate_right(node));
	}
	else if (balance < -1)
	{
	if (binary_tree_balance(node->right) > 0)
		node->right = binary_tree_rotate_right(node->right);
	return (binary_tree_rotate_left(node));
	}

	return (node);
}

/**
 * bst_insert_rec - Helper function to insert a value in a BST
 * @tree: Double pointer to the root node of BST
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
binary_tree_t *bst_insert_rec(binary_tree_t **tree, int value)
{
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		(*tree)->left = bst_insert_rec(&(*tree)->left, value);
	if ((*tree)->left)
		(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = bst_insert_rec(&(*tree)->right, value);
	if ((*tree)->right)
		(*tree)->right->parent = *tree;
	}
	else
	{
	return (NULL);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: Double pointer to the root node of AVL tree
 * @value: Value to insert
 *
 * Return: Pointer to created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
	*tree = binary_tree_node(NULL, value);
	return (*tree);
	}

	bst_t *new_node = bst_insert_rec((binary_tree_t **)tree, value);

	if (new_node == NULL)
		return (NULL);

	binary_tree_t *balanced_tree = balance_avl_tree(*tree);

	if (balanced_tree->parent == NULL)
		*tree = (avl_t *)balanced_tree;

	return (new_node);
}
