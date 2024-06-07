#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *parent = NULL, *new_node;

	if (tree == NULL)
		return (NULL);

	/* If the tree is empty, create the root node */
	if (*tree == NULL)
	{
	*tree = binary_tree_node(NULL, value);
	return (*tree);
	}

	/* Find the correct position to insert the new node */
	current = *tree;
	while (current != NULL)
	{
	parent = current;
	if (value < current->n)
		current = current->left;
	else if (value > current->n)
		current = current->right;
	else
		return (NULL); /* Value already exists in the tree */
	}

	/* Create the new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* Insert the new node as the left or right child */
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
