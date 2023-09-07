#include "hash_tables.h"

/**
 * hash_table_delete - A function that deletes a hash table.
 * @ht: Is the hash table
 *
 * Return: Void
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *current, *next;

	if (ht == NULL)
		return;

	for (index = 0; index < ht->size; index++)
	{
		current = ht->array[index];

		while (current != NULL)
		{
			next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = next;
		}
	}
	free(ht->array);
	free(ht);
}
