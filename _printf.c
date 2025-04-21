#include "main.h"
#include <stdarg.h>
#include <unistd.h> // Needed for write()

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_string(char *str)
{
	int i = 0,
	    int count = 0;

	if (str != NULL)
	{
		while (str[i])
		{
			count += _putchar(str[i]);
			i++;
		}
	}
	return (count);
}

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0,
	    int count = 0;

	va_start(args, format);
	while (format && format[i])
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
		else
		{
			count += _putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return count;
}

