#include "main.h"




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
 * printInt - Function to print Integer
 *
 * @list: list to check for Int Specifier
 * Return: count
 */
int printInt(va_list list)
{
	int num = va_arg(list, int);	
	int count = digitCount(num);


	if (num < 0)
		count++;
	printNumber(num);
	return(count);
}



void printNumber(int num)
{
	unsigned int temp;

	if (num < 0)
	{
		_putchar('-');
		temp = num * - 1;
	}
	else
		temp = num;

	if (temp / 10 != 0)
		printNumber(temp / 10);
	_putchar((temp % 10) + '0');
}
