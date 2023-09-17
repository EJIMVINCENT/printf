#include "main.h" 

int PrintInt(int i, ...)
{
	char buffer[];	
	va_list arg_list;
	int num, count;

	count = 0;
	va_start(i, arg_list);
	num = va_arg(arg_list, int);

 	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	do
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);
	
	while (i > 0 && i <= 12)
	{
		_putchar(buffer[--i]);
		count++
	}
	return (count);
}
