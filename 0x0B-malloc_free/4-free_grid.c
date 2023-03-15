#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - function that frees a 2 dimensional grid.
 * @grid: integer
 * @height: integer
 * Return:returns 0;
 */

void free_grid(int **grid, int height)
{
	int i;

	if (grid == 0 || height == 0)
	{
		return;
	}
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
