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
	int printed = 0, p = 0, index;
	check print_arg;
	int count[2];

	count[1] = 0;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == '%')
			{
				_putchar('%');
				index++;
				printed++;
			}
			else
			{
				index++;
				print_arg = checkFormat(format[index]);
				switch(print_arg.c)
				{
					case 'i':
						p = print_arg.fc(0, va_arg(arg_list, int));
						break;
					case 'd':
						p = print_arg.fc(0, va_arg(arg_list, int));
						break;
					case 'c':
						p = print_arg.fc(0, va_arg(arg_list, int));
						break;
					case 's':
						p = print_arg.fc(0, va_arg(arg_list, char *));
						break;
				}
				index++;
				if (printed == -1)
		       			return (-1);
				printed += p;
			}
		}
		else
		{
			count[0] = index;
			 _printBuffer(format, count);
			index = count[0];
			printed += count[1];
		}
	}
	va_end(arg_list);
	return (printed);
}

/**
 * _printBuffer - prints the strings passed
 * checks for % and returns at the index
 *
 * @string: string to be printed
 *
 * Return: returns count (num of char printed)
 */

int *_printBuffer(const char *string, int count[2])
{
	char buffer[BUFFER_SIZE];
	int i = 0, index = 0, printed = 0;

	count[0] = index;

	while (string[index] != '\0')
	{
		if (string[index] != '%')
		{
			buffer[i] = string[index];
			i++;
			index++;

			if (i == BUFFER_SIZE)
			{
				printed += i; 
				write(1, buffer, i);
		
				i = 0;
			}
		}
		else if (string[index] == '%')
		{
			if (i > 0)
			{
				printed += i;
				write(1, buffer, i);
			}
			count[0] = index;
			count[1] += printed;
			return (count);
		}
	}
	if (i > 0)
		write(1, buffer, i);
	count[0] = index;
	count[1] += printed;
	return (count);
}







char *string_copy(const char *string)
{
	char *copy;
	int i = 0;

	while (string[i])
		i++;
	i++;
	copy = malloc(sizeof(char) * i);

	if (copy == NULL)
		return (NULL);

	for (i = 0; string[i]; i++)
		copy[i] = string[i];
	copy[i] = '\0';

	return (copy);
}
