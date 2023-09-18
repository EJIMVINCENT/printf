#include "main.h"

/**
 * _printf - the simple printf function
 *
 * @format: the string passed to _printf to be printed
 *
 * Return: returns the number of char printed
 *
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	int printed = 0, p = 0, index = 0, i = 0;
	char buffer[BUFFER_SIZE] = {0};

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == '%')
			{
				_putchar('%'), printed++;
			}
			else
			{
				p = checkFormat(arg_list, format[++index]);
				if (p == -1)
					return (-1);
				printed += p;
			}
		}
		else
		{
			buffer[i++] = format[index];
			if (i >= BUFFER_SIZE)
			{
				write(1, buffer, i);
				printed += i, i = 0;
			}
		}
	}
	if (i > 0)
	{
		write(1, buffer, i);
		printed += i;
	}
	va_end(arg_list);
	return (printed);
}


