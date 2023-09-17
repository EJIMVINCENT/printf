#include "main.h"
#include 

int printDigit(int i, ...)
{
	va_list args;

	va_start(args, i);

	i = 0;  /*Initialize character count to 0*/

	int num = va_arg(args, int);

	if (num < 0)
	{
		i += _putchar('-');

		num = -num;
	}

	if (num == 0)
	{
		i += _putchar('0');
	}
	else
	{

		int temp = num;

		while (temp > 0)
		{
			temp /= 10;
			i++;
        	}
		while (num > 0)
		{
			char char_digit;

			int digit = num % 10;
			char_digit = (char)(digit + '0');

			i += _putchar(char_digit);
			num /= 10;
		}
	}
	va_end(args);
	return (i);
}
