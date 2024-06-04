#include "binary_trees.h"

/**
 * binary_tree_node - This function creates a binary tree node.
 * @parent: Pointer tothe parent node to be created.
 * @value: The value to put in the new node.
 *
 * Return: A pointer to the new node or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *temp = malloc(sizeof(binary_tree_t));

	if (temp == NULL)
		return (NULL);
	temp->n = value;
	temp->parent = parent;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}
