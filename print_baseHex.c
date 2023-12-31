#include "main.h"

/**
 * converter - helper function for all bases convertion
 *
 * @n: number to be converter
 * @base: base of conversion
 * @c: lower or uppercase||for hex conversion
 *
 * Return: result (the rsult of the conversion)
 *
 */

char *converter(unsigned long n, int base, char c)
{
	static char Buffer[50];
	char *alphanum;
	char *result;


	if (c == 'l')
		alphanum = "0123456789abcdef";
	else if (c == 'u')
		alphanum = "0123456789ABCDEF";

	result = &Buffer[49];
	*result = '\0';

	do {
		*(--result) = alphanum[n % base];
		n /= base;
	} while (n != 0);

	return (result);
}


/**
 * printBinary - convert number to binary and
 * print it.
 *
 * @list: va_list argument.
 * @f: flag passed
 * @c: pointer to convs struct
 *
 * Return: returns the number of char printed
 *
 */

int printBinary(va_list list, flags *f, convs *c)
{
	int i = 0, count = 0;
	unsigned int n = va_arg(list, unsigned int);
	char *output = converter(n, 2, 'l');

	(void)f;
	while (output[i])
		i++;
	count += printConvSpec(c->w - i);

	count += _putString(output);
	return (count);
}

/**
 * printOcta - print a number in base 8
 *
 * @list: va_list argument
 * @f: flag passed
 * @c: pointer to struct convs
 *
 * Return: count
 *
 */

int printOcta(va_list list, flags *f, convs *c)
{
	char *result;
	int count = 0, i = 0;
	unsigned long n;

	if (f->s == 1)
		n = (unsigned short)va_arg(list, int);
	else if (f->l == 1)
		n = (unsigned long)va_arg(list, unsigned long);
	else
		n = (unsigned int)va_arg(list, unsigned int);

	result = converter(n, 8, 'l');

	if (f->hash == 1 && result[0] != '0')
		count++;
	while (result[i])
		i++;
	count += printConvSpec(c->w - (count + i));
	if (f->hash == 1 && result[0] != '0')
		_putchar('0');
	count += _putString(result);
	return (count);
}

/**
 * printhex - print a number in lowercase base 16
 *
 * @list: va_list argument
 * @f: flag passed
 * @c: pointer to struct convs
 *
 * Return: count
 *
 */

int printhex(va_list list, flags *f, convs *c)
{
	char *result;
	int i = 0, count = 0;
	unsigned long n;

	if (f->s == 1)
		n = (unsigned short)va_arg(list, int);
	else if (f->l == 1)
		n = (unsigned long)va_arg(list, unsigned long);
	else
		n = (unsigned int)va_arg(list, unsigned int);

	result = converter(n, 16, 'l');

	if (f->hash == 1 && result[0] != '0')
		count += 2;
	while (result[i])
		i++;
	i += count;
	count += printConvSpec(c->w - i);
	if (f->hash == 1 && result[0] != '0')
		_putString("0x");
	count += _putString(result);
	return (count);
}

/**
 * printHEX - print a number in uppercase base 16
 *
 * @list: va_list argument
 * @f: flag passed
 * @c: pointer to struct convs
 *
 * Return: count
 *
 */

int printHEX(va_list list, flags *f, convs *c)
{
	char *result;
	int i = 0, count = 0;
	unsigned long n;

	if (f->s == 1)
		n = (unsigned short)va_arg(list, int);
	else if (f->l == 1)
		n = (unsigned long)va_arg(list, unsigned long);
	else
		n = (unsigned int)va_arg(list, unsigned int);

	result = converter(n, 16, 'u');

	if (f->hash == 1 && result[0] != '0')
		count += 2;
	while (result[i])
	i++;
	i += count;
	count += printConvSpec(c->w - i);
	if (f->hash == 1 && result[0] != '0')
		_putString("0X");
	count += _putString(result);
	return (count);
}
