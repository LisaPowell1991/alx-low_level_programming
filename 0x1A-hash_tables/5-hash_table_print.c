#include "hash_tables.h"

/**
 * hash_table_print - A function that prints a hash table.
 * @ht: The hash table.
 *
 * Return: Void
 */

void hash_table_print(const hash_table_t *ht)
{
	int first = 1;
	hash_node_t *current;
	unsigned long int index;

	if (ht == NULL)
		return;

	printf("{");

	for (index = 0; index < ht->size; index++)
	{
		current = ht->array[index];

		while (current != NULL)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);

			first = 0;
			current = current->next;
		}
	}
	printf("}\n");
}
