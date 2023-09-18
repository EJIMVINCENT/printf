#include "main.h"

/**
 * printString - prints a string
 *
 * @list: list where args are stored
 *
 * Return: returns the number of char
 * printed
 *
 */

int printString(va_list list)
{
	int i = 0;
	char *string;

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";
	i = 0;
	while (string[i] != '\0')
		i++;

	write(1, string, i);
	return (i);
}

/**
 * printChar - prints a character
 *
 * @list: list where args are stored
 *
 * Return: returns the number of char
 * printed
 *
 */

int printChar(va_list list)
{
	char character;

	 character = va_arg(list, int);
	_putchar(character);
	return (1);

}

