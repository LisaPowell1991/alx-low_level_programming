#include "lists.h"

/**
 * sum_dlistint - function that returns
 * the sum of all the data of a linked list
 * @head: Pointer to the head of the doubly linked list
 *
 * Return: The sum of all the data
 * or 0 if list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	int sum_total = 0;

	while (head != NULL)
	{
		sum_total += head->n;
		head = head->next;
	}
	return (sum_total);
}
