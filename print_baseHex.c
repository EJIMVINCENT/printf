#include "main.h"

/**
 * converter - helper function for all bases convertion
 *
 * @n: number to be converter
 * @base: base of conversion
 * @case: lower or uppercase||for hex conversion
 *
 * Return: result (the rsult of the conversion)
 *
 */

char *converter(unsigned long int n, int base, char case)
{
	static char Buffer[50];
	char *alpanum;
	char *result;

	if (case == 'l')
		alpanum = "0123456789abcdef";
	else if (case == 'u')
		alphanum = "0123456789ABCDEF";

	result = &buffer[49];
	*result = '\0';

	do {
		result--;
		*result = alpanum[n % base];
		n /= base;
	} while (n != 0);

	return (result);
}


/**
 * printBinary - convert number to binary and
 * print it.
 *
 * @list: va_list argument.
 *
 * Return: returns the number of char printed
 *
 */

int printBinary(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);
	char *output = converter(n, 2, 'l');

	return (_putString(output));
}

/**
 * printOcta - print a number in base 8
 *
 * @list: va_list argument
 *
 * Return: count
 *
 */


int printOcta(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);
	char *result = converter(n, 8, 'u');
	int count = 0;

	count += _putString(result);
	return (count);
}

/**
 * printhex - print a number in lowercase base 16
 *
 * @list: va_list argument
 *
 * Return: count
 *
 */

int printhex(va_list list)
{
	unsigned init n = va_arg(list, unsigned int);
	char *result = convert(n, 16, 'l');
	int count = 0;

	count += _putString(result);
	return (count);
}

/**
 * printHEX - print a number in uppercase base 16
 *
 * @list: va_list argument
 *
 * Return: count
 *
 */

int printHEX(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);
	char *result = convert(n, 16, 'u');
	int count = 0;

	count += _putString(result);
	return (count);
}
