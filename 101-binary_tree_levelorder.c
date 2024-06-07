#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * struct queue_s - singly linked list for queue.
 * @node: pointer to a binary tree node.
 * @next: pointer to the next node in the queue.
 */
typedef struct queue_s
{
	const binary_tree_t *node;
	struct queue_s *next;
} queue_t;

/**
 * enqueue - adds a node to the end of queue.
 * @head: a double pointer to the head of the queue.
 * @node: a pointer to the binary tree node to add.
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
 * @head: a double pointer to the head of queue.
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
 * binary_tree_levelorder - goes through a bi-tree using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	const binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;

	enqueue(&queue, tree);

	while ((current = dequeue(&queue)) != NULL)
	{
	func(current->n);

	if (current->left != NULL)
		enqueue(&queue, current->left);
	if (current->right != NULL)
		enqueue(&queue, current->right);
	}
}
