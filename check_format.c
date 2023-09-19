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

int (*checkFormat(char c))(va_list, flags *)
{
	register int i = 0;
	check formatCheck[] = {
		{'c', printChar},
		{'s', printString},
		{'i', printInt},
		{'d', printInt},
		{'%', printPercentSign},
		{'b', printBinary},
		{'u', printUnsigned},
		{'o', printOcta},
		{'x', printhex},
		{'X', printHEX},
		{'R', printRot13},
		{'r', printRev},
		{'S', printNonPrint},
		{'p', printAddress},
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

/**
 * checkFlag - used to check if a flag was passed
 *
 * @s: character that holds the flag
 * @f: pointer to the struct flags
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 *
 */

int checkFlag(char s, flags *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;

		case ' ':
			f->space = 1;
			i = 1;
			break;

		case '#':
			f->hash = 1;
			i = 1;
			break;

	}

	return (i);
}
