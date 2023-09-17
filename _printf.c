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
	int i = 0, count = 0, printed = 0, printedChar = 0;
	int (*print_arg)(int, ...)

	if (format == NULL)
		return (-1);

       va_start(arg_list, format);
      
	while (*format)
	{
		if (*format != '%')
		{
			printedChar += _printBuffer(format);
		}

		else if (*format == '%')
		{
			format++;
			print_arg = checkFormat(*format);
			if (print_arg == NULL)
				return (-1);
			switch(print_arg)
			{
				case printInt:
					printed = print_arg(0, va_arg(arg_list, int));
				case printChar:
					printed = print_arg(0, va_arg(arg_list, char));
				case printString:
					printed = print_arg(0, va_arg(arg_list, char));
			}
			if (printed == -1)
				return (-1);
			printedChar += printed;
		}
		format++;	
	}
	va_end(arg_list);
	return (printedChar);
}

/**
 * _printBuffer - prints the strings passed
 * checks for % and returns at the index
 *
 * @string: string to be printed
 *
 * Return: returns count (num of char printed)
 */

int _printBuffer(char *string)
{
	char buffer[BUFFER_SIZE];
	int i = 0, count = 0;

	while (*string)
	{
		if (*string != '%')
		{
			buffer[i++] = *string;
			string++;

			if (i == BUFFER_SIZE)
                        {
				count += i + 1;
				write(1, buffer, i + 1);
				i = 0;
			}
		}

		else if (*format == '%')
		{
			if (buffer > 0)
				write(1, buffer, i + 1);
			return (count);
		
		}
}

