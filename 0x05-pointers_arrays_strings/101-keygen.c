#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generate random valid passwords
 * @a: int to check
 * @b:int to check
 **2772 is the total sum of the ASCII values of all the characters in the password, including the missing character.
 * Return: 0 is success
 */

int main(void)
{
int a = 0, b = 0;
time_t t;

srand((unsigned int) time(&t));
while (b < 2772)
{
a = rand() % 128;
if ((b + a) > 2772)
break;
b = b + a;
printf("%c\n", a);

}
printf("%c\n", (2772 - b));
return (0);
}
