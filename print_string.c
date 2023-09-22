#include "main.h"

/**
 * printString - prints a string
 *
 * @list: list where args are stored
 * @f: flag passed
 * @c: pointer to struct convs
 *
 * Return: returns the number of char
 * printed
 *
 */

int printString(va_list list, flags *f, convs *c)
{
	char *string;
	int i = 0;
	(void)f;

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";
	while (string[i])
		i++;
	i += printConvSpec(c->w - i);
	_putString(string);
	return (i);
}

/**
 * printChar - prints a character
 *
 * @list: list where args are stored
 * @f: flag passed
 * @c: pointer to struct convs
 *
 * Return: returns the number of char
 * printed
 *
 */

int printChar(va_list list, flags *f, convs *c)
{
	char character;
	int i = 0;

	(void)f;

	character = va_arg(list, int);
	i += printConvSpec(c->w - 1);
	i += _putchar(character);
	return (i);
}

