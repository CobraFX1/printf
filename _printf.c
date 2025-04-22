#include "main.h"
int _putchar(char c);
int print_string(char *str);

int _printf(const char *format, ...)
{
        va_list args;
        int i = 0;
        int count = 0;

        if (!format)
        {
        	return(0);
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
		    return (0);
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
