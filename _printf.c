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
	char *format_copy;
	va_list arg_list;
	int printed = 0, printedChar = 0;
	check print_arg;
	char i = 0;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	format_copy = string_copy(format);
	if (format_copy == NULL)
	       return (-1);

	while (*format_copy != '\0')
	{
		if (*format_copy != '%')
		{
			printedChar += _printBuffer(format_copy);
			format_copy++;
		}

		else 
		{
			print_arg = checkFormat(*format_copy);
			switch(print_arg.c)
			{
				case 'i':
					printed = print_arg.fc(0, va_arg(arg_list, int));
					break;
				case 'd':
					printed = print_arg.fc(0, va_arg(arg_list, int));
					break;
				case 'c':
					printed = print_arg.fc(0, va_arg(arg_list, int));
					break;
				case 's':
					printed = print_arg.fc(0, va_arg(arg_list, char *));
					break;
			}
			if (printed == -1)
		       		return (-1);
			printedChar += printed;
			format_copy++;
		}	
	}
	free(format_copy);
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
	int i = 0;
	int count = 0;

	while (*string != '\0')
	{
		if (*string != '%')
		{
			buffer[i] = *string;
			i++;

			if (i == BUFFER_SIZE)
			{
				count += i; 
				write(1, buffer, i);
		
				i = 0;
			}
			string++;
		}
		else if (*string == '%')
		{
			string++;
			if (*string == '%')
			{
				buffer[i++] = '%';
				count++;
			}
			else
			{
				string--;
				if (i > 0)
				{
					write(1, buffer, i);
					count += i;
				}
				return(count);
			}
			string++;
		}
	}
	if (i > 0)
		write(1, buffer, i);

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
