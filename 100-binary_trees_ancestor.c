#include "binary_trees.h"

/**
 * create_list1 - This function creates a list using
 * singly linked list structure.
 * @first: A pointer to the first treee.
 *
 * Return: A pointer to the head of the list.
 */
list_t *create_list1(const binary_tree_t *first)
{
	list_t *new_node1, *list1;

	if (first == NULL)
		return (NULL);
	list1 = NULL;
	while (first != NULL)
	{
		new_node1 = malloc(sizeof(list_t));
		if (new_node1 == NULL)
		{
			perror("Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		new_node1->n = first;
		new_node1->next = list1;
		list1 = new_node1;
		first = first->parent;
	}
	return (list1);
}

/**
 * create_list2 - Creates the second list using
 * singly linked list structure.
 * @second: A pointer to the second tree.
 *
 * Return: A pointer to the head of the list.
 */
list_t *create_list2(const binary_tree_t *second)
{
	list_t *new_node2, *list2;

	list2 = NULL;
	if (second == NULL)
		return (NULL);
	while (second != NULL)
	{
		new_node2 = malloc(sizeof(list_t));
		if (new_node2 == NULL)
		{
			perror("Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		new_node2->n = second;
		new_node2->next = list2;
		list2 = new_node2;
		second = second->parent;
	}
	return (list2);
}

/**
 * free_list - This function frees the list of a binary tree node.
 * @list: The first list to free.
 */
void free_list(list_t *list)
{
	list_t *temp, *current;

	current = list;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

/**
 * binary_trees_ancestor - This function finds the lowest common
 * ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor of the two given
 * nodes, otherwise, NULL if no lowest common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	list_t *ancestor_first, *ancestor_second;
	const binary_tree_t *last_common_ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	ancestor_first = create_list1(first);
	ancestor_second = create_list2(second);
	last_common_ancestor = NULL;
	while (ancestor_first != NULL && ancestor_second != NULL)
	{
		if (ancestor_first->n == ancestor_second->n)
		{
			last_common_ancestor = ancestor_second->n;
			ancestor_first = ancestor_first->next;
			ancestor_second = ancestor_second->next;
		}
		else
		{
			free_list(ancestor_first);
			free_list(ancestor_second);
			return ((binary_tree_t *)last_common_ancestor);
		}
	}
	if (ancestor_first == NULL || ancestor_second == NULL)
	{
		free_list(ancestor_first);
		free_list(ancestor_second);
		return ((binary_tree_t *)last_common_ancestor);
	}

	free_list(ancestor_first);
	free_list(ancestor_second);
	return ((binary_tree_t *)last_common_ancestor);
}
