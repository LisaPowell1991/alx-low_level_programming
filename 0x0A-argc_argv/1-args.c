#include <stdio.h>

/**
 * main -  function that prints the number of arguments passed into it,
 * followed by a new line.
 * @argc:integer
 * @argv:integer
 * Return: returns 0.
 */

int main(int argc, char __attribute__((__unused__)) *argv[])
{
        printf("%d\n", argc - 1);
        return (0);
}
