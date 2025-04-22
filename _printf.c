#include "main.h"
int _putchar(char c);
int print_string(char *str);
int print_num(int n);

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
			case 'd':
			case 'i':
				count += print_num(va_arg(args, int));
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

int _putchar(char c)
{
	return(write(1, &c, 1));
}

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
    int num;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else if (n >= 0)
    {
        num = n;
    }
    if (num / 10)
    {
        count += print_num(num / 10);
        count += _putchar((num % 10) + '0');
    }
    else {
        count += _putchar(num + '0');
        return (count);
    }
    return (count);
}
