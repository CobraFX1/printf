#include "main.h"

/**
 * print_bin - prints a number in binary form
 * @n: parameter
 *
 * Return: number of characters printed
 */
int print_bin(int n)
{
	int num = 1;
	int count;

	if (!n)
		return (0);
	while (num > 0)
	{
		num = n;
		count += _putchar((num % 2) + '0');
		n = (num / 2);
	}
	return (count);
}
