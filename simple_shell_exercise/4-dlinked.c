#include "ss_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * add_dnodeint_end - adds a new node at the end of a dlistin_t list
 *
 * @head: a pointer to a pointer to the start of dlistint_t
 * @n: an int value to be store in the new node
 *
 *
 * Return: the address of the new element or NULL if failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, char *n)
{
	dlistint_t *new_node;
	dlistint_t *current = *head;

	new_node = malloc(sizeof(new_node));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL; /* Sets new node as last node */

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		while (current != NULL && current->next != NULL)
			current = current->next;

		current->next = new_node;
		new_node->prev = current;
	}
	return (new_node);
}

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 *
 * @h: a pointer to the start of dlistint_t
 *
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%s\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}
/**
 * free_list - check the code
 * @head: head of the list
 *
 * Return: nothing.
 */
void free_list(dlistint_t *head)
{
	dlistint_t *node;

	if (head != NULL)
	{
		node = head;
		if (node != NULL && node->next != NULL)
		{
			free_node(node->next);
		}
		free(head);
	}
}

/**
 * free_node - frees mem usage by the node
 * @node: node to free up
 *
 * Return: nothing.
 */
void free_node(dlistint_t *node)
{
	if (node->next != NULL)
	{
		free_node(node->next);
	}
	free(node);
}
