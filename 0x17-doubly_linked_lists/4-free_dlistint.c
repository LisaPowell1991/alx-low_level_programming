#include "lists.h"

/**
 * free_dlistint - function that frees a list
 * @head: Pointer that points to the head node
 *
 * Return: void
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next;

		free(current_node);
	}
}
