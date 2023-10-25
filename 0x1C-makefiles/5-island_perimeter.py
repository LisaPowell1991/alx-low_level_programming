#!/usr/bin/python3

""" A module that contains an island_perimeter definition. """

def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid:
    grid is a list of list of integers:
        - 0 represents a water zone
        - 1 represents a land zone
        - One cell is a square with side length 1
        - Grid cells are connected horizontally/vertically (not diagonally).
        -Grid is rectangular, width and height don’t exceed 100
    Grid is completely surrounded by water, and there is one island (or nothing).
    The island doesn’t have “lakes”
    (water inside that isn’t connected to the water around the island).
    """
    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # check left neighbour
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                # check right neighbour
                if j == cols - 1 or grid[i][j + 1] == 0:
                    perimeter += 1
                # Check upper neighbour
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                # check lower neighbour
                if i == rows - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
    return perimeter
