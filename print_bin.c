#include "main.h"

/**
 * print_bin - prints a number in binary form
 * @n: parameter
 *
 * Return: number of characters printed
 */
int print_bin(unsigned int n)
{
	int i = 0;
	int count = 0;
	int binary[32];

	if (n == 0)
	{
		return (_putchar(0));
	}
	while (n > 0)
	{
		binary[i++] = n % 2;
		n /= 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		count += _putchar(binary[i] + '0');
	}
	return (count);
}
