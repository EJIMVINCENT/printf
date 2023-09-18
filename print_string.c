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
	char *string;

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";

	return (_putString(string));
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

