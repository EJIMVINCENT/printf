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

int digitCount(int n)
{
	unsigned int count = 0;
	unsigned int temp;

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
 *
 * Return: count
 */
int printInt(va_list list)
{
	int num = va_arg(list, int);
	int count = digitCount(num);

	if (num <= 0)
		count++;
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

void printNumber(int num)
{
	unsigned int temp;

	if (num < 0)
	{
		_putchar('-');
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
 *
 * Return: number of char printed
 *
 */

int printUnsigned(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);
	char *str = converter(n, 10, 0);

	return (_putString(str));
}
