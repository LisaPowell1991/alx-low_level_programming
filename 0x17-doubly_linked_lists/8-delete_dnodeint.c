#include "lists.h"

/**
 * delete_dnodeint_at_index - function that
 * deletes the node at index
 * @head: Pointer to the pointer of the head node
 * @index: Index of the node to be deleted. starts at 0
 *
 * Return: 1 if it succeeded,
 * -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node = *head;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current_node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current_node);
		return (1);
	}
	while (current_node != NULL && count < index)
	{
		current_node = current_node->next;
		count++;
	}
	if (current_node == NULL)
		return (-1);
	if (current_node->prev != NULL)
		current_node->prev->next = current_node->next;
	if (current_node->next != NULL)
		current_node->next->prev = current_node->prev;

	free(current_node);
	return (1);
}
