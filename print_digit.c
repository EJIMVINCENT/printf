#include "main.h"

/**
 * digitCount - counts the number of digits
 * in a number
 *
 * @n: the nuber to be counted
 *
 * Return: returns the number of digits
 * in the number
 *
 */

int digitCount(long n)
{
	unsigned int count = 0;
	unsigned long temp;

	if (n < 0)
		temp = n * -1;
	else
		temp = n;
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	return (count);

}

/**
 * printInt - Function that print Integers
 * digitCount is first called to count the digits
 * then printNumber is called to print the number
 *
 * @list: list to check for Int Specifier
 * @f: flag passed to _printf
 * @c: pointer to struct convs
 *
 * Return: count
 */

int printInt(va_list list, flags *f, convs *c)
{
	long num;
	int count;

	if (f->s == 1)
		num = va_arg(list, int);
	else if (f->l == 1)
		num = (long)va_arg(list, long);
	else
		num = va_arg(list, int);
	count = digitCount(num);

	if (num <= 0)
		count++;
	if (f->space == 1 && f->plus == 0 && num >= 0)
		count++;
	if (f->plus == 1 && num >= 0)
		count++;
	count += printConvSpec(c->w - count);

	if (f->space == 1 && f->plus == 0 && num >= 0)
		_putchar(' ');
	if (f->plus == 1 && num >= 0)
		_putchar('+');

	printNumber(num);
	return (count);
}

/**
 * printNumber - prints an interger,
 * it helps printInt to print the interger
 *
 * @num: the numbers to be printed.
 *
 */

void printNumber(long num)
{
	long temp;

	if (num < 0)
	{

		temp = num * -1;
	}
	else
		temp = num;

	if (temp / 10)
		printNumber(temp / 10);
	_putchar((temp % 10) + '0');
}

/**
 * printUnsigned - prints an unsigned integer
 *
 * @list: va_list of arguments from _printf
 * @f: flag pass
 * @c: pointer to struct convs
 *
 * Return: number of char printed
 *
 */

int printUnsigned(va_list list, flags *f, convs *c)
{
	int i = 0, count = 0;
	char *str;
	unsigned long n;

	if (f->s == 1)
		n = (unsigned int)va_arg(list, unsigned int);
	else if (f->l == 1)
		n = (unsigned long)va_arg(list, unsigned long);
	else
		n = (unsigned int)va_arg(list, unsigned int);

	str = converter(n, 10, 'l');

	while (str[i])
		i++;
	count += printConvSpec(c->w - i);
	count += _putString(str);
	return (count);
}
