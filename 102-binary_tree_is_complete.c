#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * struct queue_s - singly linked list for queue
 * @node: a pointer to a bi-tree node
 * @next: a pointer to the next node in the queue
 */

typedef struct queue_s
{
	const binary_tree_t *node;
	struct queue_s *next;
} queue_t;

/**
 * enqueue - adds a node to the end of the queue
 * @head: a double pointer to the head of the queue
 * @node: a pointer to the binary tree node to add
 */

void enqueue(queue_t **head, const binary_tree_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));
	queue_t *temp;

	if (new_node == NULL)
	return;

	new_node->node = node;
	new_node->next = NULL;

	if (*head == NULL)
	{
	*head = new_node;
	}
	else
	{
	temp = *head;
		while (temp->next != NULL)
		temp = temp->next;
		temp->next = new_node;
	}
}

/**
 * dequeue - removes a node from the front of queue
 * @head: a double pointer to the head of the queue
 *
 * Return: the node at the front of the queue
 */

const binary_tree_t *dequeue(queue_t **head)
{
	queue_t *temp;
	const binary_tree_t *node;

	if (*head == NULL)
	return (NULL);

	temp = *head;
	node = temp->node;
	*head = (*head)->next;
	free(temp);

	return (node);
}

/**
 * binary_tree_is_complete - checks if a bi tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue = NULL;
	const binary_tree_t *current;
	int flag = 0; /* Flag to indicate the first encountered NULL node */

	if (tree == NULL)
	return (0);

	enqueue(&queue, tree);

	while ((current = dequeue(&queue)) != NULL)
	{
	if (current == NULL)
	{
		flag = 1;
	}
	else
	{
	if (flag)
		return (0);

	enqueue(&queue, current->left);
	enqueue(&queue, current->right);
	}
	}

	return (1);
}
