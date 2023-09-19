#include "main.h"


/**
 * checkFormat - checks the format specifier and
 * returns a the approperate function
 *
 * @c: to be checked
 *
 * Return: returns a function
 *
 */

int (*checkFormat(char c))(va_list)
{
	int i = 0;
	check formatCheck[] = {
		{'c', printChar},
		{'s', printString},
		{'i', printInt},
		{'d', printInt},
		{'\0', NULL}
	};

	for (i = 0; formatCheck[i].c != '\0'; i++)
	{
		if (formatCheck[i].c == c)
		{
			return (formatCheck[i].fc);
		}
	}
	return (NULL);
}
