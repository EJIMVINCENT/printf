#include "main.h"


/**
 * checkFormat - checks the format specifier and
 * returns a the approperate function
 *
 * @character - the character to be checked
 * @arg_list: list of arguments
 *
 * Return: returns a function
 *
 */

int checkFormat(va_list list, char character)
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
		if (formatCheck[i].c == character)
		{
			
			return (formatCheck[i].fc(list));
		}
	}
	return (-1);
}
