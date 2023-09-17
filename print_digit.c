#include "main.h" 

int printInt(int i, ...)
{
	char buffer[20];	
	va_list arg_list;
	int num, count;

	count = 0;
	va_start(arg_list, i);
	num = va_arg(arg_list, int);

 	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	i = 0;
	do
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);
	
	while (i > 0 && i <= 20)
	{
		_putchar(buffer[--i]);
		count++;
	}
	va_end(arg_list);
	return (count);
}
