#include "hash_tables.h"

/**
 * hash_table_create -  a function that creates a hash table.
 * @size: The size of the array.
 *
 * Return: a pointer to the newly created hash table
 * or NULL if something went wrong
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = NULL;
	unsigned long int index;

	if (size < 1 || table == NULL)
		return (NULL);

	table = malloc(sizeof(hash_table_t));

	table->array = malloc(sizeof(hash_node_t *) * size);

	if (table->array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		table->array[index] = NULL;
	}
	table->size = size;
	return (table);
}
