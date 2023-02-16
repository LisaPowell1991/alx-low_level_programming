#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char charType;
	int intType;
	long int longInt;
	long long int longLongInt;
	float floatType;

printf("Size of a char: %c byte\n", sizeof(charType));
printf("Size of a int: %d byte\n", sizeof(intType));
printf("Size of a long int: %ld byte\n", sizeof(longInt));
printf("Size of a long long int: %lld byte\n", sizeof(longLongInt));
printf("Size of a float: %f byte\n", sizeof(floatType));

return (0);
}
