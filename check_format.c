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

int (*checkFormat(char c))(va_list, flags *, convs *)
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

		case 'l':
			f->l = 1;
			i = 1;
			break;

		case 'h':
			f->s = 1;
			i = 1;
			break;
	}
	return (i);
}

/**
 * checkConvSpec - handles the field width
 * for non-custom conversion specifiers
 *
 * @s: charcter to be checked
 * @c: pinter to struct convs
 * @list: poniter to list
 *
 * Return: 1 if specifer is found,
 * 0 otherwise.
 *
 */

int checkConvSpec(char s, convs *c, va_list list)
{
	int i = 0;
	static char dot;

	if (s == '*')
	{
		i = va_arg(list, int);
		c->w += i;
		return (1);
	}
	if (s == '.')
		dot = '.';

	if (dot != '.' && (s > '0' && s < '9'))
	{
		c->w *= 10;
		i = s - '0';
		c->w += i;
		return (1);
	}

	else if (dot == '.' && (s > '0' && s < '9'))
	{
		c->p *= 10;
		i = s - '0';
		c->p += i;
		return (1);
	}
	return (0);

}

/**
 * printConvSpec - print space
 * @n: number of space
 *
 * Return: return i or 0
 */

int printConvSpec(int n)
{
	int i = 0;

	if (n < 0)
		return (0);

	while (n > 0)
	{
		i += _putchar(' ');
		n--;
	}
	return (i);
}
