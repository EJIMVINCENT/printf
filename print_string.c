#include "main.h"

/**
 * printString - prints a string
 *
 * @list: list where args are stored
 * @f: flag passed
 *
 * Return: returns the number of char
 * printed
 *
 */

int printString(va_list list, flags *f)
{
	char *string;

	(void)f;

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";
	return (_putString(string));
}

/**
 * printChar - prints a character
 *
 * @list: list where args are stored
 * @f: flag passed
 *
 * Return: returns the number of char
 * printed
 *
 */

int printChar(va_list list, flags *f)
{
	char character;

	(void)f;

	character = va_arg(list, int);
	_putchar(character);
	return (1);
}

