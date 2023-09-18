#include "main.h" 

int printInt(va_list list)
{

	char *buffer;
	int num, count;
	int i = 0;

	count = 0;
	num = va_arg(list, int);

 	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	while (num != 0)
		num /= 10, i++;

	buffer = malloc(sizeof(char) * (1 + i));
	if (buffer == NULL)
		return (-1);
		
	i = 0;
	do
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	while (i > 0)
	{
		_putchar(buffer[--i]);
		count++;
	}
	free(buffer);
	return (count);
}
