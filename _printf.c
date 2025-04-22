#include "main.h"
int _putchar(char c);
int print_string(char *str);
int print_num(int n);
/**
 * _printf - prints a format string
 * @format: parameter
 *
 * Return: count of characters
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	if (!format)
	{
		return (-1);
	}

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			switch (format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += print_string(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += print_num(va_arg(args, int));
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i + 1]);
					break;
			}
			i += 2;
		}
		else if (format[i] == '%' && !format[i + 1])
		{
			return (-1);
		}
		else
		{
			count += _putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	_putchar(-1);
	return (count);
}

/**
 * _putchar - prints a character
 * @c: character
 *
 * Return: amount of characters printed
 */

int _putchar(char c)
{
	static char buffer[1024];
	static int index = 0;

	if (c == -1 || index == 1023)
	{
		write(1, buffer, index);
		index = 0;
		return (-1);
	}
	buffer[index] = c;
	index++;
	return (1);
}

/**
 * print_string - prints a string of characters
 * @str: parameter
 *
 * Return: amount of characters printed
 */

int print_string(char *str)
{
	int i = 0;
	int count = 0;

	if (!str)
	{
		str = "(null)";
	}
	while (str[i])
	{
		count += _putchar(str[i]);
		i++;
	}
	return (count);
}
int print_num(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}
	if (num / 10)
	{
		count += print_num(num / 10);
	}
	count += _putchar((num % 10) + '0');
	return (count);
}
