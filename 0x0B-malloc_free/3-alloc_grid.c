#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - function that returns a
 * pointer to a 2 dimensional array of integers.
 * @width: integer
 * @height: integer
 * Return:returns a 2 dimensional array of integers
 * or returns NULL on failure
 * or if height or width is 0 or negative
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, n;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	grid = malloc(height * sizeof(int *));

	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
	grid[i] = malloc(width * sizeof(int));

	if (grid[i] == NULL)
	{
		for (i--; i >= 0; i--)
		free(grid[i]);
			free(grid);
			return (NULL);
	}
	}
	for (i = 0; i < height; i++)
	for (n = 0; n < width; n++)
		grid[i][n] = 0;

	return (grid);
}
