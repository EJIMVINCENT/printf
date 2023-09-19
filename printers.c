#include "main.h"

/**
 * _putchar - stores the character c in a buffer
 * if c = -1 or the buffer is full, we fullsh the buffer.
 *
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 *
 */

int _putchar(char c)
{
	static char buffer[1024];
	static int index;

	if (c == -1 || index >= 1024)
		write(1, buffer, index), index = 0;

	if (c != -1)
		buffer[index] = c, index++;
	return (1);
}

/**
 * _putString - Used to print a string
 * the function will loop over the characters
 * in string and call putchar each time.
 *
 * @string: the string to be printed.
 *
 * Return: returns the number of characters printed
 *
 */

int _putString(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
		_putchar(string[i]);

	return (i);
}
