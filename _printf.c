#include "main.h"
int _putchar(char c);
int print_string(char *str);

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
	return (write(1, &c, 1));
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
